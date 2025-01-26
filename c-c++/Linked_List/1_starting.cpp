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

        void push_front(int value){
            Node* newNode = new Node(value);
            if(head == NULL){
                head = tail = newNode;
                return;
            }
            else{
                newNode->next = head; 
                head = newNode;
            }
        }

        void pop_front(){
            if(head == NULL){
                cout<<"Linked List is empty";
                return;
            }
            Node* temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
        
        void push_back(int value){
            Node* newNode = new Node(value);
            if(head == NULL){
                head = tail = NULL;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }

        void pop_back(){
            if(head == NULL){
                cout<<"Linked List is empty";
                return;
            }
            Node* temp = head;
            if(temp->next != tail){
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;

        }

        void printList(){
            Node* temp = head;
            while(temp != NULL){
                cout<<"data = "<<temp->data<<"   Present Address = "<<temp<<"   next address = "<<temp->next<<endl;
                temp = temp->next;
            }
        }
};


int main(){
    List LL;
    LL.push_front(1);
    LL.push_front(2);
    LL.push_front(3);
    LL.push_front(4);
    LL.push_back(2);
    LL.push_back(9);
    LL.pop_front();
    LL.pop_back();
    LL.printList();

}