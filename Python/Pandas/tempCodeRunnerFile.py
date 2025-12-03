import pandas as pd

# A pandas 1D labeled array that can hold any data type


# data = [100.2,102,104]
# series = pd.Series(data)
# print(series)


# data = [True,False,True]
# series = pd.Series(data)
# print(series)

# print("\n\n")
# data = [100,102,104]
# series = pd.Series(data,index=["a","b","c"])
# print(series)

# series.iloc[0] = 300
# series.loc["c"] = 200
# print(series.loc["c"])
# print(series)


data = [100,102,104,200,202]

series = pd.Series(data,index=["a","b","c","d","e"])

print(series)
print("\n\n")
print(series[series >= 200])


cal = {"Day 1": 1750, "Day 2": 2100, "Day 3": 1700}

ser = pd.Series(cal)