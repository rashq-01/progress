#include <stdio.h>
int main()
{
    FILE *file;
    char fileName[50];
    char ch;
    int lines = 0, words = 0, characters = 0, inWord = 0;
    // Get the file name from the user
    printf("Enter the name of the file: ");
    scanf("%s", fileName);
    // Open the file for reading
    if ((file = fopen(fileName, "r")) == NULL)
    {
        perror("Error opening file for reading");
        return 1;
    }
    // Count lines, words, and characters in the file
    while ((ch = fgetc(file)) != EOF)
    {
        characters++;
        if (ch == '\n')
        {
            lines++;
        }
        // Check for word boundaries
        if (ch == ' ' || ch == '\t' || ch == '\n')
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            inWord = 1;
            words++;
        }
    }
    printf("Number of lines: %d\n", lines);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);
    // Close the file
    fclose(file);
    return 0;
}