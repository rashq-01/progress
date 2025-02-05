#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr,int start, int mid, int end){
    vector<int> temp;
    int i=start, j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int id=0;id<temp.size();id++){
        arr[id+start] = temp[id];
    }


}

void mergeSort(vector<int> &arr,int start, int end){
    if(start<end){
        int mid = start + (end-start)/2;

        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);

        merge(arr,start,mid,end);
    }
}

void printArray(vector<int>& arr,int size){
    cout<<endl<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr= {7,4,3,6,5,1,2,};
    int size = arr.size();
    printArray(arr,arr.size());
    mergeSort(arr,0,arr.size()-1);
    printArray(arr,arr.size());
}