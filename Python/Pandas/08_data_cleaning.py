import pandas as pd

df = pd.read_csv("04_data.csv")

# 1. Drop irrelevant coulmns
# ldf = df.drop(columns=["Legendary","No"])
# print(ldf)


# 2. Handle missing data
# df = df.dropna(subset=["Type2"])
# df = df.fillna({"Type2": "None"})


# 3. Fix inconsistent values
# df["Type2"] = df["Type1"].replace({"Grass":"GRASS",
#                                    "Fire":"FIRE",
#                                    "Water":"WATER"})


# 4. Standarize text
# df["Name"] = df["Name"].str.capitalize()


# 5. Fix data types
# df["Legendary"] = df["Legendary"].astype(bool)

# 6. Removing duplicates

df = df.drop_duplicates()


print(df.to_string())