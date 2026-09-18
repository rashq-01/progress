import numpy as np

arr1 = np.array([[21,17,19,20,16,30,18,65],
                [39,22,15,99,18,19,20,21]])

teen = arr1[arr1 < 18]
adult = arr1[(arr1 >= 18) & (arr1<65)] 

even = arr1[arr1%2==0]
print(even)



adults = np.where(arr1>=18,arr1,0)
print(adults)