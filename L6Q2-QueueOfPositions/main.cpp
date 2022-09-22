#include <iostream>

using namespace std;

class Position{
    public:
        int row;
        int column;
};

class PositionQueue{
    public:
        Position* arr;
        int maxSize;
        int front;
        int rear;
        int count;

        // Constructor method, initializes the queue
        PositionQueue(int arrSize){
            arr = new Position[arrSize]; // Creates the vector with desired size
            maxSize = arrSize;
            front = 0; // Beggining of the queue
            rear = -1; // End of the queue
            count = 0; // Number of elements
        }

        // Insert an element at the back of the queue
        void push(Position position){
            if(count < maxSize){
                count++;
                rear = ((rear + 1) % maxSize);
                arr[rear] = position;
            } else{
                cout << "The queue is full!" << endl;
            }
        }

        // Removes an element from the front of the queue
        Position pop(){
            if(count > 0){
                Position element = arr[front];
                arr[front].row = -1;
                arr[front].column = -1;

                front = ((front + 1) % maxSize);
                count--;
                return element;
            } else{
                cout << "The queue is empty!";
            }
        }

        // Empty queue method
        int empty(){
            return count == 0;
        }
};

int main() {

    int size = 10;

    PositionQueue twoElements(size);

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