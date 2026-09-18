#include<iostream>
using namespace std;

class Stack{
        //data members
        int *arr;
        int capacity;
        int top;
    public:
        Stack(int size){
            this -> capacity = size;
            top = -1;
            arr = new int[size];
        }

        void push(int val){
            if(top == capacity-1){
                cout<<"Stack Overflow\n";
                return;
            }
            arr[++top] = val;
        }

        void pop(){
            if(top == -1){
                cout<<"Stack underflow\n";
                return;
            }
            top--;
        }

        int peek(){
            if(top == -1){
                cout<<"Stack is empty\n";
                return -1;
            }
            return arr[top];
        }

        int isEmpty(){
            return top == -1;
        }

        int size(){
            return top+1;
        }
        ~Stack(){
            delete[] arr;
        }
};
int main(){
    Stack s1(5);
    cout<<s1.isEmpty()<<endl;
    s1.push(5);
    cout<<s1.peek()<<endl;
    s1.push(58);
    cout<<s1.peek()<<endl;
    s1.pop();
    cout<<s1.peek();
    return 0;
}