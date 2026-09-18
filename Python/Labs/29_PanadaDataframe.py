import pandas as pd

data = {
    "Name":["Alice","Bob","Charlie","David","Eva","Frank","Grace","Hannah","Iran","Julia"],
    "Age":[20,21,22,20,23,21,24,22,23,25],
    "Marks":[85,90,78,88,76,95,89,92,80,87,],
    "City":["Delhi","Mumbai","Kolkata","Chennai","Delhi","Pune","Mumbai","Delhi","Chennai","Kolkata"],
    "College":["IIT","NIT","IIT","BITS","DU","IIT","NIT","Du","BITS","NIT"]
}

# Converting dictionary to Pandas DataFrame
df = pd.DataFrame(data)

#Displaying DataFrame
print("\nDataFrame : \n",df)

# Apply head() function
print("\nFirst 5 Rows using head(): \n",df.head())

#Performing data Selection
print("\nSingle Column (Name) : \n",df["Name"])
print("\nMultiple Column (Name, Age) : \n",df[["Name","Age"]])
print("\nUsing loc (Rows 0-2, Column Name & City) : \n",df.loc[0:2],[["Name","City"]])
print("\nUsing iloc (Rows 2-5, First 3 columns) : \n",df.iloc[2:6,0:3])