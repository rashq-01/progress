vote = []
unique_pattern = set()
for i in range(5):
    b = int(input("Enter vote (1-15) : "))
    vote.append(b)
    unique_pattern.add(b)
feature = [0,0,0,0]
for i in range(len(vote)):
    tem = vote[i]
    t = 0
    while(tem):
        dig = tem & 1
        if(dig==1):
            feature[t]= feature[t] + 1
        tem = tem >> 1
        t +=1

for i in range(4):
    if(feature[i]>3):
        print("Feature ",i+1," : ",feature[i],"---Popular")
    else:
        print("Feature ",i+1," : ",feature[i])

print("Unique voting pattern ",unique_pattern)