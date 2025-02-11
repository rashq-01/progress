#include<iostream>
using namespace std;

void bubble_sort(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    bubble_sort(arr,size-1);
    printArray(arr,size-1);
}