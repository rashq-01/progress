#include<iostream>
#define MAX 10
using namespace std;

void countingSort(int arr[],int n){
    int temp[MAX] = {0};
    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }
    int j = 0;
    for(int i=0;i<MAX;i++){
        while(temp[i]){
            arr[j++] = i;
            temp[i]--;
        }
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[MAX] = {1,1,4,2,7,3,3,5,9,6};
    cout<<"Before Count Sort : ";
    printArray(arr,MAX);

    cout<<"After Count Sort : ";
    countingSort(arr,MAX);
    printArray(arr,MAX);


    return 0;
}