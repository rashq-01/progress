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
        
        //Push Front
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

        //Push Back
        void push_back(int value){
            Node* newNode = new Node(value);
            if(!head){
                head = tail = newNode;
            }
            else{
                Node* curr = head;
                while(curr != tail){
                    curr = curr->next;
                }
                newNode->prev = curr;
                curr->next = newNode;
                tail = newNode;
                
            }
        }

        //Pop Front
        void pop_front(){
            if(!head){
                return;
            }
            else if(head == tail){
                delete head;
                head = tail = NULL;
            }
            else{
                Node* temp = head;
                head = head->next;
                head->prev = NULL;
                temp->next = NULL;
                delete temp;
            }
        }

        //Pop Back
        void pop_back(){
            if(!head){
                return;
            }
            else if(head == tail){
                delete head;
                head = tail = NULL;
            }
            else{
                Node* curr = head;
                while(curr->next != tail){
                    curr = curr->next;
                }
                tail->prev = NULL;
                curr->next = NULL;
                delete tail;
                tail = curr;
            }
        }

        //Deletion by value
        void removeByValue(int v){
            if(!head){
                cout<<endl<<"Empty List"<<endl;
            }
            else{
                Node* prev = NULL;
                Node* curr = head;
                Node* nex = NULL;
                while(curr->val != v){
                    prev = curr;
                    curr = curr->next;
                    nex = curr->next;
                }
                curr->prev = NULL;
                curr->next = NULL;
                delete curr;
                prev->next = nex;
                nex->prev = prev;
            }
        }

        //PrintList
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
    l.push_back(10);
    l.push_back(11);
    l.push_back(12);
    l.push_back(123);
    l.removeByValue(10);
    l.printList();

}