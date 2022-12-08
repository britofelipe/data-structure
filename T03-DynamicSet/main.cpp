// Implementation of Dynamic Set using linked list

#include <iostream>
using namespace std;

class DoubleSet
{
    // Node struct -> each set has 0 to multiple nodes
    struct Node {
        
        double data;
        Node *prev;
        Node *next;

    };

    // Each dinamic set has it's left (front) and back (right)
    Node *left; // null
    Node *right; // null
    int setSize;

    public:

        double getLeft(){
            if(isEmpty()){
                return -1;
            }
            return left->data;
        }

        double getRight(){
            if(isEmpty()){
                return -1;
            }
            return right->data;
        }

        bool belongsTo(double element) {
            if(isEmpty()){
                cout << "The set is empty" << endl;
            } else{
                Node *temp = left;

                while(temp != nullptr){
                    if(temp->data == element)
                        return true;
                    temp = temp->next;
                }
                return false;
            }
        }

        // set constructor - initializes the set with nullptr and no data
        DoubleSet(){
            left = nullptr;
            right = nullptr;
            setSize = 0;
            cout << "New set allocated" << endl;
        }

        // Deconstructor
        ~DoubleSet(){
            cout << "Set deallocated" << endl;
        }

        void insertLeftWithoutTesting(double element) {

            Node *newNode = new Node;

            // The newNode will be a node with element inside
            newNode->data = element;

            // FIRST CASE: left (and right) is empty
            if(left == nullptr){
                // Puting left and right to be the newNode -> they will be pointing to the same place
                left = newNode;
                right = newNode;

                // Both previous and next will be null, since the set is only one element long
                newNode->prev = nullptr;
                newNode->next = nullptr;
            } else{
                // The newNode will be the "new" left
                left->prev = newNode;
                newNode->next = left;

                left = newNode;

                newNode->prev = nullptr;
            }
            // Increase setSize by 1
            setSize++;
        }

        void insertLeft(double element){
            if(!belongsTo(element)){
                insertLeftWithoutTesting(element);
            }
            else{
                cout << "The element is already on the set" << endl;
            }
        }

        void insertRight(double element){
            if(!belongsTo(element)){
                insertRightWithoutTesting(element);
            }
            else{
                cout << "The element is already on the set" << endl;
            }
        }

        void insertRightWithoutTesting(int element) {

            Node *newNode = new Node;

            // The newNode will be a node with element inside
            newNode->data = element;

            // FIRST CASE: right (and left) is empty
            if(right == nullptr){
                // Puting right and left to be the newNode -> they will be pointing to the same place
                right = newNode;
                left = newNode;

                // Both previous and next will be null, since the set is only one element long
                newNode->prev = nullptr;
                newNode->next = nullptr;
            } else{
                // The newNode will be the "new" right
                right->next = newNode;
                newNode->prev = right;

                right = newNode;

                newNode->next = nullptr;
            }
            // Increase setSize by 1
            setSize++;
        }

        void deleteLeft() {
            if(isEmpty()){
                cout << "The set is empty" << endl;
            } else if(right == left){
                right = left = nullptr;
            } else{
                left = left->next;
                left->prev = nullptr;
            }
            setSize--;
        }

        void deleteRight() {
            if(isEmpty()){
                cout << "The set is empty" << endl;
            } else if(right == left){
                right = left = nullptr;
            } else{
                right = right->prev;
                right->next = nullptr;
            }
            setSize--;
        }

        void preciseDelete(double element){
            if(isEmpty()){
                cout << "The set is empty" << endl;
            } else{
                Node *temp = left;

                if (temp->data == element){
                    // Checks if the set is one element long
                    if(right == left){
                        right = left = nullptr;
                        return;
                    } else{
                        left = left->next;
                        left->prev = nullptr;
                        return;
                    }
                }
                // Looks for the element in the set
                while(temp != nullptr){
                    if(temp->data == element)
                        break;
                    temp = temp->next;
                }
                // If the element is the last one, the process is different
                if(temp->next == nullptr){
                    right = right->prev;
                    right->next = nullptr;
                    return;
                } else{
                    // Making a link between temp->next and temp-> prev
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                    temp = nullptr;
                }
            }
        }

        void deleteSet(){
            while(right != nullptr){
                deleteRight();
            }
        }

        int getSize() {
            return setSize;
        }

        bool isEmpty(){
            return (left==nullptr); // right == nullptr
        }

        void print(){           
            if(isEmpty()){
                cout << "The set is empty" << endl;
            } else{
                Node *temp = left;

                while(temp != nullptr){
                    cout << temp->data << ", ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
};

int main() {
    DoubleSet set;

    set.insertRightWithoutTesting(1);

    set.insertRightWithoutTesting(2);

    set.insertRightWithoutTesting(3);

    set.insertRightWithoutTesting(4);

    set.print();

    set.deleteRight();
    set.print();

    set.deleteLeft();
    set.print();

    set.deleteLeft();
    set.print();

    set.insertRightWithoutTesting(4);
    set.insertRightWithoutTesting(5);
    set.insertRightWithoutTesting(6);
    set.insertRightWithoutTesting(7);
    set.insertRightWithoutTesting(8);
    set.insertRightWithoutTesting(9);
    set.insertRightWithoutTesting(10);
    set.print();
    
    set.insertLeft(3);
    set.insertLeft(2);
    set.insertLeft(1);
    set.insertLeft(10);

    set.print();

    set.preciseDelete(1);
    set.print();

    set.preciseDelete(5);
    set.print();

    set.preciseDelete(3);
    set.print();

    set.preciseDelete(10);
    set.print();
    set.preciseDelete(9);
    set.print();

    set.preciseDelete(2);
    set.print();

    set.preciseDelete(6);
    set.print();

    set.preciseDelete(7);
    set.print();

    set.preciseDelete(4);
    set.print();

    set.preciseDelete(8);
    set.print();
}
