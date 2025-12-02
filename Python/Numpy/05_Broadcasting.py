import numpy as np

arr1 = np.array([[1, 2, 3, 4]])
arr2 = np.array([[1], [2], [3], [4] ])


print(arr1.shape)
print(arr2.shape)

print(arr1 * arr2)

arr1 = np.array([[1, 2, 3, 4],
                 [5,6,7,8],
                 [9,10,11,12],
                 [13,14,15,16]])
arr2 = np.array([[1], [2], [3], [4] ])

print("\n\n")

print(arr1.shape)
print(arr2.shape)
print(arr1*arr2)