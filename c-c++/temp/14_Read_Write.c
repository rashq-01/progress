#include <stdio.h>
int main()
{
    FILE *file;
    char fileName[] = "example.txt";
    char buffer[100];
    char textToWrite[100];
    // Get text from the user
    printf("Enter text to write to the file: ");
    fgets(textToWrite, sizeof(textToWrite), stdin);
    // Writing text to a file
    file = fopen(fileName, "w");
    fprintf(file, "%s", textToWrite);
    fclose(file);
    printf("Text written to the file.\n");
    // Reading text from the file
    file = fopen(fileName, "r");
    printf("Reading text from the file:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }
    fclose(file);
    return 0;
}