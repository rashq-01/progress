#include<iostream>
using namespace std;
void printArray(int array1[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<array1[i]<<" ";
    }
    cout<<endl<<"The size of the array is "<<size;
    cout<<endl;
}

int function(int arr[],int size){
    int final = 0;
    for(int i = 0; i<size; i++){
        for(int j = i+1; j<size; j++){
            if(arr[j]< arr[i]){
                int area = arr[j] * (j-i);
                if(area > final){
                    final = area;
                }
            }
            else{
                int area = arr[i] * (j-1);
                if(area > final){
                    final = area;
                }
            }
            
            
        }
    }
    return final;
}





int main(){
    int arr[] = {1,8,6,2,5,4,8,3,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = function(arr,size);
    cout<<endl<<result;
    
}