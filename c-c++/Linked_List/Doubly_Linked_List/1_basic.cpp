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

class list{
    public:
        Node* head;
        Node* tail;

        list(){
            head = NULL;
            tail = NULL;
        }

        void push_front(int value){
            Node* newNode = new Node(value);
            if(!head){
                head = tail = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
                newNode->next->prev = head;
            }
        }


        void printList(){
            Node* temp = head;
            int a = 1;
            cout<<endl<<endl;
            while(temp != NULL){
                cout<<a<<"  Data: "<<temp->val<<" prevAdd: "<<temp->prev<<"  presentAddress: "<<temp<<"  nextAddress: "<<temp->next<<endl;
                temp = temp->next;
                a++;
            }
        }
};

int main(){
    list l;
    l.push_front(5);
    l.push_front(6);
    l.push_front(8);
    l.push_front(3);
    l.printList();

}