#include<stdio.h>
#include<stdlib.h>

void binary_search(int arr[],int size,int target){
    int start = 0;
    int end = size-1;
    while(start<=end){
        int mid = (start - ((start-end)/2));
        if(target==arr[mid]){
            printf("\nElement %d found at index %d.",target,mid);
            return;
        }
        else if(target<arr[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }

    }
    printf("\nElement is not present");
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    binary_search(arr,10,0);
}