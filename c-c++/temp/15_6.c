#include <stdio.h>
#include <stdlib.h>
void printLastNCharacters(FILE *file, int n)
{
    fseek(file, 0, SEEK_END);    // Move the file pointer to the end of the file
    long fileSize = ftell(file); // Get the total size of the file
    // Read and print the last 'n' characters
    for (long i = 1; i <= n && i <= fileSize; i++)
    {
        fseek(file, -i, SEEK_END);
        char ch = fgetc(file);
        putchar(ch);
    }
}
int main()
{
    FILE *file;
    char fileName[50];
    int n;
    // Get the file name from the user
    printf("Enter the name of the file: ");
    scanf("%s", fileName);
    // Open the file for reading
    if ((file = fopen(fileName, "r")) == NULL)
    {
        perror("Error opening file for reading");
        return 1;
    }
    // Get the value of 'n' from the user
    printf("Enter the value of 'n': ");
    scanf("%d", &n);
    printf("Last %d characters of the file:\n", n);
    printLastNCharacters(file, n);
    // Close the file
    fclose(file);
    return 0;
}