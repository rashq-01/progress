import math

class Shape:
    def area(self):
        pass
    def perimeter(self):
        pass

class Circle(Shape):
    def __init__(self,radius):
        self.radius = radius
    
    def area(self):
        return math.pi *(self.radius**2)
    
    def perimeter(self):
        return math.pi * 2 * self.radius
    

class Square(Shape):
    def __init__(self,l):
        self.length = l
    
    def area(self):
        return self.length**2
    
    def perimeter(self):
        return 4*self.length
    
class Triangle(Shape):
    def __init__(self,b,h):
        self.base = b
        self.height = h
    
    def area(self):
        return (self.base * self.height)/2
    def perimeter(self):
        return math.sqrt((self.base **2) + (self.height**2))+self.base + self.height

print("--- Object-Oriented Shapes ---")
my_circle = Circle(radius=7)
print(f"Circle (radius=7):")
print(f" Area: {my_circle.area():.2f}")
print(f" Perimeter: {my_circle.perimeter():.2f}\n")

my_square = Square(l=5)
print(f"Square (side=5):")
print(f" Area: {my_square.area()}")
print(f" Perimeter: {my_square.perimeter()}\n")

my_triangle = Triangle(b=10,h=5) # Equilateral triangle​
print(f"Triangle (base=10 , height=5):")
print(f" Area: {my_triangle.area():.2f}")
print(f" Perimeter: {my_triangle.perimeter():.2f}\n")