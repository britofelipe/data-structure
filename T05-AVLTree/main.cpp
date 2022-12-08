#include <iostream>
using namespace std;
#define COUNT 10

struct AVLTree {

    struct Node {

        int data, height;
        Node *left, *right;

        Node(int data){
            this->data = data;
            height = 1;
            left = nullptr;
            right = nullptr;
        }

    };

    Node *root;

    AVLTree() {
        root = nullptr;
        cout << "New tree allocated" << endl;
    }

    ~AVLTree() {
        cout << "Tree deallocated" << endl;
    }

    // Returns true if empty
    bool isEmpty(Node *root){
        return(root == nullptr);
    }

    Node * insert(Node *root, int element){

        // Making new node
        Node *newNode = new Node(element);

        if(isEmpty(root)){
            return (new Node(element));
        } else{
            Node *temp = root;
            for(;;) { // while true
                if(newNode->data < temp->data){
                    if(temp->left == nullptr){
                        temp->left = newNode;
                        break;
                    } else{
                        temp = temp->left;
                    }
                } else{
                    if(temp->right == nullptr){
                        temp->right = newNode;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }

        // We need to find the new height of each node between the root and inserted node
        root->height = max(height(root->left), height(root->right)) + 1;

        // Checks if the tree is balanced
        root = balance(root);

        // Return the (new or same) root
        return root;
    }

    // Removes an element from the tree
    Node * remove(Node *root, int element) {
        // TODO
    }

    // Get node height
    int height(Node *node){
        if(node == nullptr){
            return 0;
        }

        return node->height;

        // Recursive calculation of height
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if(leftHeight > rightHeight){
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }

    // Get the maximum of two integers (to get balance factor)
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    // Balances the tree
    Node* balance(Node *root){

        int bf = balanceFactor(root); 
        // If the bf is lower than -1, then it's a right imbalance
        // If the bf is greater than 1, then it's a left imbalance

        // LEFT-LEFT IMBALANCE
        if(bf > 1 and balanceFactor(root->left) <= 0) // i.e we are putting on the left of the left
            root = LeftLeftRotation(root);

        // RIGHT-RIGHT IMBALANCE
        if(bf < -1 and balanceFactor(root->right) >= 0) // i.e we are putting on the right of the right
            root = RightRightRotation(root);

        // LEFT-RIGHT IMBALANCE
        if(bf > 1 and balanceFactor(root->right) > 0) // i.e we are putting on the right of the left
            root = LeftRightRotation(root);

        // RIGHT-LEFT  IMBALANCE
        if(bf < -1 and balanceFactor(root->left) < 0) // i.e we are putting on the left of the right
            root = RightLeftRotation(root);

        return root;
    }

    // Get the balance factor, that should be {-1, 0, 1}
    int balanceFactor(Node *node){
        if(node == nullptr){
            return -1;
        } else {
            return(height(node->left) - height(node->right));
        }
    }

    // LL Rotation
    Node * LeftLeftRotation(Node *node){
        cout << "LL Imbalance" << endl;
    }

    // LR Rotation
    Node * LeftRightRotation(Node *node){

    }

    // RR Rotation
    Node * RightRightRotation(Node *node){
        cout << "RR Imbalance" << endl;
    }

    // RL Rotation
    Node * RightLeftRotation(Node *node){

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
    tree.root = tree.insert(tree.root, 250); 
    tree.root = tree.insert(tree.root, 300);
    tree.root = tree.insert(tree.root, 170);
    tree.root = tree.insert(tree.root, 185);
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

    cout << tree.root->height << endl;

}