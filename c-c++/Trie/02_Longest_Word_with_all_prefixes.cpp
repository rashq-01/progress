#include<iostream>


using namespace std;

class Node{
    public:
    Node* child[26];
    bool isWord;


    Node(){
        for(int i=0;i<26;i++){
            child[i] = nullptr;
        }
        isWord = false;
    }
};

void insert(Node* &root,string &word){
    Node* curr = root;
    for(char ch:word){
        int idx = ch - 'a';
        if(curr->child[idx] == nullptr){
            curr->child[idx] = new Node();
        }
        curr = curr->child[idx];
    }
    curr->isWord = true;
}

void search(Node* &root,string word){
    Node* curr = root;
    for(auto ch:word){
        int idx = ch - 'a';
        if(curr->child[idx]){
            curr = curr->child[idx];
        }
        else{
            cout<<"\n'"<<word<<"' not found!"<<endl;
            return;
        }
    }
    if(curr->isWord){
        cout<<"\n'"<<word<<"' found..."<<endl;

    }
}
string ans  = "";
void longestWord(Node* &root,string temp){
    if(!root) return;

    for(int i=0;i<26;i++){
        if(root->child[i] && root->child[i]->isWord){
            char ch = 'a'+i;
            temp.push_back(ch);
            if(temp.size()>ans.size()){
                ans = temp;
            }
            longestWord(root->child[i],temp);
            temp.pop_back();
        }
    }

}


int main(){
    string words[7] {"a","banana","app","appl","ap","apply","apple"};

    Node* root = new Node();
    for(int i=0;i<7;i++){
        insert(root,words[i]);
    }
    longestWord(root,"");
    cout<<ans;


    return 0;
}