#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i=1;i<=n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;

        }
        arr[j+1] = key;
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
    insertion_sort(arr,size-1);
    printArray(arr,size-1);
}