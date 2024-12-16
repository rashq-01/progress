#include<iostream>
#include<math.h>
using namespace std;

int sorted(int array[], int size){
    for (int i = 0; i < size; i++)
    {
        int index = i;
        for (int j = i; j < size; j++)
        {
            if (array[j]<array[i])
            {
                index = j;
            }
        }
        int temp = array[index];
        array[index] = array[i];
        array[i] = temp;
        
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
    int s;
    cout<<"Enter the size of array: ";
    cin>>s;
    int arr[100];
    cout<<"Enter the elements: ";
    for (int i = 0; i < s; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Before sorted: ";
    printArray(arr,s);
    cout<<endl;
    cout<<"After sorted: ";
    sorted(arr,s);
    printArray(arr,s);
    cout<<endl;

}