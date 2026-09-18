#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 5

struct Node{
    int data;
    struct Node* next;
};

struct Node* hashTable[TABLE_SIZE] = {NULL};

int hashFunction(int val){
    return val % TABLE_SIZE;
}

void insert(){
    int key;
    printf("\nEnter value: ");
    scanf("%d",&key);
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void search(){
    int key;
    printf("\nEnter value to search: ");
    scanf("%d",&key);
    struct Node* temp = hashTable[hashFunction(key)];
    while(temp){
        if(temp->data == key){
            printf("Value %d is present in the table....",key);
            return;
        }
        temp = temp->next;
    }
    printf("\nValue %d is not present in the table....",key);
}

void printTable(){
    printf("\n");
    for(int i=0;i<5;i++){
        struct Node* temp = hashTable[i];
        while(temp){
            printf("%d--",temp->data);
            temp = temp->next;
        }
    }
    printf("NULL");
}

int main(){
    insert();
    insert();
    insert();
    insert();
    insert();
    search();
    search();
    search();
    printTable();

    return 0;
}


/*







*/