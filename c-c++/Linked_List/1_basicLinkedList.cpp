#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int value){
            data = value;
            next = NULL;
        }
};

class List{
        Node* head;
        Node* tail;
    public:
        List(){
            head = tail = NULL;
        }
};


int main(){
    List LL;
}