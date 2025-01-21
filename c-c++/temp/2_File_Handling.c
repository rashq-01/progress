#include<stdio.h>
#include<string.h>
int main(){
    char str[100] = "";
    FILE *ptr;
    ptr = fopen("2_File_Handling.txt","w");
    if(ptr == NULL){
        printf("Error in creating file.....");
        printf("\n");
    }
    else{
        printf("Enter string: ");
        gets(str);
        fputs(str,ptr);
        printf("Successfully data has been written...");
        fclose(ptr);
    }
    return 0;
}