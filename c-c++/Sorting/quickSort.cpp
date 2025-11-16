#include<iostream>
using namespace std;


int partition(int arr[],int s,int e){
    int pivot = arr[s];

    int count = 0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    //Place for pivot
    int pivotIndex = s+count;
    swap(arr[pivotIndex],arr[s]);

    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[j--],arr[i++]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[],int s, int e){
    //Base Case
    if(s>=e){
        return;
    }

    int p = partition(arr,s,e);

    //Left part
    quickSort(arr,s,p-1);

    //Right Part
    quickSort(arr,p+1,e);
    


}

int main(){
    int arr[5] = {2,4,1,6,9};
    int n=5;

    cout<<"\nBefore Sorting : ";
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";

    quickSort(arr,0,n-1);
    cout<<"\nAfter Sorting : ";
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";



    return 0;
}