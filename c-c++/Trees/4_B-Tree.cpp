#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// B-Tree node structure
struct BTreeNode {
    vector<int> keys;
    vector<BTreeNode*> children;
    bool isLeaf;

    BTreeNode(bool leaf) : isLeaf(leaf) {}

    ~BTreeNode() {
        for (auto child : children)
            delete child;
    }
};

// B-Tree class
class BTree {
public:
    BTreeNode* root;
    int degree;

    BTree(int _degree) : root(nullptr), degree(_degree) {}
    ~BTree() { delete root; }
};


// Forward declarations
void removeNode(BTreeNode* node, int key, int degree);
void removeFromLeaf(BTreeNode* node, int index);
void removeFromNonLeaf(BTreeNode* node, int index, int degree);
void fill(BTreeNode* node, int index, int degree);


// Traverse in-order
void traverse(BTreeNode* node) {
    int i;
    for (i = 0; i < node->keys.size(); i++) {
        if (!node->isLeaf)
            traverse(node->children[i]);
        cout << node->keys[i] << " ";
    }
    if (!node->isLeaf)
        traverse(node->children[i]);
}

// Search for key
bool searchKey(BTreeNode* node, int key) {
    int i = 0;
    while (i < node->keys.size() && key > node->keys[i]) i++;
    if (i < node->keys.size() && key == node->keys[i]) return true;
    if (node->isLeaf) return false;
    return searchKey(node->children[i], key);
}

// Split child node
void splitChild(BTreeNode* parent, int index, BTreeNode* child, int degree) {
    BTreeNode* newNode = new BTreeNode(child->isLeaf);

    // Move last (degree-1) keys to newNode
    newNode->keys.assign(child->keys.begin() + degree, child->keys.end());
    child->keys.erase(child->keys.begin() + degree, child->keys.end());

    // Move children if not leaf
    if (!child->isLeaf) {
        newNode->children.assign(child->children.begin() + degree, child->children.end());
        child->children.erase(child->children.begin() + degree, child->children.end());
    }

    // Middle key moves to parent
    int midKey = child->keys[degree - 1];
    child->keys.erase(child->keys.begin() + degree - 1);
    parent->keys.insert(parent->keys.begin() + index, midKey);

    parent->children.insert(parent->children.begin() + index + 1, newNode);
}

// Insert in non-full node
void insertNonFull(BTreeNode* node, int key, int degree) {
    int i = node->keys.size() - 1;

    if (node->isLeaf) {
        node->keys.push_back(0);
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
    } else {
        while (i >= 0 && key < node->keys[i]) i--;
        i++;
        if (node->children[i]->keys.size() == 2 * degree - 1) {
            splitChild(node, i, node->children[i], degree);
            if (key > node->keys[i]) i++;
        }
        insertNonFull(node->children[i], key, degree);
    }
}

// Insert main function
void insert(BTree* tree, int key) {
    if (!tree->root) {
        tree->root = new BTreeNode(true);
        tree->root->keys.push_back(key);
        return;
    }

    if (tree->root->keys.size() == 2 * tree->degree - 1) {
        BTreeNode* newRoot = new BTreeNode(false);
        newRoot->children.push_back(tree->root);
        splitChild(newRoot, 0, tree->root, tree->degree);

        int i = (newRoot->keys[0] < key) ? 1 : 0;
        insertNonFull(newRoot->children[i], key, tree->degree);
        tree->root = newRoot;
    } else {
        insertNonFull(tree->root, key, tree->degree);
    }
}

// Get predecessor
int getPredecessor(BTreeNode* node) {
    while (!node->isLeaf) node = node->children.back();
    return node->keys.back();
}

// Get successor
int getSuccessor(BTreeNode* node) {
    while (!node->isLeaf) node = node->children.front();
    return node->keys.front();
}

// Merge nodes
void mergeNodes(BTreeNode* node, int index) {
    BTreeNode* child = node->children[index];
    BTreeNode* sibling = node->children[index + 1];

    child->keys.push_back(node->keys[index]);
    child->keys.insert(child->keys.end(), sibling->keys.begin(), sibling->keys.end());

    if (!child->isLeaf)
        child->children.insert(child->children.end(), sibling->children.begin(), sibling->children.end());

    node->keys.erase(node->keys.begin() + index);
    node->children.erase(node->children.begin() + index + 1);

    delete sibling;
}

// Borrow from previous child
void borrowFromPrev(BTreeNode* node, int index) {
    BTreeNode* child = node->children[index];
    BTreeNode* sibling = node->children[index - 1];

    child->keys.insert(child->keys.begin(), node->keys[index - 1]);
    node->keys[index - 1] = sibling->keys.back();
    sibling->keys.pop_back();

    if (!child->isLeaf) {
        child->children.insert(child->children.begin(), sibling->children.back());
        sibling->children.pop_back();
    }
}

