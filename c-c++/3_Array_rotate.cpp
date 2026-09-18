#include<iostream>
#include<math.h>
using namespace std;

void rotate(int arr[],int arr1[], int value, int size){
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        int temp = size - value -1;
        if (value > 0)
        {
            arr1[i] = arr[temp];
        }
        else{
            arr1[i] = arr[j];
        }
        j++;
        value--;
        
    }
    
}
void printArray(int array1[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<array1[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int n;
    cout<<"Enter the rotate value: ";
    cin>>n;
    int s;
    cout<<"Enter the size of array";
    cin>>s;
    int arr[100];
    int array[100];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < s; i++)
    {
        cin>>arr[i];
    }
    cout<<"Your array is ";
    printArray(arr,s);
    cout<<endl;
    cout<<"rotating the array....";
    rotate(arr,array,n,s);
    cout<<endl;
    cout<<"the result is";
    printArray(array,s);


    
}