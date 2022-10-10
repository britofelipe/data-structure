#include <iostream>

using namespace std;

class Position{
    public:
        int row;
        int column;
};

class PositionStack{
    public:
        Position* arr;
        int maxSize;
        int top;
        int count; // number of elements in the stack

        // Constructor method, initializes the stack
        PositionStack(int arrSize){
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
                cout << "The queue is full!" << endl;
            }
        }
        
        // Removes the element on the top of the stack
        Position pop(){
            // TODO
        }

        // m é todo pilha vazia
        int empty(){
            return count == 0;
        }
};

int main() {
    int size = 10;

    PositionStack twoElements(size);

    Position position;
    Position test;
}