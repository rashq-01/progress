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



        //Using Length Calculation

        void middleLength(){
            Node* temp = head;
            if(temp == NULL){
                cout<<"Empty LinkedList...";
                return;
            }
            else{
                int n = 0;
                while(temp){
                n++;
                temp = temp->next;
                }
                int mid = n/2;
                temp = head;
                while(mid--){
                    temp=temp->next;
                }
                cout<<endl<<endl<<"Using middleLength Function----> ";
                cout<<"Data: "<<temp->data;
            }       
        }

        void middleFS(){
            if(!head){
                cout<<"Empty Linked List...";
                return;
            }
            else{
                Node* slow = head;
                Node* fast = head;
                while(fast && fast->next){
                    slow = slow->next;
                    fast = fast->next->next;
                }
                cout<<endl<<endl<<"Using middleFS Function----> ";
                cout<<"Data: "<<slow->data;
            }
        }


};

int main(){
    List LL;
    for(int i=1;i<=12;i++){
        LL.push_back(i);
    }
    LL.printList();
    LL.middleFS();
    LL.middleLength();

}