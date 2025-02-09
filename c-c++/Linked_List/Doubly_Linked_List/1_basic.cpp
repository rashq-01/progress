#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* prev;
        Node* next;

        Node(int value){
            val = value;
            prev = NULL;
            next = NULL;
        }
};

int main(){
    Node* head = new Node(5);

}