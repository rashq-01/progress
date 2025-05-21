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
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }

        void reversing(){
            Node* prev = NULL;
            Node* curr = head;
            Node* nex = NULL;
            while(curr){
                nex = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nex;
            }

            tail = head;
            head = prev;
        }
};


int main(){
    List LL;
    int arr[5] = {1,2,3,4,5};
    for(int i=0;i<5;i++){
        LL.push_back(arr[i]);
    }
    cout<<endl<<"Before Reversing: ";
    LL.printList();
    cout<<endl<<"After Reversing: ";
    LL.reversing();
    LL.printList();


}






// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]