l = [5,7,10,20,25,30,90]
min = l[0]
max = l[0]

for i in range(len(l)):
    min = l[i] if min>l[i] else min
    max = l[i] if min<l[i] else max


print("Max : ",max)
print("Min",min)


rev = l

n =len(rev)-1

for i in range(n+1):
    temp = rev[i]
    rev[i] = rev[n-i]
    rev[n-i] = temp

print(rev)