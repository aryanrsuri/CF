import os
import glob
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
from datetime import datetime

INITIAL_RATING = 900
sns.set_palette("deep")

def get_time():
    return datetime.now().strftime("%Y-%m-%d_%H-%M-%S")


class CP(object):
    def __init__(self):
        self._problems = pd.read_csv("./problems.csv")
        self._type = pd.read_csv("./tags.csv")
        self._problems = pd.merge(self._problems, self._type, how="left", on="problem_id")
        df = self._problems
        df["time_started"] = pd.to_datetime(df["time_started"])
        df["focus_efficiency"] = (df["focus_factor"]) / df["time_spent"]
        df["normalized_difficulty_by_focus"] = (df["difficulty"] / df["focus_efficiency"]  ) / df["focus_factor"].mean()
        df["normalized_difficulty_by_time_spent"] = df["difficulty"] * (df["time_spent"] / df["time_spent"].mean())
        df["normalized_difficulty_by_help_used"] = df["difficulty"] * (df["used_help"] / df["used_help"].mean())
        self._problems = df

        types_grouped = self._type.groupby('problem_id')['type'].apply(list).reset_index()
        self.data = (self._problems
                     .merge(types_grouped, on='problem_id', how='left')
                     .sort_values('time_started')
                     .reset_index(drop=True))

    def compute_elo_series(self, initial_rating=INITIAL_RATING, K=32, invert_last=False):
        """
        Compute Elo rating history over solves.
        - initial_rating: starting Elo
        - K: K-factor
        - invert_last: if True, treat last solve as a loss (score=0)
        Returns a list of Elo ratings after each solve.
        """
        ratings = []
        current = initial_rating
        for idx, row in self.data.iterrows():
            opp = row['difficulty']
            score = 1
            if invert_last and idx == len(self.data) - 1:
                score = 0
            expected = 1 / (1 + 10 ** ((opp - current) / 400))
            current += K * (score - expected)
            ratings.append(current)
        return ratings

    def add_elo_columns(self, initial_rating=INITIAL_RATING, K=32):
        """
        Adds two new columns to self.data:
        - 'elo_actual': history with all solves as wins
        - 'elo_hypothetical': history with last solve flipped to a loss
        """
        self.data['elo_actual'] = self.compute_elo_series(initial_rating, K, invert_last=False)
        self.data['elo_hypothetical'] = self.compute_elo_series(initial_rating, K, invert_last=True)

    def plot_elo(self, log_x=False):
        """
        Plot Elo over solve count.
        - log_x: if True, use log scale on x-axis
        """
        if 'elo_actual' not in self.data:
            raise ValueError("Please run add_elo_columns() first.")

        x = range(1, len(self.data) + 1)
        plt.plot(x, self.data['elo_actual'], label='Actual Elo')
        if log_x:
            plt.xscale('log')
        plt.title('Elo Rating vs. Solve Count' + (' (Log Scale)' if log_x else ''))
        plt.xlabel('Solve Count' + (' (log)' if log_x else ''))
        plt.ylabel('Elo Rating')
        plt.grid(True)
        plt.legend()
        plt.tight_layout()
        t = get_time()
        png = glob.glob("./stats/*_elo.png")
        for file in png:
            os.remove(file)
        plt.savefig(f"./stats/{t}_elo.png")
        print(f"[OK] Elo progression plotted at ./stats/{t}_elo.png")

    def summary(self):
        """
        Print current and hypothetical Elo.
        """
        if 'elo_actual' not in self.data:
            self.add_elo_columns()
        actual = self.data['elo_actual'].iloc[-1]
        hypo = self.data['elo_hypothetical'].iloc[-1]
        self.actual = actual
        print(f"[OK] Current estimated Elo: {round(actual)}")
        print(f"[OK] Hypothetical Elo if last solve was missed: {round(hypo)}")


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
            f.write(df[["problem_id", "time_spent", "focus_factor", "used_help", "difficulty", "normalized_difficulty_by_focus", "normalized_difficulty_by_time_spent", "normalized_difficulty_by_help_used"]].drop_duplicates().to_string(index=False))
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


        print(f"[OK] Report generated at ./stats/{timestamp}_report.txt")


        if not img:
            return None

        fig = plt.figure(figsize=(24, 20))
        gs = gridspec.GridSpec(4, 3, figure=fig)

        # Boxplot: Time vs Difficulty
        ax0 = fig.add_subplot(gs[0, 0])
        sns.boxplot(x="difficulty", y="time_spent", data=df, ax=ax0)
        ax0.set_title("Time Spent vs Difficulty")

        # Scatter: Focus vs Time
        ax1 = fig.add_subplot(gs[0, 1])
        sns.scatterplot(x="focus_factor", y="time_spent", hue="difficulty", data=df, ax=ax1)
        ax1.set_title("Focus vs Time Spent")

        # Scatter: Time vs Time Started
        ax2 = fig.add_subplot(gs[0, 2])
        sns.scatterplot(x="time_started", y="time_spent",  hue="difficulty", data=df, ax=ax2)
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
        plt.savefig(f"./stats/{timestamp}_report.png")

       
if __name__ == "__main__":
    c = CP()
    c.stats(img=True)
    # c.add_elo_columns()
    # c.summary()
    # c.plot_elo()






