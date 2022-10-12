#include <iostream>
#include <stack>

using namespace std;

class Position{
    public:
        int row;
        int column;
};

class Stack{
    public:
        Position* arr;
        int maxSize;
        int top;
        int count; // number of elements in the stack

        // Constructor method, initializes the stack
        Stack(int arrSize){
            arr = new Position[arrSize];
            maxSize = arrSize;
            top = -1;
            count = 0;
        }

        // Insert an element at the top of the stack
        void push(Position position){
            if(count < maxSize){
                count++;
                top = ((top + 1) % maxSize);
                arr[top] = position;
            } else{
                cout << "The stack is full!" << endl;
            }
        }
        
        // Removes the element on the top of the stack
        Position pop(){
            if(count > 0){
                Position element = arr[top];
                arr[top].row = -1;
                arr[top].column = -1;

                top = ((top - 1) % maxSize);
                count--;
                return element;
            } else{
                cout << "The queue is empty!";
            }
        }

        // m é todo pilha vazia
        int empty(){
            return count == 0;
        }
};

int main() {
    int size = 10;

    Stack twoElements(size);

    Position position;
    Position test;

    cout << "Inserting new elements" << endl;
    for(int i = 0; i < size; i++) {
        position.row = i * i ;
        position.column = i * i * i ;
        twoElements.push(position);
    }
    cout << endl;

    test.row = 100;
    test.column = 100;

    twoElements.push(test);

    cout << "New elements inserted: " << endl;
    for(int i = 0; i < size; i++) {
        cout << "(" << twoElements.arr[i].row << ", " << twoElements.arr[i].column << "), ";
    }
    cout << endl;

    twoElements.pop();
    twoElements.pop();
    twoElements.pop();

    cout << "Elements removed: " << endl;
    for(int i = 0; i < size; i++) {
        cout << "(" << twoElements.arr[i].row << ", " << twoElements.arr[i].column << "), ";
    }
    cout << endl;

    twoElements.push(test);
    twoElements.push(test);

    cout << "New elements inserted: " << endl;
    for(int i = 0; i < size; i++) {
        cout << "(" << twoElements.arr[i].row << ", " << twoElements.arr[i].column << "), ";
    }
    cout << endl;

    for ( int i = 0; i < 5; i++){
        twoElements.pop();
    }
    cout << endl;

    cout << "Elements removed: " << endl;
    for(int i = 0; i < size; i++) {
        cout << "(" << twoElements.arr[i].row << ", " << twoElements.arr[i].column << "), ";
    }
    cout << endl;

     while (!twoElements.empty()){
       twoElements.pop();
    }

    cout << "The queue is empty: " << endl;
    for(int i = 0; i < size; i++) {
        cout << "(" << twoElements.arr[i].row << ", " << twoElements.arr[i].column << "), ";
    }
    cout << endl;
}