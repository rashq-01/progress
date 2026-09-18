str = "123.45"
print(float(str), type(float(str)))

l = ['a','b','c']
print(tuple(l),type(tuple(l)))
print(list(tuple(l)),type(list(tuple(l))))

s = {'x','y'}
print(list(s),type(list(s)))



a = 100
b = a
print(id(a),id(b))

i = 100
f = 10.34
b = True
s = "Rajesh "
print(i+f,type(i+f))
print(i+b,type(i+b))

print(f+b,type(f+b))



str1 = "hello"
str2 = str1
print(str2)
str1 = "Rajesh"
print(str2)

l1 = [1,2,3,4]
l2 = [1,2,3,4]
print(id(l1),id(l2))