#include<iostream>
#include<vector>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;


        heap(){
            arr[0] = -1;
            size=0;
        }

        void insert(int n){
            int idx = ++size;
            arr[idx] = n;

            while(idx>1){
                int parent = idx/2;
                if(arr[parent]<arr[idx]){
                    swap(arr[parent],arr[idx]);

                    idx = parent;
                }
                else{
                    return;
                }
            }
        }

        void display(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<"\t";
            }
        }
};


void heapify(int arr[],int n,int i){
    int largest = i;
    int left = i*2;
    int right = i*2+1;

    if(i<=n && arr[largest]<arr[left]){
        largest = left;
    }
    if(i<=n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest != i){
        heapify(arr,n,largest);
    }
    else{
        return;
    }
}

void buildHeap(int arr[],int n){
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }
}


int main(){

    // heap h;

    // h.insert(12);
    // h.insert(23);
    // h.insert(2);
    // h.insert(4);
    // h.insert(32);
    // h.insert(11);
    // h.insert(21);
    // h.insert(45);
    // h.insert(67);
    // h.insert(17);
    // h.insert(43);
    // h.insert(32);
    // h.insert(32);
    // h.display();


    // index-1 based array
    int arr[6] = {-1, 10, 20, 15, 30, 40};

    int n = (sizeof(arr)/sizeof(arr[0])) - 1;

    cout << "\nArray before heapify: ";
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << "\n";

    buildHeap(arr, n);

    cout << "Array after buildHeap: ";
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << "\n";

    return 0;

    return 0;
}