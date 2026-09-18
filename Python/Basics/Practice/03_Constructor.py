# class Student:
#     total_obj = 0
#     def __init__(self,Name,ID,Address):
#         self.name = Name
#         self.id = ID
#         self.address = Address
#         Student.total_obj+=1
#         print("adding students in data base")

    
#     def printDetail(self):
#         print("Name : ",self.name,end=" ")
#         print("ID : ",self.id,end=" ")



# s1 = Student("Rajesh",63453,"Bishrampur")
# s1 = Student("Majesh",63453,"Bishrampur")
# s1 = Student("Naresh",63453,"Bishrampur")

# s1.printDetail()
# print("\n")
# print(Student.total_obj)


# class student:
#     name = "None"
#     marks = [0,0,0]

#     @staticmethod
#     def hello():
#         print("Hello")

#     def __init__(self,Name,Subs):
#         self.name = Name
#         self.marks = Subs
#         print("Successfully Added")


#     def average(self):
#         total = 0
#         for i in range(len(self.marks)):
#             total+=self.marks[i]
#         print("Name : ",self.name,"Average : ",total/3)

# s1 = student("Rajesh",[20,30,40])
# s2 = student("Naresh",[60,70,80])
# s2.average()
# student.hello()




class Complex:
    def __init__(self,b,a):
        self.img = a
        self.real = b
        

    def show(self):
        print(self.real,"i + ",self.img,"j")


    def __add__(self,c1):
        img = self.img + c1.img
        real = self.real + c1.real
        return Complex(real,img)


c1 = Complex(5,6)
c2 = Complex(3,5)
c3 = c1+c2
c3.show()