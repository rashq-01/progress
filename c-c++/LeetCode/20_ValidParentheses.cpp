#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string str) {
        stack<char> st;
        for(int i=0;i<str.size();i++){
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                st.push(str[i]);
            }
            else{
                if(st.size() == 0){
                    return false;
                }
                if((st.top() == '(' && str[i] == ')') || (st.top()=='{' && str[i]=='}') || (st.top()=='[' && str[i]==']')){
                    st.pop();

                }
                else{
                    return false;
                }
            }
        }
        return st.size()==0;
        
    }


int main(){
    string s = "()[{}";
    cout<<isValid(s);


    return 0;

}





/*
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true
*/
