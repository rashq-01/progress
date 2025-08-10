#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
    int height;
};

Node* createNode(int val){
    Node* newNode = new Node();
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

int height(Node* node){
    if(node==NULL) return 0;
    return node->height;
}

int getBalance(Node* node){
    if(node==NULL) return 0;
    return (height(node->left) - height(node->right));
}

Node* rightRotation(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;

    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right)) + 1;
    
    return x;
}
Node* leftRotation(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;

    return y;
}

Node* insert(Node* root,int key){
    if(root==NULL){
        return createNode(key);
    }
    if(key<root->val){
        root->left = insert(root->left,key);
    }
    else if(key>root->val){
        root->right = insert(root->right,key);
    }
    else{
        return root;
    }

    root->height = max(height(root->left),height(root->right)) + 1;
    int balance = getBalance(root);

    if((balance>1) && (key<root->left->val)){
        return rightRotation(root);
    }
    if((balance<-1) && (key>root->right->val)){
        return leftRotation(root);
    }

    if((balance>1) && (key>root->left->val)){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    if((balance<-1) && (key<root->right->val)){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void inOrder(Node* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->val<<" ";
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }


}


int main(){
    Node* root = NULL;
    int arr[11] = {20,11,5,32,40,2,4,27,23,28,50};
    for(int i=0;i<11;i++){
        cout<<"inserting : "<<arr[i]<<endl;
        root = insert(root,arr[i]);
    }

    cout<<"Inorder Traversal Of AVL Tree : ";
    inOrder(root);
    cout<<endl;
    cout<<"Level Order Traversal : "<<endl;
    levelOrder(root);

    return 0;

    
}

