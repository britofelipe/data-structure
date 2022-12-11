#include <iostream>
using namespace std;
#define COUNT 10

struct AVLTree {

    // Node struct
    struct Node{
        int data;
        Node *left, *right;

        Node(int element){
            data = element;
            left = nullptr; 
            right = nullptr;
        }
    };

    Node *root;

    // AVL Tree Constructor
    AVLTree() {
        root = nullptr;
        cout << "New tree allocated" << endl;
    }

    ~AVLTree() {
        cout << "Tree deallocated" << endl;
    }

    // Returns true if empty
    bool isEmpty(Node *root) {
        return(root == nullptr);
    }

    // Get node height (for balance purposes)
    int height(Node *node) {
        if(node == nullptr)
            return -1;

        // Recursive calculation of height
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if(leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }

    // Get the balance factor, that should be {-1, 0, 1}
    int balanceFactor(Node *node) {
        if(node == nullptr)
            return -1;
        else 
            return(height(node->left) - height(node->right));
    }

    // Balances the tree
    Node* balance(Node *root){

        int bf = balanceFactor(root); 
        // If the bf is lower than -1, then it's a right imbalance
        // If the bf is greater than 1, then it's a left imbalance

        // LEFT-LEFT IMBALANCE
        if(bf > 1 and balanceFactor(root->left) > 0) // i.e we are putting on the left of the left
            // return rightRotation(root);
            cout << "RL" << endl;

        // RIGHT-RIGHT IMBALANCE
        if(bf < -1 and balanceFactor(root->right) < 0) // i.e we are putting on the right of the right
            // return leftRotation(root);
            cout << "RL" << endl;

        // LEFT-RIGHT IMBALANCE
        if(bf > 1 and balanceFactor(root->right) > 0) // i.e we are putting on the right of the left
            // return rightRotation(root);
            cout << "RL" << endl;

        // RIGHT-LEFT  IMBALANCE
        if(bf < -1 and balanceFactor(root->left) < 0) // i.e we are putting on the left of the right
            cout << "RL" << endl;

        return root;
    }    

    // Left Rotation
    Node * leftRotation(Node *node) {
        
    }

    // Right Rotation
    Node * rightRotation(Node *node) {
        
    }

    Node * insert(Node *root, int element){

        // Making new node
        Node *newNode = new Node(element);

        // 1. If the tree is empty, then the root will be equal to the new node
        if(isEmpty(root)){
            root = newNode;
            return root;
        }
        
        // 2. If the tree is not empty, then it will be on the left or in the right
        // 2.1. In case the tree is on the left
        if(element < root->data){
            root->left = insert(root->left, element);
        }
        // 2.2. If the new element will be on the right of current node
        else if(element > root->data){
            root->right = insert(root->right, element);
        }

        // Checks if the tree is balanced
        root = balance(root);

        // Return the (new or same) root
        return root;
    }

    // Print the tree - utility
    void printUtil(Node* root, int space) {
        // Base case
        if (root == NULL)
            return;

        // Increase distance between levels
        space += COUNT;

        // Process right child first
        printUtil(root->right, space);

        // Print current node after space
        // count
        cout << endl;
        for (int i = COUNT; i < space; i++)
            cout << " ";
        cout << root->data << "\n";

        // Process left child
        printUtil(root->left, space);
    }

    // Print the tree
    void print() {
        // Pass initial space count as 0
        printUtil(this->root, 0);
    }

};

int main(){

    AVLTree tree;

    // Insert some elements in the tree
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 100);
    tree.root = tree.insert(tree.root, 200);
    // tree.root = tree.insert(tree.root, 250); 
    // tree.root = tree.insert(tree.root, 300);
    // tree.root = tree.insert(tree.root, 170);
    // tree.root = tree.insert(tree.root, 185);
    // tree.root = tree.insert(tree.root, 192);
    // tree.root = tree.insert(tree.root, 160);
    // tree.root = tree.insert(tree.root, 155);
    // tree.root = tree.insert(tree.root, 125);

    // Print the tree in a 2D format
    tree.print();

    // cout << tree.height(tree.root) << endl;
    // cout << tree.balanceFactor(tree.root) << endl;

    cout << "Press any key to continue... ";
    // getchar();

}