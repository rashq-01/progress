#include<iostream>

using namespace std;

class heap{
    public:
        int arr[100];
        int size;

        heap(){
            arr[0] = -1;
            size = 0;
        }
        void insert(int val){
            int index = ++size;
            arr[index] = val;

            while(index>1){
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[index],arr[parent]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }

        void print(){
            cout<<endl;
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

};

int main(){

    heap H;
    H.insert(50);
    H.insert(55);
    H.insert(53);
    H.insert(52);
    H.insert(54);

    H.print();

    return 0;
}