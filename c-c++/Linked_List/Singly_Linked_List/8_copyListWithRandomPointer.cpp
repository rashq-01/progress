#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* random = nullptr;
        Node(int value){
            val = value;
        }
};
void printList(Node* head){
    cout<<endl<<endl;
    int i=1;
    while(head){
        cout<<i<<".  "<<"Value: "<<head->val<<" presentAdd: "<<head<<"  nextAdd:  "<<head->next<<"  randomPointer: "<<head->random->val<<endl;
        head = head->next;
        i++;
    }
}

Node* copyRandomList(Node* head) {
    if(head==NULL){
        return NULL;
    }
    unordered_map<Node*,Node*> m;
    Node* oldHead = head;
    Node* newHead = new Node(head->val);
    Node* old = head->next;
    Node* New = newHead;
    m[oldHead] = newHead;
    while(old){
        Node* nex = new Node(old->val);
        m[old] = nex;
        New->next = nex;
        old = old->next;
        New = New->next;
    }
    New = newHead;
    old = head;
    while(old){
        if(old->random == NULL){
            New->random == NULL;
        }
        New->random = m[old->random];
        old = old->next;
        New = New->next;
    }

    return newHead;

    
}

int main(){
    //   1 -> 2 -> 3 -> 4 -> -> 5

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Assign random pointers
    head->random = head->next->next->next;      // 1 -> 4
    head->next->random = head->next->next;      // 2 -> 3
    head->next->next->random = head;            // 3 -> 1
    head->next->next->next->random = head->next->next->next->next; // 4 -> 5
    head->next->next->next->next->random = head->next; // 5 -> 2

    // printList(head);
    printList(head);
    printList(copyRandomList(head));
    
}