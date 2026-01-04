#include<iostream>
#include<vector>
#define MAX 8
using namespace std;

int tree[MAX*4] = {0};

int buildST(int arr[], int idx, int start, int end){
    if(start==end){
        tree[idx] = arr[start];
        return arr[start];
    }

    int mid = (start + ((end-start)/2));
    
    int left = buildST(arr,2*idx+1,start,mid);
    int right = buildST(arr,2*idx+2,mid+1,end);

    tree[idx] = left+right;

    return tree[idx];


}


int main(){
    int arr[MAX] = {1,2,3,4,5,6,7,8};
    int n = MAX;
    int x = buildST(arr,0,0,n-1);

    for(int i=0;i<15;i++){
        cout<<tree[i]<<" ";
    }
    cout<<x;



    return 0;
}