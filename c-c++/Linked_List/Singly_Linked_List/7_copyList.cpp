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

        Node* getHead(){
            return head;
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

void printList(Node* head){
            Node* temp = head;
            int a = 1;
            while(temp != NULL){
                cout<<a<<"  Data: "<<temp->data<<"  presentAddress: "<<temp<<"  nextAddress: "<<temp->next<<endl;
                temp = temp->next;
                a++;
            }
        }

Node* copyList(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* nex = new Node(head->data);
    Node* Head = nex;
    Node* curr = nex;
    head = head->next;
    while(head != NULL){
        nex = new Node(head->data);
        curr->next = nex;
        curr = nex;
        head=head->next;

    }
    return Head;

}


int main(){
    List LL;

    for(int i=1;i<=5;i++){
        LL.push_back(i);
    }
    LL.printList();
    cout<<endl<<endl<<endl;
    Node* newHead = copyList(LL.getHead());
    printList(newHead);
}