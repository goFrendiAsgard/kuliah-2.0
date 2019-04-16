import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.read_csv("./kernel.csv")
print(df)

sns.lmplot(x="x", y="y", data=df, hue="category", fit_reg=False)
plt.show()

# z = x^2 + y^2
df["z"] = df["x"] ** 2 + df["y"] ** 2

sns.lmplot(x="x", y="z", data=df, hue="category", fit_reg=False)
plt.show()
print(df)

