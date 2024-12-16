#include<iostream>
using namespace std;

void printArray(int array1[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<array1[i]<<" ";
    }
    cout<<endl;
}



int sorting(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        for (int  j = i; j < size; j++)
        {
            if(arr[j] <= arr[i]){
                swap(arr[j], arr[i]);
            }
        }
        
    }
    
}

int main(){
    int array[10];
    int size = 10;
    for (int  i = 0; i < size; i++)
    {
        cout<<"Enter element no. "<<i<<" ";
        cin>>array[i];
    }
    cout<<"Your entered array is ";

    printArray(array,size);

    sorting(array,size);

    cout<<"After sorting ";
    printArray(array,size);

    
}