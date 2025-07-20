#include<stdio.h>
int main(){
    int n;
    printf("Enter Size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter %d Elements for the array: ");
    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",arr+i);
    }
    printf("\nOriginal Array: ");
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    int end = n-1;
    for(int i=0;i<(n/2);i++){
        int temp = arr[i];
        arr[i] = arr[end];
        arr[end] = temp;
        end--;
    }
    printf("\nReversed Array: ");
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    
    return 0;
}