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

        void push_back(int value){
            Node* newNode = new Node(value);
            if(head == NULL){
                head = tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }
        void printList(){
            Node* temp = head;
            int a = 1;
            while(temp != NULL){
                cout<<a<<"  Data: "<<temp->data<<"  presentAddress: "<<temp<<"  nextAddress: "<<temp->next<<endl;
                temp = temp->next;
                a++;
            }
        }
};


int main(){
    List LL;
}