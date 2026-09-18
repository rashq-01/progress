# Average of list

l = [1,2,3,4,5,5,3,32,2,3.4]
print(sum(l)/len(l))

#Duplicates

d = [1,9,2,3,4,5,5,3,6]
u = []
for i in d:
    if i not in u:
        u.append(i)
print(u)


# Matrix to flat
m = [[1,2],[3,4],[5,6]]
flat = [item for sublist in m for item in sublist]
print(flat)


# Even Number

ev = [x for x in range(1,20)if x%2==0]
print(ev)

#Index of negative number

x = [1,2,3,4,4,-2,32,23,-3,34,22]
