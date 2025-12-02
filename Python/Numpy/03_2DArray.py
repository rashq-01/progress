import numpy as np


arr = np.array([[1,2,3,4],
                [5,6,7,8],
                [9,10,11,12],
                [13,14,15,16]])



# array slicing   arr[start : end : step]


print(arr[0 : 3 : 2])
print("\n\n")
print(arr[:,2])


print("\n\n")
print(arr[:,1:4])

print("\n\n")
print(arr[:,::2])

print("\n\n")
print(arr[1:3,1:3])