import numpy as np

arr1 = np.array([0,2,3,4])
arr2 = np.array([[2,3,4,5],[2,3,4,5]])
arr3 = np.array([[[2,3,4,5],[2,3,4,5]],[[2,3,4,5],[2,3,4,5]]])

print(arr1.ndim)
print(arr2.ndim)
print(arr3.ndim)

print(arr1.shape)
print(arr2.shape)
print(arr3.shape)

# chain indexing

print(arr3[0][1][2])


arr4 = np.array([[['A','B','C'],['D','E','F'],['G','H','I']],
                 [['J','K','L'],['M','N','O'],['P','Q','R']],
                 [['S','T','U'],['V','W','X'],['Y','Z','A']]])


word = arr4[0,0,0] + arr4[2,0,0] + arr4[1,0,0]

print(word)