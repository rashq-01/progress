#include<iostream>
using namespace std;


void selection_sort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int index = i;
        for(int j=i+1;j<=n;j++){
            if(arr[j]<arr[index]){
                index = j;
            }
        }
        int temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }
}


void printArray(int arr[],int size){
    for(int i=0;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]= {7,8,0,44,78,33,90};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Sorting: ";
    printArray(arr,size-1);
    cout<<endl<<"After Sorting: ";
    selection_sort(arr,size-1);
    printArray(arr,size-1);
}