#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int>& vec,int start,int mid,int end){
    int n1=mid-start;
    int n2=end-mid+1;
    vector<int> leftvec(n1),rightvec(n2);
    for(int i=0;i<n1;i++){
        leftvec[i] = vec[start+i];
    }
    for(int j=0;j<n2;j++){
        rightvec[j] = vec[(mid+1+j)];
    }
    int i=0;
    int j=0;
    int k=start;
    while(i<n1 && j<n2){
        if(leftvec[i] <= rightvec[j]){
            vec[k] = leftvec[i];
            i++;
            k++;
        }
        else{
            vec[k] = rightvec[j];
            j++;
            k++;
        }
        
    }
    for(i;i<n1;i++){
        vec[k] = leftvec[i];
        k++;
    }
    for(j;j<n2;j++){
        vec[k] = rightvec[j];
        k++;
    }
}

void mergeSort(vector<int>& vec,int start,int end){
    if(start<end){
        int mid = (start+end)/2;
        mergeSort(vec,start,mid);
        mergeSort(vec,mid+1,end);
        merge(vec,start,mid,end);
    }
}
int main(){
    vector<int> arr(7);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(8);
    arr.push_back(0);
    arr.push_back(7);
    int size = 7;
}