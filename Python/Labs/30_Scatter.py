import pandas as pd
import matplotlib.pyplot as plt

# Creating dictionary and dataFrames
data = {

"Name": ["Alice", "Bob", "Charlie", "David", "Eva", "Frank",
"Grace", "Hannah", "Ian", "Julia"],
"Age": [20, 21, 22, 20, 23, 21, 24, 22, 23, 25],
"Marks": [85, 90, 78, 88, 76, 95, 89, 92, 80, 87],
"City": ["Delhi", "Mumbai", "Kolkata", "Chennai", "Delhi", "Pune","Mumbai", "Delhi", "Chennai", "Kolkata"],
"College": ["IIT", "NIT", "IIT", "BITS", "DU", "IIT", "NIT", "DU","BITS", "NIT"]
}

df = pd.DataFrame(data)

# Selecting two columns
x = df["Age"]
y = df["Marks"]

# Scattering Plot
plt.scatter(x,y,color="blue",marker="o")
plt.title("Scatter Plot of Marks vs Age")
plt.xlabel("Age")
plt.ylabel("Marks")
plt.grid(True)
plt.show()

# Line ploting
plt.plot(x,y,color="green",marker="s",linestyle="--")
plt.title("Line plot of Marks vs Age")
plt.xlabel("Age")
plt.ylabel("Marks")
plt.grid(True)
plt.show()