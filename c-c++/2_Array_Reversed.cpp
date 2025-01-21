#include<iostream>
#include<math.h>
using namespace std;


void reversed(int array[], int n){
    int start = 0;
    int end = n-1;
    while (start <= end)
    {
        swap(array[start],array[end]);
        start++;
        end--;
    }
    
}
void printArray(int array1[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<array1[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[100];
    int s;
    cout<<"Enter size: ";
    cin>>s;
    cout<<"Enter elements: ";
    for (int i = 0; i < s; i++)
    {
        cin>>arr[i];
    }
    printArray(arr,s);
    reversed(arr,s);
    cout<<"The reversed is ";
    printArray(arr,s);
    
}