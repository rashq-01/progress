#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->next = NULL;
    newNode->data = val;
    return newNode;
}

struct Node* tail = NULL;

int isEmpty(){
    return tail==NULL;
}

void push_front(){
    int val;
    printf("\nEnter push_front Value: ");
    scanf("%d",&val);
    struct Node* newNode = createNode(val);
    if(isEmpty()){
        tail = newNode;
        newNode->next = tail;
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;

}
void push_back(){
    int val;
    printf("\nEnter push_back Value: ");
    scanf("%d",&val);
    struct Node* newNode = createNode(val);
    if(isEmpty()){
        tail = newNode;
        newNode->next = tail;
        return;
    }
    push_front();
    tail = tail->next;
}
