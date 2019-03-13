import pandas as pd

filepath = "contoh-data.csv"
sep = ","
delimiter = None

df = pd.read_csv(filepath, sep=sep, delimiter=delimiter)

print(df)

# show columns
print(df.columns)

# show data
print(df["IQ"])
