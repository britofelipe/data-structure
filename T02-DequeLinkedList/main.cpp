// Implementation of Deque using linked list

#include <iostream>
using namespace std;

class DequeInt {
    
    // Node struct -> each deque has 0 to multiple nodes
    struct Node {
        
        int data;
        Node *prev;
        Node *next;

    };

    // Each deque has it's left (front) and back (right)
    Node *left; // null
    Node *right; // null
    int dequeSize;
    
    public:

        int getLeft(){
            if(isEmpty()){
                return -1;
            }
            return left->data;
        }

        int getRight(){
            if(isEmpty()){
                return -1;
            }
            return right->data;
        }

        // Deque constructor - initializes the Deque with nullptr and no data
        DequeInt(){
            left = nullptr;
            right = nullptr;
            dequeSize = 0;
            cout << "New deque allocated" << endl;
        }

        // Deconstructor
        ~DequeInt(){
            cout << "Deque deallocated" << endl;
        }

        void insertLeft(int element) {

            Node *newNode = new Node;

            // The newNode will be a node with element inside
            newNode->data = element;

            // FIRST CASE: left (and right) is empty
            if(left == nullptr){
                // Puting left and right to be the newNode -> they will be pointing to the same place
                left = newNode;
                right = newNode;

                // Both previous and next will be null, since the deque is only one element long
                newNode->prev = nullptr;
                newNode->next = nullptr;
            } else{
                // The newNode will be the "new" left
                left->prev = newNode;
                newNode->next = left;

                left = newNode;

                newNode->prev = nullptr;
            }
            // Increase size by 1
            dequeSize++;
        }

        void insertRight(int element) {

            Node *newNode = new Node;

            // The newNode will be a node with element inside
            newNode->data = element;

            // FIRST CASE: right (and left) is empty
            if(right == nullptr){
                // Puting right and left to be the newNode -> they will be pointing to the same place
                right = newNode;
                left = newNode;

                // Both previous and next will be null, since the deque is only one element long
                newNode->prev = nullptr;
                newNode->next = nullptr;
            } else{
                // The newNode will be the "new" right
                right->next = newNode;
                newNode->prev = right;

                right = newNode;

                newNode->next = nullptr;
            }
            // Increase size by 1
            dequeSize++;
        }

        void deleteLeft() {
            if(isEmpty()){
                cout << "The deque is empty" << endl;
            } else if(right == left){
                right = left = nullptr;
            } else{
                left = left->next;
                left->prev = nullptr;
            }
            dequeSize--;
        }

        void deleteRight() {
            if(isEmpty()){
                cout << "The deque is empty" << endl;
            } else if(right == left){
                right = left = nullptr;
            } else{
                right = right->prev;
                right->next = nullptr;
            }
            dequeSize--;
        }

        void deleteDeque(){
            while(right != nullptr){
                deleteRight();
            }
        }

        int size() {
            return dequeSize;
        }

        bool isEmpty(){
            return (left==nullptr); // right == nullptr
        }

        void print(){           
            if(isEmpty()){
                cout << "The deque is empty" << endl;
            }

            Node *temp = left;

            while(temp != nullptr){
                cout << temp->data << ", ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    
    DequeInt deque;

    deque.insertRight(1);

    deque.insertRight(2);

    deque.insertRight(3);

    deque.insertRight(4);

    deque.print();

    deque.deleteRight();
    deque.print();

    deque.deleteLeft();
    deque.print();

    deque.deleteLeft();
    deque.print();

    deque.insertRight(4);
    deque.insertRight(5);
    deque.insertRight(6);
    deque.insertRight(7);
    deque.insertRight(8);
    deque.insertRight(9);
    deque.insertRight(10);
    deque.print();
    
    deque.deleteDeque();
    deque.print();
}