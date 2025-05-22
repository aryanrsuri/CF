import os
import glob
import pandas as pd
import seaborn as sns
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
from datetime import datetime

def get_time():
    return datetime.now().strftime("%Y-%m-%d_%H-%M-%S")


class CP(object):
    def __init__(self):
        self._type = pd.read_csv("./tags.csv")
        df =  pd.merge(pd.read_csv("./problems.csv"), self._type, how="left", on="problem_id")
        df["time_started"] = pd.to_datetime(df["time_started"])
        avg_time_per_difficulty = (
            df.groupby("difficulty")["time_spent"]
            .mean()
            .rename("avg_time_for_difficulty")
            .reset_index()
        )
        df = df.merge(avg_time_per_difficulty, on="difficulty", how="left")
        a = 0.25  # tuning parameter to control sensitivity
        time_ratio = df["time_spent"] / df["avg_time_for_difficulty"]
        df["simple_diff"] = df["difficulty"] * (1 + a * np.log(time_ratio.clip(lower=a))) + df["used_help"] * 2 * a * df["difficulty"]
        df["n_simple_diff"] = df["simple_diff"]/df["difficulty"]
        self._problems = df

    def stats(self, img=False):
        df = self._problems
        txt = glob.glob("./stats/*_report.txt")
        png = glob.glob("./stats/*_report.png")
        timestamp = get_time()
        output_path = f"./stats/{timestamp}_report.txt"
        for file in txt:
            os.remove(file)
        if (img):
            for file in png:
                os.remove(file)



        with open(output_path, "w") as f:
            f.write("=== Average Time Spent per Difficulty ===\n")
            f.write(df.groupby("difficulty")["time_spent"].mean().round(2).to_string())
            f.write("\n\n=== Scaled Difficulties ===\n")
            f.write(df[["problem_id", "time_spent", "focus_factor", "used_help", "difficulty", "n_simple_diff", "simple_diff"]].drop_duplicates().to_string(index=False))
            f.write("\n\n=== Nominal Problems+Types ===\n")
            df = df.drop(columns=["notes", "Takeaway"])
            f.write(df.to_string(index=False))

        print(f"[OK] Report generated at ./stats/{timestamp}_report.txt")
        if not img:
            return None
        fig = plt.figure(figsize=(24, 20))
        gs = gridspec.GridSpec(2, 3, figure=fig)
        ax0 = fig.add_subplot(gs[0, 0])
        sns.boxplot(x="difficulty", y="time_spent", data=df, ax=ax0)
        ax0.set_title("Time Spent vs Difficulty")
        ax2 = fig.add_subplot(gs[0, 1])
        sns.scatterplot(x="time_started", y="time_spent",  hue="difficulty", data=df, ax=ax2)
        ax2.set_title("Time Progression")
        df_sorted = df.sort_values("time_started")
        ax4 = fig.add_subplot(gs[0, 2])
        df_sorted["rolling_n_diff"] = df_sorted["n_simple_diff"].rolling(window=3, min_periods=1).mean()
        sns.lineplot(x="time_started", y="rolling_n_diff", data=df_sorted, ax=ax4)
        ax4.set_title("N-normed Difficulty by Time Spent")
        ax6 = fig.add_subplot(gs[1, 0])
        sns.boxplot(x="type", y="time_spent", data=df, ax=ax6)
        ax6.set_title("Time Spent by Type")
        ax6.tick_params(axis='x', rotation=45)
        pivot_table_7 = df.pivot_table(values="simple_diff", index="type", columns="difficulty", aggfunc="mean")
        ax7 =  fig.add_subplot(gs[1,1])
        sns.heatmap(pivot_table_7, annot=True, fmt=".1f", cmap="YlGnBu", ax=ax7)
        ax7.set_title("Simple Diff x Type × Difficulty")
        plt.tight_layout()
        plt.savefig(f"./stats/{timestamp}_report.png")

       
if __name__ == "__main__":
    c = CP()
    c.stats(img=True)
    # c.add_elo_columns()
    # c.summary()
    # c.plot_elo()






