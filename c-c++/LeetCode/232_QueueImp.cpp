#include<iostream>
#include<stack>
using namespace std;


class myQueue{
    private:
        stack<int> s1;
        stack<int> s2;
    
    public:
        myQueue(){

        }

        void push(int x){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }

        int pop(){
            int temp = s1.top();
            s1.pop();
            return temp;
        }

        int peek(){
            return s1.top();
        }
        
        bool empty(){
            return s1.empty();
        }
};


int main(){


    return 0;
}



/*
Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false


*/