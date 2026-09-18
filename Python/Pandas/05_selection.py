import pandas as pd


df = pd.read_csv("04_data.csv",index_col="Name")

# Selection by column

# print(df["Name"].to_string())
# print(df["Height"].to_string())
# print(df[["Name","Height","Weight"]].to_string())


# Selection by rows
# print(df.loc["Charizard":"Blastoise",["Height","Weight"]])

# print(df.iloc[0:11:2,0:3])

pokemon = input("Enter a pokemon Name ; ")

try:
    print(df.loc[pokemon])
except KeyError:
    print(f"${pokemon} not found")