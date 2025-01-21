#include<iostream>
using namespace std;

//Two function with smae name but for different datypes
int addition(int num1, int num2){
    return num1+num2;
}

float addition(float num1, float num2){
    return num1+num2;

}
int main(){
    int int1 = 4;
    int int2 = 5;
    float float1 = 2.3;
    float float2 = 4.5;
    cout<<"Result for "<<int1<<" + "<<int2<<" is "<<addition(int1,int2)<<endl;
    cout<<"Result for "<<float1<<" + "<<float2<<" is "<<addition(float1,float2)<<endl;

}