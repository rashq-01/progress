m1 = [[1,2], [3,4]]
m2 = [[5,6] , [7,8]]
result = [[0,0] , [0,0]]

print("------Matrix Operation------")
print("Matrix 1 : ",m1)
print("Matrix 2 : ",m2)
print("-"*25)

print("------Addition------")
for i in range(len(m1)):
    for j in range(len(m1[0])):
        result[i][j] = m1[i][j]+m2[i][j]
for row in result:
    print(row)

print("------Matrix Transpose------")
result = [[0,0],[0,0]]
for i in range(len(m1)):
    for j in range(len(m1[0])):
        result[i][j] = m1[j][i]

for row in result:
    print(row)

print("------Matrix Multiplication------")

for i in range(len(m1)):
    for j in range(len(m1[0])):
        for k in range(len(m2)):
            result[i][j]+=m1[i][k]*m2[k][j]
for row in result:
    print(row)