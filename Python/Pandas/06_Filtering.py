import pandas as pd

df = pd.read_csv("04_data.csv")

tall_pokemon = df[df["Height"] >= 2]
heavy_pokemon = df[(df["Weight"] >= 100) & (df["Height"] >= 2)]
legendary_pokemon = df[df["Legendary"]==1]

water_pokemon = df[(df["Type1"] == "Water") | (df["Type2"] == "Water")]

ff_pokemon = df[(df["Type1"] == "Fire") &
                (df["Type2"] == "Flying")]
print(heavy_pokemon)