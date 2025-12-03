import pandas as pd


# a tabular data frame


data = {"Name":["Rajesh","Pradip","Bikash"],
        "Age":[30,35,50]}

df = pd.DataFrame(data,index=["Employee 1","Employee 2","Employee 3"])

# print(df)
# print(df.loc["Employee 1"])
# print(df.iloc[0])

# Add new column
df["Job"] = ["Cook","N/A","Cashier"]

# Add new row
# new_row = pd.DataFrame([{"Name": "Sandy","Age":28,"Job":"Engineer"}],index=["Employee 4"])
# df  = pd.concat([df,new_row])
# print(df)


# Add new rows
new_rows = pd.DataFrame([{"Name": "Sandy","Age":28,"Job":"Engineer"},
                         {"Name": "Sandeep","Age":34,"Job":"Designer"}],index=["Employee 4","Employee 5"])
df  = pd.concat([df,new_rows])
print(df)
