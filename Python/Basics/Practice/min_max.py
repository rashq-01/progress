l = [5,7,10,20,25,30,90]

first = l[0]
second = l[0]
\
for i in range(len(l)):
    if l[i]>first:
        second = first
        first = l[i]
    elif l[i]>second:
        second = l[i]

print("The second largest number : ",second)