#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = nullptr;
        }
};

class Queue{
    public:
        Node* front;
        Node* rear;

        Queue(){
            front = rear = nullptr;
        }

        void enqueue(int val){
            Node* newNode = new Node(val);
            if(!front){
                front = rear = newNode;
                return;
            }
            newNode->next = front;
            front = newNode;
        }

        void pop(){
            if(!rear){
                cout<<endl<<"Queue is empty!";
                return;
            }
            Node *temp = rear;
            rear = rear->next;
            if(!rear) front=nullptr;
            delete temp;
        }

};