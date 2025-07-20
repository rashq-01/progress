#include<stdio.h>
int main(){
    int SIZE;
    printf("Enter the size of the array: ");
    scanf("%d",&SIZE);
    int arr[SIZE];
    printf("\nEnter %d elements for the array: ",SIZE);
    for(int i=0;i<SIZE;i++){
        printf("\nEnter element %d: ",i+1);
        scanf("%d",arr+i);
    }
    printf("\nOriginal Array elements: ");
    for(int i=0;i<SIZE;i++){
        printf(" %d",arr[i]);
    }
    int del_index;
    printf("\nEnter the index of delete element (0-%d): ",SIZE-1);
    scanf("%d",&del_index);
    if(del_index<0 || del_index>=SIZE){
        printf("Invalid index");
        return 1;
    }
    for(int i=del_index;i<SIZE-1;i++){
        arr[i] = arr[i+1];
    }
    SIZE=SIZE-1;
    printf("\nModified Array: ");
    for(int i=0;i<SIZE;i++){
        printf(" %d",arr[i]);
    }
}







/*
#include <stdio.h>
int main() {
int n;
printf("Enter the size of the array: ");
scanf("%d", &n);
int LA[n]; // Declaring array of size n
printf("Enter %d elements for the array:\n", n);
for(int i = 0; i < n; i++) {
printf("Enter element %d: ", i + 1);
scanf("%d", &LA[i]);
}
printf("The original array elements are:\n");
for(int i = 0; i < n; i++)
printf("LA[%d] = %d \n", i, LA[i]);
int del_index;
printf("Enter the index of the element to delete (0 to %d): ", n - 1);
scanf("%d", &del_index);
if (del_index < 0 || del_index >= n) {
printf("Invalid index.\n");
return 1; // Exiting program with error code
}
// Deleting element at del_index
for(int i = del_index; i < n - 1; i++) {
LA[i] = LA[i + 1];
}
n = n - 1; // Decreasing size of array
printf("The array elements after deletion:\n");
for(int i = 0; i < n; i++)
printf("LA[%d] = %d \n", i, LA[i]);
return 0;
}
*/