// Borrow from next child
void borrowFromNext(BTreeNode* node, int index) {
    BTreeNode* child = node->children[index];
    BTreeNode* sibling = node->children[index + 1];

    child->keys.push_back(node->keys[index]);
    node->keys[index] = sibling->keys.front();
    sibling->keys.erase(sibling->keys.begin());

    if (!child->isLeaf) {
        child->children.push_back(sibling->children.front());
        sibling->children.erase(sibling->children.begin());
    }
}

// Fill child with less than degree-1 keys
void fill(BTreeNode* node, int index, int degree) {
    if (index != 0 && node->children[index - 1]->keys.size() >= degree) {
        borrowFromPrev(node, index);
    } else if (index != node->keys.size() && node->children[index + 1]->keys.size() >= degree) {
        borrowFromNext(node, index);
    } else {
        if (index != node->keys.size()) mergeNodes(node, index);
        else mergeNodes(node, index - 1);
    }
}

// Remove from leaf
void removeFromLeaf(BTreeNode* node, int index) {
    node->keys.erase(node->keys.begin() + index);
}

// Remove from non-leaf
void removeFromNonLeaf(BTreeNode* node, int index, int degree) {
    int key = node->keys[index];

    if (node->children[index]->keys.size() >= degree) {
        int pred = getPredecessor(node->children[index]);
        node->keys[index] = pred;
        removeNode(node->children[index], pred, degree);
    } else if (node->children[index + 1]->keys.size() >= degree) {
        int succ = getSuccessor(node->children[index + 1]);
        node->keys[index] = succ;
        removeNode(node->children[index + 1], succ, degree);
    } else {
        mergeNodes(node, index);
        removeNode(node->children[index], key, degree);
    }
}

// Remove key
void removeNode(BTreeNode* node, int key, int degree) {
    int index = 0;
    while (index < node->keys.size() && key > node->keys[index]) index++;

    if (index < node->keys.size() && key == node->keys[index]) {
        if (node->isLeaf) removeFromLeaf(node, index);
        else removeFromNonLeaf(node, index, degree);
    } else {
        if (node->isLeaf) {
            cout << "Key " << key << " not found in the tree.\n";
            return;
        }

        bool flag = (index == node->keys.size());
        if (node->children[index]->keys.size() < degree)
            fill(node, index, degree);

        if (flag && index > node->keys.size() - 1)
            removeNode(node->children[index - 1], key, degree);
        else
            removeNode(node->children[index], key, degree);
    }
}

// Wrapper remove
void removeKey(BTree* tree, int key) {
    if (!tree->root) {
        cout << "Tree is empty\n";
        return;
    }

    removeNode(tree->root, key, tree->degree);

    if (tree->root->keys.empty()) {
        BTreeNode* temp = tree->root;
        if (tree->root->isLeaf) tree->root = nullptr;
        else tree->root = tree->root->children[0];
        temp->children.clear();
        delete temp;
    }
}




void levelOrderTraversalByLevel(BTreeNode* root) {
    if (!root) return;

    std::queue<BTreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();  // Number of nodes at the current level

        for (int i = 0; i < levelSize; i++) {
            BTreeNode* node = q.front();
            q.pop();

            // Print all keys in the current node
            for (int key : node->keys)
                std::cout << key << " ";
            cout << "   ";  // Separate nodes for clarity

            // Enqueue children if not leaf
            if (!node->isLeaf) {
                for (BTreeNode* child : node->children)
                    q.push(child);
            }
        }

        cout << "\n";  // End of current level
    }
}


int main() {
    BTree* tree = new BTree(3);

    insert(tree, 10);
    insert(tree, 20);
    insert(tree, 5);
    insert(tree, 6);
    insert(tree, 12);
    insert(tree, 30);
    insert(tree, 7);
    insert(tree, 17);

    cout << "Traversal of the B-Tree: ";
    traverse(tree->root);
    cout << "\n";

    cout << "Searching keys 6 and 15:\n";
    cout << "6: " << (searchKey(tree->root, 6) ? "Found" : "Not Found") << "\n";
    cout << "15: " << (searchKey(tree->root, 15) ? "Found" : "Not Found") << "\n";

    removeKey(tree, 6);
    removeKey(tree, 13);
    removeKey(tree, 7);

    cout << "Traversal after deletions: ";
    traverse(tree->root);
    cout << "\n";


    cout<<"Level Order Traversal : "<<endl;
    levelOrderTraversalByLevel(tree->root);

    delete tree;
    return 0;
}
