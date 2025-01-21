#include<iostream>
#include<math.h>
using namespace std;

int min(int array[], int s){
    int result = INT32_MAX;
    for (int i = 0; i < s; i++)
    {
        if (array[i] < result)
        {
            result = array[i];
        }
        
    }
    return result;
    

}


int main(){
    int size;
    int arr[100];
    cout<<"Enter the size: ";
    cin>>size;
    cout<<"Enter the values: ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<<"The mininmum value is "<<min(arr,size);
}


