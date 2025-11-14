with open("report.txt","w") as f:
    f.write("Python is a versatile programming language.\n")
    f.write("It is a widely used for web development, data science and more.\n")

print("------File Statistics Counter------")
try:
    line_count = 0
    word_count = 0
    char_count = 0

    with open("report.txt","r") as f:
        for line in f:
            line_count+=1
            char_count+=len(line)
            words = line.split()
            word_count = len(words)
    print("Analysis of 'report.txt'.")
    print("Nuber of lines : ",line_count)
    print("Number of words : ",word_count)
    print("Number of char : ",char_count)

except FileNotFoundError:
    print("Error 'report.txt' could not be found")
print("-"*30)