a=int(input("Enter a number : "))
if(a<0):
    print("Negative number")
elif(a==0):
    print("Zero Number")
else:
    print("Positive number")

if(a%2==0):
    print("Even Number")
else:
    print("Odd Number")

if(a%5==0):
    if(a%3==0):
        print("Divisable by 5 & 3")
