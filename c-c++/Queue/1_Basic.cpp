#include<iostream>
using namespace std;

class Queue{
        int *arr;
        int capacity;
        int front;
        int rear;
    public:
        Queue(int size){
            arr = new int[size];
            capacity = size;
            front = 0;
            rear = 0;
        }

        void enqueue(int val){
            if(rear == capacity){
                cout<<"Queue Overflow"<<endl;
                return;
            }
            arr[rear++] = val;
        }

        void dequeue(){
            if(front == rear){
                cout<<"Queue Underflow"<<endl;
                return;
            }
            front++;
        }

        int front(){
            if(front == rear){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return arr[front];
        }

        int back(){
            if(front == rear){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return arr[rear];
        }

        int isEmpty(){
            return front == rear;
        }

        int size(){
            return rear-front;
        }
};