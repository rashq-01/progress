#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree(Node* root){
    int data;
    cout<<endl<<"Enter data: ";
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<endl<<"Enter data for inserting in left of "<<data<<" :";
    root->left = buildTree(root->left);
    cout<<endl<<"Enter data for inserting in right of "<<data<<" :";
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


void inOrderTraversal(Node* root){
    if(!root){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(!root){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void buildTreeFromLevelOrder(Node* &root){
    queue<Node*> q;
    int data;
    cout<<endl<<"Enter data for root: ";
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        int leftData,rightData;
        cout<<endl<<"Enter data for left Node of "<<temp->data<<": ";
        cin>>leftData;
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        cout<<endl<<"Enter data for right Node of "<<temp->data<<": ";
        cin>>rightData;
        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }


}

int main(){
    Node* root = NULL;
    
    /*root = buildTree(root);
    
    cout<<endl<<"Printing the level of traversal output: "<<endl;
    levelOrderTraversal(root);
    
    cout<<endl<<"Inorder Traversal: ";
    inOrderTraversal(root);
    
    cout<<endl<<"Pre-Order Traversal: ";
    preOrderTraversal(root);
    
    cout<<endl<<"Post-Order Traversal: ";
    postOrderTraversal(root);
    */
    
    buildTreeFromLevelOrder(root);

    cout<<endl<<"Inorder Traversal: ";
    inOrderTraversal(root);
    
}









// 100 50 25 -1 -1 75 65 -1 -1 85 -1 -1 150 125 -1 -1 175 -1 -1 
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

/*

             1
     3              5
7      11      17       



*/

