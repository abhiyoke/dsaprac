#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isThreaded = false;
    return newNode;
}

// Function to perform inorder traversal of threaded BST
void inorderTraversal(Node* root){
  Node* curr=root;
    while(curr!=nullptr){
        while(curr->left!=nullptr){
            curr=curr->left;
        }
        cout<<curr->data<<" ";
        while(curr->isThreaded and curr->right!=nullptr){
            curr=curr->right;
            cout<<curr->data<<" ";
        }
        curr=curr->right;
    }
}

// Function to convert BST to TBT
void convertToThreadedBST(Node* root, Node** prev) {
    if (root == NULL)
        return;

    // Convert left subtree
    convertToThreadedBST(root->left, prev);

    // If the previous node is NULL, it means the current node is the first node (leftmost node)
    if (*prev == NULL)
        (*prev) = root;
    else {
        // If the previous node's right pointer is NULL, make it point to the current node
        if ((*prev)->right == NULL) {
            (*prev)->right = root;
            (*prev)->isThreaded = true;
        }
    }

    // Update the previous node
    (*prev) = root;

    // Convert right subtree
    convertToThreadedBST(root->right, prev);
}

int main() {
    // Create a binary search tree
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    // Convert the BST to TBT
    Node* prev = NULL;
    convertToThreadedBST(root, &prev);

    // Perform inorder traversal on TBT
    std::cout << "Inorder Traversal of Threaded BST: ";
    inorderTraversal(root);

    return 0;
}
