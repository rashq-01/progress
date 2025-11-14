with open("data.txt","w") as f:
    f.write("Line 1: First line of the file.\n")
    f.write("Line 2: This is the second line.\n")
    f.write("Line 3: Penultimate line here.\n")
    f.write("Line 4: The final line.\n")

print("------Reverse File printer------")
print("Original content of 'data.txt.'")
with open("data.txt","r") as f:
    print(f.read())
print("-"*30)

try:
    with open("data.txt","r") as file:
        lines = file.readlines()
        reversed_lines = lines[::-1]

        print("File content in reverse order.")
        for line in reversed_lines:
            print(line.strip())

except FileNotFoundError:
    print("Error 'data.txt'")
print("-"*30)