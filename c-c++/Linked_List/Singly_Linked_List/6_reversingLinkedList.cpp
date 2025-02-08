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
            head = head->next;
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
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;

        }

        void insert(int val, int pos){
            if(pos <0){
                cout<<"Invalid Position"<<endl;
                return;
            }
            else if(pos == 0){
                push_front(val);
                return;
            }
            else{
                Node* temp = head;
                for(int i=0;i<(pos-2);i++){
                    if(temp == NULL){
                        cout<<"Invalid Position"<<endl;
                        return;
                    }
                    temp = temp->next;
                }
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
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
        void serach(int v){
            Node* temp = head;
            int a = 0;
            while(temp != NULL){
                ++a;
                int data = temp->data;
                if(data == v){
                    cout<<endl<<endl<<"---------------DATA FOUND---------------"<<endl<<endl;
                    cout<<"position: "<<a<<"  Data: "<<temp->data<<"  presentAddress: "<<temp<<"  nextAddress: "<<temp->next<<endl;
                    return;
                }
                temp = temp->next;
            }
            if(temp == NULL){
                cout<<endl<<endl<<"Your data not found"<<endl<<endl;
            }
        }
};

Node reversing(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* nex = NULL;

    while(curr != NULL){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;

    }

}

int main(){
    List LL;
    LL.push_back(9);
    LL.push_back(5);
    LL.push_front(9);
    LL.push_back(4);
    LL.push_front(9);
    LL.push_back(8);
    LL.push_front(3);
    LL.insert(112,3);
    LL.printList();
    LL.serach(9);

}