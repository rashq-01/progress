#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

class Hashing{

    public:

        vector<list<int>> hashtable;
        int buckets;

        Hashing(int size){
            buckets = size;
            hashtable.resize(size);
        }

        int hashValue(int key){
            return key%buckets; //division Methods
        }

        void add(int key){
            int idx = hashValue(key);
            hashtable[idx].push_back(key);
        }

        list<int>::iterator search(int key){
            int idx = hashValue(key);
            return find(hashtable[idx].begin(),hashtable[idx].end(),key);
        }

        void remove(int key){

            int idx = hashValue(key);
            if(search(key) != hashtable[idx].end()){
                hashtable[idx].erase(search(key));
                cout<<endl<<key<<" is deleted.";
            }
            cout<<endl<<key<<" is not present in Hash Table.";
        }

        void display(){
            for(int i=0;i<buckets;i++){
                cout<<i<<": ";
                for(auto val:hashtable[i]){
                    cout<<val<<" -> ";
                }
                cout<<"NULL\n";
            }
        }
};



int main(){
    Hashing h(10);
    h.add(5);
    h.add(9);
    h.add(3);

    h.display();

    h.remove(6); // Not present
    h.remove(5); // Present

    cout << "\n\nAfter Deletion:\n";
    h.display();

    return 0;
}