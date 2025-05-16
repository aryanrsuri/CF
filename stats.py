import sqlite3
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import numpy as np
from datetime import datetime


class CP(object):
    def __init__(self, path: str = "./comprog.sqlite3"):
        self._conn = sqlite3.connect(path)

    def _load(self):
        # Load both tables
        self._problems = pd.read_sql("SELECT * FROM problems", self._conn)
        self._type = pd.read_sql("SELECT * FROM type", self._conn)

        self._problems = pd.merge(self._problems, self._type, how="left", on="problem_id")
        # Fixme: Rename back to 
        df = self._problems
        df["time_started"] = pd.to_datetime(df["time_started"])
        df["focus_efficiency"] = (df["focus_factor"]) / df["time_spent"]

        df["focus_efficiency"] = df["focus_factor"] / (df["time_spent"] + 1e-6)
        df["normalized_difficulty_by_focus"] = (df["difficulty"] / df["focus_efficiency"]  ) / 5
        df["normalized_difficulty_by_time_spent"] = df["difficulty"] * (df["time_spent"] / df["time_spent"].mean())
        df["normalized_difficulty_by_help_used"] = df["difficulty"] * (df["used_help"] / df["used_help"].mean())

        # df["perceived_difficulty"] = (
        #     df["difficulty"] * df["time_spent"] / (df["focus_factor"] + 0.1)
        # ) * (1 + 0.5 * df["used_help"])
        # df["normalized_difficulty_by_time"] = df["difficulty"] * (
        #     df["time_spent"] / df["time_spent"].mean()
        # )
        # df["difficulty_time_log_scaled"] = df["difficulty"] * np.log1p(df["time_spent"])
        # df["difficulty_with_help_penalty"] = df["difficulty"] * (1 + 0.5 * df["used_help"])
        # df["difficulty_per_unit_focus"] = df["difficulty"] / (df["focus_factor"] + 0.1)
        self._problems = df
        return self._problems

    def _stats(self, ):
        df = self._problems
        timestamp = datetime.now().strftime("%Y-%m-%d_%H-%M-%S")
        output_path = f"./stats/{timestamp}_report.txt"

        with open(output_path, "w") as f:
            f.write("=== Average Time Spent per Difficulty ===\n")
            f.write(df.groupby("difficulty")["time_spent"].mean().round(2).to_string())
            f.write("\n\n=== Scaled Difficulties ===\n")
            f.write(df[["problem_id", "time_spent", "focus_factor", "difficulty", "normalized_difficulty_by_focus", "normalized_difficulty_by_time_spent", "normalized_difficulty_by_help_used"]].drop_duplicates().to_string())
            f.write("\n\n=== Avg Time Spent by Help Usage ===\n")
            f.write(df.groupby("used_help")["time_spent"].mean().round(2).to_string())
            f.write("\n\n=== Avg Time Spent per Type ===\n")
            f.write(df.groupby("type")["time_spent"].mean().round(2).to_string())
            f.write("\n\n=== Avg Focus Efficiency per Type ===\n")
            f.write(df.groupby("type")["focus_efficiency"].mean().round(3).to_string())
            f.write("\n\n=== Avg Scaled Difficulty per Type ===\n")
            f.write(df.groupby("type")["normalized_difficulty_by_focus"].mean().round(2).to_string())
            f.write("\n\n=== Avg Normed Difficulty per Type ===\n")
            f.write(df.groupby("type")["normalized_difficulty_by_time_spent"].mean().round(2).to_string())
            f.write("\n\n=== Avg Normed Difficulty per Help ===\n")
            f.write(df.groupby("type")["normalized_difficulty_by_help_used"].mean().round(2).to_string())
            f.write("\n\n=== Nominal Problems+Types ===\n")
            df = df.drop(columns=["notes"])
            f.write(df.to_string(index=False))


        with open(output_path, "r") as f:
            for line in f.readlines():
                print(line, end="")

        if (False):
        # Plot grid setup
        fig = plt.figure(figsize=(24, 20))
        gs = gridspec.GridSpec(4, 3, figure=fig)

        # Boxplot: Time vs Difficulty
        ax0 = fig.add_subplot(gs[0, 0])
        sns.boxplot(x="difficulty", y="time_spent", data=df, ax=ax0)
        ax0.set_title("Time Spent vs Difficulty")

        # Scatter: Focus vs Time
        ax1 = fig.add_subplot(gs[0, 1])
        sns.scatterplot(x="focus_factor", y="time_spent", size="difficulty", hue="difficulty", data=df, ax=ax1)
        ax1.set_title("Focus vs Time Spent")

        # Scatter: Time vs Time Started
        ax2 = fig.add_subplot(gs[0, 2])
        sns.scatterplot(x="time_started", y="time_spent", size="difficulty", hue="difficulty", data=df, ax=ax2)
        ax2.set_title("Time Progression")

        # Rolling Time Spent
        df_sorted = df.sort_values("time_started")
        df_sorted["rolling_avg_time"] = df_sorted["time_spent"].rolling(window=3, min_periods=1).mean()
        ax3 = fig.add_subplot(gs[1, 0])
        sns.lineplot(x="time_started", y="rolling_avg_time", data=df_sorted, ax=ax3)
        ax3.set_title("Rolling Avg Time Spent")

        # Avg Time per Difficulty Barplot
        ax4 = fig.add_subplot(gs[1, 1])
        sns.barplot(x="difficulty", y="time_spent", data=df.groupby("difficulty")["time_spent"].mean().reset_index(), ax=ax4)
        ax4.set_title("Avg Time per Difficulty")

        # Help vs Time Boxplot
        ax5 = fig.add_subplot(gs[1, 2])
        sns.boxplot(x="used_help", y="time_spent", data=df, ax=ax5)
        ax5.set_title("Help Usage vs Time Spent")

        # Type vs Time Boxplot
        ax6 = fig.add_subplot(gs[2, 0])
        sns.boxplot(x="type", y="time_spent", data=df, ax=ax6)
        ax6.set_title("Time Spent by Type")
        ax6.tick_params(axis='x', rotation=45)

        # Type vs Normalized Difficulty
        ax7 = fig.add_subplot(gs[2, 1])
        sns.boxplot(x="type", y="normalized_difficulty_by_time_spent", data=df, ax=ax7)
        ax7.set_title("Perceived Difficulty by Type")
        ax7.tick_params(axis='x', rotation=45)


        # Type Heatmap
        ax8 = fig.add_subplot(gs[2, 2])
        pivot_table = df.pivot_table(values="time_spent", index="type", columns="difficulty", aggfunc="mean")
        sns.heatmap(pivot_table, annot=True, fmt=".1f", cmap="YlGnBu", ax=ax8)
        ax8.set_title("Time Spent Heatmap (Type × Difficulty)")

        # Focus Efficiency by Type
        ax9 = fig.add_subplot(gs[3, 0])
        sns.boxplot(x="type", y="focus_efficiency", data=df, ax=ax9)
        ax9.set_title("Focus Efficiency by Type")
        ax9.tick_params(axis='x', rotation=45)

        # Scaled Difficulty Rolling Plot
        df_sorted["rolling_percieved_diff"] = df_sorted["normalized_difficulty_by_time_spent"].rolling(window=3, min_periods=1).mean()
        ax10 = fig.add_subplot(gs[3, 1])
        sns.lineplot(x="time_started", y="rolling_percieved_diff", data=df_sorted, ax=ax10)
        ax10.set_title("Rolling Perceived Difficulty By Time")

        df_sorted["rolling_by_focus_diff"] = df_sorted["normalized_difficulty_by_focus"].rolling(window=3, min_periods=1).mean()
        ax11 = fig.add_subplot(gs[3, 2])
        sns.lineplot(x="time_started", y="rolling_by_focus_diff", data=df_sorted, ax=ax11)
        ax11.set_title("Rolling Perceived Difficulty By Focus")

        plt.tight_layout()
        plt.savefig(f"./stats/{timestamp}_report.png", dpi=800)

       
if __name__ == "__main__":
    c = CP()
    p = c._load()
    c._stats()

