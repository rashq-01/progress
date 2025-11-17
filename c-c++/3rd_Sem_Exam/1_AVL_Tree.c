#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a,int b){
    return a>b?a:b;
}


struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
int height(struct Node* node){
    if(!node)return 0;
    else return node->height;
}
int getBalance(struct Node* node){
    if(!node)return 0;
    return height(node->left) - height(node->right);
}

struct Node* rightRotation(struct Node* y){
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    y->left = T2;
    x->right = y;

    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    return x;

}

struct Node* leftRotation(struct Node* x){
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    x->right = T2;
    y->left = x;
    
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return y;
}

struct Node* insert(struct Node* node,int key){
    if(!node){
        return createNode(key);
    }
    else if(key>node->data){
        node->right = insert(node->right,key);
    }
    else if(key<node->data){
        node->left = insert(node->left,key);
    }
    else{
        return node;
    }

    node->height = max(height(node->left),height(node->right)) +1;
    
    int balance = getBalance(node);
    
    if(balance>1){
        if(key<node->left->data){
            return rightRotation(node);
        }
        if(key>node->left->data){
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }
    }
    if(balance < -1){
        if(key>node->right->data){
            return leftRotation(node);
        }
        if(key<node->right->data){
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }
    }

    return node;
}


int main(){


    return 0;
}