#include <iostream>

using namespace std;

class Queue{
    public:
        int* arr;
        int maxSize;
        int front;
        int rear;
        int count;

        // Constructor method, initializes the queue
        Queue(int arrSize){
            arr = new int[arrSize]; // Creates the vector with desired size
            maxSize = arrSize;
            front = 0; // Beggining of the queue
            rear = -1; // End of the queue
            count = 0; // Number of elements
        }

        // Insert an element at the back of the queue
        void push(int newElement){
            if(count < maxSize){
                count++;
                rear = ((rear + 1) % maxSize);
                arr[rear] = newElement;
            } else{
                cout << "The queue is full!" << endl;
            }
        }

        // Removes an element from the front of the queue
        int pop(){
            if(count > 0){
                int element = arr[front];
                arr[front] = -1;
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

    int size = 20;

    Queue integers(size);

    cout << "Inserting new elements" << endl;
    for(int i = 0; i < size; i++) {
        integers.push(i);
    }
    cout << endl;
    
    integers.push(20);
    cout << "New elements inserted: " << endl;
    for(int i = 0; i < size; i++) {
        cout << integers.arr[i] << ", ";
    }
    cout << endl;

    cout << integers.pop() << endl;
    cout << integers.pop() << endl;
    cout << integers.pop() << endl;
    integers.push(20);
    integers.push(21);
    integers.push(22);
    integers.push(23);
    integers.push(24);

    cout << "New elements inserted: " << endl;
    for(int i = 0; i < size; i++) {
        cout << integers.arr[i] << ", ";
    }
    cout << endl;

    cout << integers.pop() << endl;
    cout << integers.pop() << endl;

    cout << "Elements removed: " << endl;
    for(int i = 0; i < size; i++) {
        cout << integers.arr[i] << ", ";
    }
    cout << endl;

    for ( int i = 0; i < 5; i++){
        cout << integers.pop() << ", ";
    }
    cout << endl;

    cout << "Elements removed: " << endl;
    for(int i = 0; i < size; i++) {
        cout << integers.arr[i] << ", ";
    }
    cout << endl;

    while (!integers.empty()){
        cout << integers.pop() << ", ";
    }

    cout << "Elements removed: " << endl;
    for(int i = 0; i < size; i++) {
        cout << integers.arr[i] << ", ";
    }
    cout << endl;
    
}