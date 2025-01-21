// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"enter number";
    cin>>n;
    int result = 0;
    int i = 0;
    while(n != 0){
        int temp = n & 1;
        result = result << 1;
        result = result ^ temp;
        cout<<"result:"<<result<<endl;
        cout<<"n&1:"<< (n& 1)<<endl;
        n = n>>1;
        i++;
    }
    cout<<"The final result is "<<(result<<(32-i));

    return 0;
}