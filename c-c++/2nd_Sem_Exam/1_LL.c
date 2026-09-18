#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void push_back(){
    int val;
    printf("\nEnter value: ");
    scanf("%d",&val);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = val;
    newNode->next = NULL;
    if(!head){
        head = newNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void push_front(){
    int val;
    printf("\nEnter value: ");
    scanf("%d",&val);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = val;
    newNode->next = NULL;
    if(!head){
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void pop_back(){
    if(!head){
        printf("\nLinked List is empty...");
        return;
    }
    struct Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void display(){
    struct Node* temp = head;
    if(!temp){
        printf("\nList is empty...");
        return;
    }
    while(temp){
        printf("%d-->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void erase(){
    struct Node* temp = head;
    printf("\nErasing Space....");
    while(head){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    display();
    push_back();
    push_back();
    push_back();
    push_back();
    push_front();
    push_front();
    pop_back();
    display();

    erase();
    return 0;
}