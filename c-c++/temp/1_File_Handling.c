#include<stdio.h>
#include<string.h>
int main(){
    FILE *Fpointer;
    Fpointer = fopen("Example.txt","a");
    char data[50] = " Naresh Pandit";
    if(Fpointer == NULL){
        printf("Error in opening files....");
    }
    else{
        for(int i=0;i<strlen(data);i++){
            printf("Writing character: %c \n",data[i]);
            fputc(data[i],Fpointer);
        }
        printf("Data Entered Successfully....");
        fclose(Fpointer);
    }
    return 0 ;
}