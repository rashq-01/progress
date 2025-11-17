#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 20

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int arr[CAPACITY];
int size = 0;

// void insert(int key){
//     int index = size++;
//     arr[index] = key;
//     while(index>0){
//         int parent = (index-1)/2;
//         if(arr[index] > arr[parent]){
//             swap(&arr[index],&arr[parent]);
//         }
//         else{
//             return;
//         }
//         index = parent;
        
//     }
// }

void heapify(int arr[],int n, int i){
    int largest = i;
    int left = largest*2+1;
    int right = largest*2+2;

    if(left<n && arr[largest]<arr[left]){
        largest = left;

    }
    if(right<n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}

void insert(int key){
    int index = size++;
    arr[index] = key;
    for(int i=size/2-1;i>=0;i--){
        heapify(arr,size,i);

    }


}





void print(){
    printf("-----------MAX HEAP-------------\n\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}


int main(){
    insert(50);
    insert(55);
    insert(53);
    insert(52);
    insert(54);
    print();



    return 0;
}