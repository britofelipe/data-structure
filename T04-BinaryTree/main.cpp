// Implementation of Binary Tree

#include <iostream>
using namespace std;
#define COUNT 10

struct Node {
    
    int data;
    Node *left;
    Node *right;

};

struct BinaryTree {

    Node *root;

    BinaryTree() {
        root = nullptr;
    }

    void insert(int element) {
        
        // Making new node
        Node *newNode = new Node{
            element,
            nullptr,
            nullptr
        };

        if(isEmpty()){
            root = newNode;
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
    }

    bool belongsTo(int element){

        if(isEmpty()){
            return false;
        }

        Node *temp = root;
        while(temp != nullptr){
            if(element == temp->data){
                return true;
            } else if(element < temp->data){
                temp = temp->left;
            } else{
                temp = temp->right;
            }
        }

        return false;

    }

    void remove(int element){
        if(isEmpty()){
            cout << "The tree is empty" << endl;
        }

        Node *target = root;
        Node *up = nullptr;

        while(target != nullptr){
            if(element == target->data){
                break;
            } else if(element < target->data){
                up = target;
                target = target->left;
            } else{
                up = target;
                target = target->right;
            }
        }

        // Not found
        if(target == nullptr){
            cout << "This element is not on the tree" << endl;
        }       
        
        if(target->left == nullptr){
            if(up == nullptr)
                root = target->right;
            else if(target == up)
                up->left = target->right;
            else /* target == up->right */
                up->right = target->right;
        } else if(target->right == nullptr){
            if(up == nullptr)
                root = target->left;
            else if(target == up->left)
                up->left = target->right;
            else /* target == up->left */
                up->right = target->right;
        } else{
            Node *p = target->left;
            Node *cp = target;

            // Find predecessor
            while(p->right != nullptr){
                cp = p;
                p = p->right;
            }

            // Remove predecessor
            if(p == cp->left)
                cp->left = p->left;
            else /* p == cp->right */
                cp->right = p->left;

            p->left = target->left;
            p->right = target->right;
            if(up == nullptr)
                root = p;
            else if(target == up->left)
                up->left = p;
            else
                up->right = p;
        }
        delete target;
    }

    void removeBetter(int element){
        Node **up = &root;
        Node *target;

        for(;;){
            target = *up; // The pointer pointed by "up"
            if(target == nullptr)
                return;
            if(element == target->data)
                break;
            if(element < target->data)
                up = &target->left;
            else
                up = &target->right;
        } 
        if(target->left == nullptr){
            *up = target->right;
        }
    }

    void erase(Node *target){
        if(target == nullptr)
            return;
        erase(target->left);
        erase(target->right);
        delete target;
    }

    void printIncreasing(Node *target){
        if(target != nullptr){
            printIncreasing(target->left);
            cout << target->data << ", ";
            printIncreasing(target);
        }
    }

    void printHeights(){
        printHeight(root, 1);
    }

    void printHeight(Node *target, int deep){
        if(target != nullptr){
            cout << "Deep(" << target->data << ") = " << deep << endl;
            printHeight(target->left, deep + 1);
            printHeight(target->right, deep + 1);
        }
    }

    bool isEmpty(){
        return(root == nullptr);
    }
};

void print2DUtil(Node* root, int space) {
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(Node* root) {
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(15);
    tree.insert(20);
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(12);
    print2D(tree.root);

    tree.remove(5);
    print2D(tree.root);

    tree.printHeights();
}