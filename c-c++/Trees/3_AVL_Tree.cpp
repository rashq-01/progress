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
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;

    return newNode;
}

int height(Node* node){
    if(node==nullptr) return 0;
    return node->height;
}

int getBalance(Node* node){
    if(node==nullptr) return 0;
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
    if(root==nullptr){
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
//Minumum value
Node* minValue(Node* root){
    Node* curr = root;
    while(curr && curr->left){
        curr = curr->left;
    }
    return curr;
}
//Remove node
Node* removeNode(Node* root, int key){
    if(!root) return root;
    
    if(key<root->val){
        root->left = removeNode(root->left,key);
    }
    else if(key>root->val){
        root->right = removeNode(root->right,key);
    }
    else{
        if(!root->left || !root->right){
            Node* temp = root->left ? root->left : root->right;
            if(!temp){
                delete root;
                root = nullptr;
            }
            else{
                Node* old = root;
                root = temp;
                delete old;

            }
        }
        else{
            Node* temp = minValue(root->right);
            root->val = temp->val;
            root->right = removeNode(root->right,temp->val);
        }

    }

    if(!root) return root;

    root->height = 1 + max(height(root->left),height(root->right));

    int balance = getBalance(root);

    //Right Rotation Case
    if(balance>1 && getBalance(root->left)>=0){
        return rightRotation(root);
    }

    //Left Rotation Case
    if(balance>1 && getBalance(root->left)<0){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    //Right Rotation Case
    if(balance<-1 && getBalance(root->right)<=0){
        return leftRotation(root);

    }
    //Right Left Rotation
    if(balance<-1 && getBalance(root->right)>0){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;

}


void inOrder(Node* root){
    if(root==nullptr) return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp==nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<temp->val<<" ";
            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);
        }
    }


}


int main(){
    Node* root = NULL;

    cout << "=== AVL Tree Insertions ===" << endl;

    // Step 1: Insert nodes
    int insertArr[] = {30, 20, 40, 10, 25, 50, 5};
    for(int i=0; i<7; i++){
        cout << "\nInserting: " << insertArr[i] << endl;
        root = insert(root, insertArr[i]);
        cout << "Inorder: ";
        inOrder(root);
        cout << "\nLevel Order:" << endl;
        levelOrder(root);
    }

    cout << "\n=== AVL Tree Deletions ===" << endl;

    // Step 2: Delete leaf node
    cout << "\nDeleting leaf node 5" << endl;
    root = removeNode(root, 5);
    cout << "Inorder: ";
    inOrder(root);
    cout << "\nLevel Order:" << endl;
    levelOrder(root);

    // Step 3: Delete node with one child
    cout << "\nDeleting node 25 (one child)" << endl;
    root = removeNode(root, 25);
    cout << "Inorder: ";
    inOrder(root);
    cout << "\nLevel Order:" << endl;
    levelOrder(root);

    // Step 4: Delete node with two children
    cout << "\nDeleting node 20 (two children)" << endl;
    root = removeNode(root, 20);
    cout << "Inorder: ";
    inOrder(root);
    cout << "\nLevel Order:" << endl;
    levelOrder(root);

    // Step 5: Delete root repeatedly
    int toDelete[] = {30, 40, 10, 50};
    for(int val : toDelete){
        cout << "\nDeleting node " << val << endl;
        root = removeNode(root, val);
        cout << "Inorder: ";
        inOrder(root);
        cout << "\nLevel Order:" << endl;
        levelOrder(root);
    }

    // Step 6: Insert ascending order (RR rotations)
    cout << "\nInserting nodes in ascending order: 1 2 3 4 5 6 7" << endl;
    int asc[] = {1,2,3,4,5,6,7};
    root = NULL;
    for(int val : asc){
        root = insert(root, val);
    }
    cout << "Inorder: ";
    inOrder(root);
    cout << "\nLevel Order:" << endl;
    levelOrder(root);

    // Step 7: Insert descending order (LL rotations)
    cout << "\nInserting nodes in descending order: 7 6 5 4 3 2 1" << endl;
    int desc[] = {7,6,5,4,3,2,1};
    root = NULL;
    for(int val : desc){
        root = insert(root, val);
    }
    cout << "Inorder: ";
    inOrder(root);
    cout << "\nLevel Order:" << endl;
    levelOrder(root);

    return 0;
}
