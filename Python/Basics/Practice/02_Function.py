

# def lenList(a):
#     return(len(a))

# def listLine(a):
#     for i in range(len(a)):
#         print(a[i],end=" ")

# cities = ["Birgunj","Kathmandu","Pokhara","Biratnager"]
# listLine(cities)

def fact(n):
    if(n==1 or n==0):
        return n
    else:
        return n * fact(n-1)

print(fact(5))

def conv(usd):
    return usd*100
print(conv(100))