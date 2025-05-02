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

Node* insertion(Node* &root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data>=root->data){
        insertion(root->right,data);
    }
    else{
        insertion(root->left,data);
    }

    return root;


}

void takeInput(Node* &root){
    int d;
    cout<<endl<<"Enter data: ";
    cin>>d;
    while(d !=-1){
        root = insertion(root,d);
        cout<<endl<<"Enter data: ";
        cin>>d;
    }
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


int main(){
    Node* root = NULL;
    
    /*root = buildTree(root);
    
    
    cout<<endl<<"Inorder Traversal: ";
    inOrderTraversal(root);
    
    cout<<endl<<"Pre-Order Traversal: ";
    preOrderTraversal(root);
    
    cout<<endl<<"Post-Order Traversal: ";
    postOrderTraversal(root);
    */
   cout<<endl<<"Enter datas for BST: "<<endl;
   takeInput(root);
   
   cout<<endl<<"Printing the level of traversal output: "<<endl;
   levelOrderTraversal(root);
    cout<<endl<<"Inorder Traversal: ";
    inOrderTraversal(root);


    return 0;
}