# Printing Number
a = int(input("Enter a number : "))
i=1
while(i<=a):
    print(i)
    i+=1

#Multiplication
b=int(input("Enter table number : "))
print("\nTable of ",b," :")
for i in range(1,11,1):
    print(b*i)

#All even and Odd 
print("All Even number between 1-100")
for i in range(1,101,1):
    if(i%2 != 0):
        continue
    print(i)


#Pattern print
for i in range(5):
    print("* "*i)

#Break
while True:
    a = input("Enter exit to exit : ")
    if(a=="exit"):
        break


#Dictionary
d = {"name":"Rajesh","age":21,"address":"Nepal"}

for key in d:
    print(key,d[key])


#for-else
for i in range(5):
    if i==3:
        break
    print(i)
else:
    print("Break statem is occured")

for i in range(5):
    print(i)
else:
    print("Break statement is not occured")
