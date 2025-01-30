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

//Push_Front
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

//Pop_Front
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
        
//Push_Back

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

//Pop_Back

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

//Insertion

        void insert(int val, int position){
            if(position <0){
                cout<<"Invalid Position"<<endl;
                return;
            }
            else if(position == 0){
                push_front(val);
                return;
            }
            else{
                Node* temp = head;
                for(int i=0;i<(position-2);i++){
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

//Deletion_By_Position

        void deletion_byPosition(int index){
            if(index<0){
                cout<<"Invalid index"<<endl;
                return;
            }
            else{
                Node* prev = NULL;
                Node* curr = head;
                Node* nex = NULL;
                int i = 0;
                while(i != (index-1)){
                    if(curr == NULL){
                        cout<<"index out of range "<<endl;
                        return;
                    }
                    nex = curr->next;
                    prev = curr;
                    curr = nex;
                    i++;
                }

                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
            }

        }

//Deletion_By_Value

        void deletion_byValue(int value){
            Node* prev = NULL;
            Node* curr = head;
            Node* nex = NULL;
            while(curr){
                if(!curr){
                    cout<<"Value not exist";
                    return;
                }
                else if(curr->data == value){
                    break;
                }
                else{
                    nex = curr->next;
                    prev = curr;
                    curr = nex;
                }
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;


        }

//Displaying_Linked_List_Datas

        void printList(){
            Node* temp = head;
            int a = 1;
            while(temp != NULL){
                cout<<a<<"  Data: "<<temp->data<<"  presentAddress: "<<temp<<"  nextAddress: "<<temp->next<<endl;
                temp = temp->next;
                a++;
            }
        }

//Searching data

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


int main(){
    List LL;
    LL.push_back(1);
    LL.push_back(2);
    LL.push_front(3);
    LL.push_back(4);
    LL.push_front(5);
    LL.push_back(6);
    LL.push_front(7);
    LL.insert(112,3);
     LL.printList();
    LL.deletion_byValue(112);
    LL.printList();

}