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
        deleteTree(root);
        root = nullptr;
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
        if(bf > 1 and balanceFactor(root->left) >= 0) // i.e we are putting on the left of the left
            return rightRotation(root);

        // RIGHT-RIGHT IMBALANCE
        if(bf < -1 and balanceFactor(root->right) <= 0) // i.e we are putting on the right of the right
            return leftRotation(root);
            
        // LEFT-RIGHT IMBALANCE
        if(bf > 1 and balanceFactor(root->left) < 0) {// i.e we are putting on the right of the left
            cout << "Right Left Rotation" << endl;
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }

        // RIGHT-LEFT IMBALANCE
        if(bf < -1 and balanceFactor(root->right) > 0) { // i.e we are putting on the left of the right
            cout << "Left Right Rotation" << endl;
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }

        return root;
    }    

    // Left Rotation
    Node * leftRotation(Node *A) {
        cout << "Left Rotation" << endl;
        //          A                                   B
        //     Ax        B              =>         A          C
        //           Bx     C                  Ax    Bx   Cx      Cy
        //              Cx     Cy

        Node *B = A->right;
        Node *Bx = B->left;

        A->right = Bx;
        B->left = A;

        return B;
    }

    // Right Rotation
    Node * rightRotation(Node *A) {
        cout << "Right Rotation" << endl;
        //                 A                                       B  
        //          B             Ay              =>        C               A
        //      C      By                               Cx     Cy      By       Ay
        //   Cx     Cy             

        Node *B = A->left;
        Node *By = B->right;

        A->left = By;
        B->right = A;

        return B;
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
        else if(element > root->data) {
            root->right = insert(root->right, element);
        } else{
            cout << "The element " << element << " is already on the Tree" << endl;
            return root;
        }

        // Checks if the tree is balanced
        root = balance(root);

        // Return the (new or same) root
        return root;
    }

    Node * remove(Node *root, int element) {
        // 1. Empty Tree
        if(root == nullptr){
            cout << "Value not found" << endl;
            return nullptr;
        } 

        // 2. Searches for the element
        else {
            if(root->data == element) {
                // 2.1. Nodes without children
                if(root->left == nullptr && root->right == nullptr){
                    delete(root);
                    return nullptr;
                }
                // 2.2. Nodes with children
                else {
                    // 2.2.1. Nodes with two children
                    if(root->left != nullptr && root->right != nullptr){
                        Node *temp = root->left;
                        while(temp->right != nullptr)
                            // Finding the predecessor
                            temp = temp->right;
                        root->data = temp->data;
                        temp->data = element;
                        root->left = remove(root->left, element);
                        return root;
                    }

                    // 2.2.2. Nodes with one children
                    else {
                        Node *temp;
                        if(root->left != nullptr)
                            temp = root->left;
                        else
                            temp = root->right;
                        delete(root);
                        return temp;
                    }

                }
            } 
            // Continues to do the search
            else {
                if(element < root->data)
                    root->left = remove(root->left, element);
                else
                    root->right = remove(root->right, element);
            }
        }

        // Checks if needs balance only for some nodes -> O(log n)
        root = balance(root);

        // Return (same or changed) root
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

    void deleteTree(Node *node) {
        if(node == nullptr) {
            return;
        }

        // Recursively delete
        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    }
};

int main(){

    AVLTree tree;

    // tree.root = tree.remove(tree.root, 50);

    // Insert some elements in the tree
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 100);
    tree.root = tree.insert(tree.root, 200);
    tree.root = tree.insert(tree.root, 250); 
    tree.root = tree.insert(tree.root, 300);
    tree.root = tree.insert(tree.root, 170);
    tree.root = tree.insert(tree.root, 185);
    tree.root = tree.insert(tree.root, 192);
    tree.root = tree.insert(tree.root, 160);
    tree.root = tree.insert(tree.root, 155);
    tree.root = tree.insert(tree.root, 125);

    tree.root = tree.insert(tree.root, 189);
    tree.root = tree.insert(tree.root, 144);
    tree.root = tree.insert(tree.root, 122);
    tree.root = tree.insert(tree.root, 225);

    tree.print();

    // tree.root = tree.remove(tree.root, 170);
    // tree.root = tree.remove(tree.root, 160);
    // tree.root = tree.remove(tree.root, 155);
    // tree.root = tree.remove(tree.root, 250); 
    // tree.root = tree.remove(tree.root, 300);
    // tree.root = tree.remove(tree.root, 125);
    // tree.root = tree.remove(tree.root, 192);
    // tree.root = tree.remove(tree.root, 50);
    // tree.root = tree.remove(tree.root, 100);
    // tree.root = tree.remove(tree.root, 200);
    // tree.root = tree.remove(tree.root, 185);
    // tree.root = tree.remove(tree.root, 1);
    
    // Print the tree in a 2D format

    // Remove elements of the tree:

    // tree.print();

    // cout << tree.height(tree.root) << endl;
    // cout << tree.balanceFactor(tree.root) << endl;

    cout << "Press any key to continue... ";
    getchar();

}