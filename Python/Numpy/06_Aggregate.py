import numpy as np


arr1 = np.array([[1,2,3,4,5],
                 [6,7,8,9,10]])

print("Sum : ",np.sum(arr1))

print("Mean : ",np.mean(arr1))

print("StdDeviation : ",np.std(arr1))

print("Variation : ",np.var(arr1))

print("Max : ",np.max(arr1))

print("Min index : ",np.argmin(arr1))

print("Sum : ",np.sum(arr1, axis=0))

print("Sum : ",np.sum(arr1, axis=1))