#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//Swapping
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function for quick Sort
int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

//Quick Sort Function
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);

    }
}

//Merge function for MergeSort
void merge(int arr[],int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    
    int *L = (int*)malloc(n1*sizeof(int));
    int *R = (int*)malloc(n2*sizeof(int));

    for(int i=0;i<n1;i++){
        L[i] = arr[l+i];
    }

    for(int j=0;j<n2;j++){
        R[j] = arr[m+1+j];
    }
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while(i<n1){
        arr[k++] = L[i++];
    }
    while(j<n2){
        arr[k++] = R[j++];
    }
    free(R);
    free(L);
}

//Merge Sort function
void mergeSort(int arr[],int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

//Utility Functions to generate test cases
void generateBestCase(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i] = n-i;
    }
}

void generateAverageCase(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i] = rand()%n;
    }
}

//Function to copy array
void copyArray(int src[],int dest[],int n){
    for(int i=0;i<n;i++){
        dest[i] = src[i];
    }
}
double measureQuickSort(int arr[],int n){
    clock_t start,end;
    start = clock();
    quickSort(arr,0,n-1);
    end = clock();
    return ((double)(end-start)) / CLOCKS_PER_SEC;
}
double measureMergeSort(int arr[],int n){
    clock_t start,end;
    start = clock();
    mergeSort(arr,0,n-1);
    end = clock();
    return ((double)(end-start)) / CLOCKS_PER_SEC;
}
