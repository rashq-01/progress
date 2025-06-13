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
void printBuckets(){
    printf("\n");
    for(int i=0;i<5;i++){
        struct Node* temp = hashTable[i];
        printf("Bucket[%d]-->",i+1);
        while(temp){
            printf("%d--",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void delete(){
    int key;
    printf("\nEnter value to delete: ");
    scanf("%d",&key);
    struct Node* prev = NULL;
    struct Node* index = hashTable[hashFunction(key)];
    struct Node* next = NULL;
    while(index){
        next = index->next;
        if(index->data==key){
            if(prev==NULL){
                prev = index;
                index = index->next;
                hashTable[hashFunction(key)] = index;
                prev->next = NULL;
                free(prev);
                printf("\nValue %d deleted successfully",key);
                return;
            }
            prev->next = index->next;
            index->next = NULL;
            free(index);
            printf("\nValue %d deleted successfully",key);
            return;
        }
        prev = index;
        index = index->next;
    }
    printf("\nValue %d is not present in table....",key);

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
    printBuckets();
    delete();
    printBuckets();


    return 0;
}


/*







*/