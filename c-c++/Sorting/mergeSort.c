#include<stdio.h>

void merge(int arr[],int start, int mid, int end){
    int leftSide = mid-start+1;
    int rightSide = end-mid;
    int left[leftSide], right[rightSide];
    int i,j,k;
    for(i=0;i<leftSide;i++){
        left[i] = arr[start+i];
    }
    for(j=0;j<rightSide;j++){
        right[j] = arr[mid+1+j];
    }
    i=j=k=0;
    while(i<leftSide && j<rightSide){
        if(left[i] < right[j]){
            arr[k+start] = left[i];
            i++;
        }
        else{
            arr[k+start] = right[j];
            j++;
        }
        k++;
    }
    while(i<leftSide){
        arr[k+start] = left[i];
        i++;
        k++;
    }

    while(j<rightSide){
        arr[k+start] = right[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[],int start, int end){
    if(start<end){
        int mid = start + (end-start)/2;


        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);

        
        merge(arr,start,mid,end);
    }
}



void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}


int main(){

    int arr[]= {7,4,3,6,5,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Before Sorting: ");
    printArray(arr,size);
    mergeSort(arr,0,size-1);
    printf("\nAfter Sorting: ");
    printArray(arr,size);
}
