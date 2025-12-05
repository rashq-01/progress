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


int main(){

    string words[] = {
    "supercalifragilisticexpialidocious",
    "pneumonoultramicroscopicsilicovolcanoconiosis",
    "hippopotomonstrosesquipedaliophobia",
    "antidisestablishmentarianism",
    "floccinaucinihilipilification",
    "pseudopseudohypoparathyroidism",
    "psychoneuroendocrinological",
    "thyroparathyroidectomized",
    "electroencephalographically",
    "honorificabilitudinitatibus",
    "tetrahydrocannabinol",
    "transubstantiation",
    "ultramicroscopically",
    "overintellectualization",
    "immunoelectrophoretically",
    "microspectrophotometries",
    "counterrevolutionaries",
    "hyperimmunoglobulinemia",
    "phosphatidylethanolamine",
    "radioimmunoelectrophoresis"
    };
    int n = sizeof(words)/sizeof(words[0]);

    Node* root = new Node();

    for(int i=0;i<n;i++){
        insert(root,words[i]);
    }
    search(root,"phosphatidylethanolamine");


    return 0;
}