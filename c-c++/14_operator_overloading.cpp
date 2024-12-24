#include<iostream>
using namespace std;

class complex{
    private:
    int r;
    int i;

    public:
    complex(int a=0, int b=0){
        r=a;
        i=b;
    }
    void dipaly(){
        cout<<"Real part: "<<r<<" imaginary: "<<i<<endl;
    }
    complex operator +(complex com){
        complex x;
        x.r = r+com.r;
        x.i = i+com.i;
        return x;
    }
    complex operator -(complex com){
        complex x;
        x.r = r-com.r;
        x.i = i-com.i;
        return x;
    }
};

int main(){
    complex c1(5,6), c2(8,9), c3(1,2),c4;
    c4 = c1+c2-c3;
    c4.dipaly();
}