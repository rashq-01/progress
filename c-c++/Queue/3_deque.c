#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct node* prev;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int isEmpty(){
    return front==NULL;
}

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void push_front(){
    int val;
    printf("\nEnter value: ");
    scanf("%d",&val);
    struct Node* newNode = createNode(val);
    if(isEmpty()){
        front = newNode;
        rear = newNode;
        return;
    }
    newNode->next = front;
    front->prev = newNode;
    front = newNode;
    printf("\n%d inserted at front.",val);
}

void push_back(){
    int val;
    printf("\nEnter value: ");
    scanf("%d",&val);
    struct Node* newNode = createNode(val);
    if(isEmpty()){
        front = newNode;
        rear = newNode;
        return;
    }
    newNode->prev = rear;
    rear->next = newNode;
    rear = newNode;
    printf("\n%d inserted at back",val);

}

void pop_front(){
    if(isEmpty()){
        printf("\nDeque is empty.");
        return;
    }
    struct Node* temp = front;
    front = front->next;
    if(!front){
        rear = NULL;
    }
    else{
        front->prev = NULL;
    }
    printf("\n%d removed.",temp->data);
    temp->next = temp->prev = NULL;
    free(temp);

}

void pop_back(){
    if(isEmpty()){
        printf("\nDeque is empty.");
        return;
    }
    struct Node* temp = rear;
    rear = rear->prev;
    if(!rear){
        front = NULL;
    }
    else{
        rear->next = NULL;
    }
    printf("\n%d removed.",temp->data);
    temp->next = temp->prev = NULL;
    free(temp);
}
int get_front(){
    if(isEmpty()){
        return -1;
    }
    return front->data;
}