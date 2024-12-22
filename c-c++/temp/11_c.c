#include <stdio.h>
#include <string.h>
// Function to copy one string to another using pointers
void copyStrings(char *source, char *destination)
{
    while (*source)
    {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0'; // Terminate the destination string
}
int main()
{
    char source[100], destination[100];
    // Input the source string
    printf("Enter the source string:\n");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = '\0'; // Remove newline character if present
    // Copy the source string to destination
    copyStrings(source, destination);
    // Display the copied string
    printf("Copied string is: %s\n", destination);
    return 0;
}