#include<iostream>
#define MAX 20
using namespace std;

void maxHeapify(int arr[],int &n, int &i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        maxHeapify(arr,n,largest);
    }
}

void maxHeapBuilder(int arr[],int &n){
    for(int i=(n/2)-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
}


void minHeapify(int arr[],int &n, int &i){
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left<n && arr[left]<arr[smallest]){
        smallest = left;
    }
    if(right<n && arr[right]<arr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[i],arr[smallest]);
        minHeapify(arr,n,smallest);
    }
}

void minHeapBuilder(int arr[],int &n){
    for(int i=(n/2)-1;i>=0;i--){
        minHeapify(arr,n,i);
    }
}

void insert(int arr[],int &n, int val){
    arr[n++] = val;
    maxHeapBuilder(arr,n);
}

void deleteNode(int arr[],int &n){
    arr[0] = arr[--n];
    maxHeapBuilder(arr,n);
}


int main() {
    int arr[MAX];
    int n;

    // Step 1: Input array
    cout << "Enter number of elements (1-20): ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 2: Print original
    cout << "\nOriginal Array : ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    // Step 3: Build MAX heap
    maxHeapBuilder(arr, n);
    cout << "\nAfter MAX Heap Build : ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    // Step 4: Insert a new element
    insert(arr, n, 15);
    cout << "\nAfter Insert(15) in MAX Heap : ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    // Step 5: Delete root
    deleteNode(arr, n);
    cout << "\nAfter Delete Root in MAX Heap : ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    // Step 6: Build MIN heap
    minHeapBuilder(arr, n);
    cout << "\nAfter MIN Heap Build : ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    cout << endl;
    return 0;
}
