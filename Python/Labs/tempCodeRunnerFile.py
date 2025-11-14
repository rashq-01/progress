import numpy as np

# Create a Numpy Array
arr = np.array([10,20,30,40,50,60,70,80])

print("Original Array : ",arr)

# 1. Basic Slicing
print("\nBasic Slicling (arr[2:6]) : ",arr[2:6]) # items from index 2 to 5
print("\nBasic Slicing withe step (arr[1:7:2]) : ",arr[1:7:2]) # Element from 1 to 6 with step 2


# 2. Integer Indexing
indices = [0,2,5]
print("\nInteger Indexing (arr[[0,2,5]]) : ",arr[indices]) # Picks specific elements ie with index

# 3. Boolean Indexing
bool_mask = arr>40 # Condition
print("\nBoolean Mask (arr > 40) : ",bool_mask)
print("\nBoolean Indexing (arr[arr > 40])",arr[bool_mask])