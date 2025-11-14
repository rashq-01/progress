with open("source.txt","w") as f:
    f.write("This is a Sample File for testing the Python program\n")
    f.write("It contains Words in both Upper and lower case")

print("------File Word Sorter------")
try:
    with open("source.txt","r") as source_file:
        content = source_file.read()
        words = content.split()

    lower_case_words = [word.lower() for word in words]
    lower_case_words.sort()

    with open("destination.txt","w") as dest_file:
        for word in lower_case_words:
            dest_file.write(word+"\n")
    print("Successfully sorter wrods from 'source.text' and wrote to 'destination.txt'")
except:
    print("Error 'source.txt' not found. Please ensure the file exists")
print("-"*25)