#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    Node* getHead() {
        return head;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        int a = 1;
        while (temp != NULL) {
            cout << a << "  Data: " << temp->data << "  presentAddress: " << temp << "  nextAddress: " << temp->next << endl;
            temp = temp->next;
            a++;

            // Break if cycle is detected to prevent infinite loop
            if (a > 20) {  
                cout << "Cycle detected, stopping print...\n";
                break;
            }
        }
    }
};

void deleteCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            Node* prev = NULL;
            while(slow != fast){
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }
            prev->next = NULL;
        }
    }
}

int main() {
    List LL;
    for (int i = 1; i <= 12; i++) {
        LL.push_back(i);
    }

    // Creating cycle
     /*

    1-->2-->3-->4-->5-->6-->7-->8-->9-->10-->11-->12
                                    ^              |
                                    |              |
                                    ^--<--<--<--<--|

    */
    
    Node* temp = LL.getHead()->next->next->next->next->next->next->next->next;;
    LL.getHead()->next->next->next->next->next->next->next->next->next->next->next->next = temp;
    LL.printList();


    deleteCycle(LL.getHead());
    LL.printList();
}
