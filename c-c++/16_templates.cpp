#include<iostream>
using namespace std;
template <typename t>
t add(t a, t b){
    return a+b;
}
int main(){
    cout<<"Integer: "<<add<int>(5,6)<<endl;
    cout<<"Float: "<<add<float>(4.5,3.4)<<endl;
    return 0;
}