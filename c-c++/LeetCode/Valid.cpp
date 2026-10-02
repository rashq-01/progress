#include<bits/stdc++.h>

using namespace std;

int main(){
    string s = "()";
    int n = s.size();
    stack<char> st;

    for(auto ch : s){
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            if(st.empty() || st.top()!=ch)cout<<0;return 1;

            st.pop();
        }
    }

    cout<<st.empty();
}