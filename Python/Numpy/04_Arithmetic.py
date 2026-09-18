import numpy as np


arr = np.array([1,2,3])

# Scalar Arithmetic

print(arr + 1)
print(arr - 1)
print(arr * 2)
print(arr / 2)
print(arr ** 2)



# Vectorized math function

print("\n\n\nVectorized math")

print(np.floor(np.sqrt(arr)))


raddi = np.array([1,2,3])

print(np.round(np.pi * raddi**2))


arr1 = np.array([1,2,3])
arr2 = np.array([4,5,6])

print("Element wise add: ",arr1+arr2)
print("Element wise sub: ",arr1 - arr2)




scores = np.array([91, 55, 100, 73, 82, 64])

print(scores==100)


scores[scores < 60] = 0
print(scores)