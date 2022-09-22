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

    int queueSize = 100;
    int matrixSize = 10;

    PositionQueue positionsQueue(queueSize);

    Position position;

    int matrix[matrixSize][matrixSize];
    int distances[matrixSize][matrixSize];

    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++){
            matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++){
            distances[i][j] = -1;
        }
    }

    // Filling the matrix as the example goes
    matrix[0][8] = 1;
    matrix[0][9] = 1;
    matrix[4][4] = 1;
    matrix[4][5] = 1;
    matrix[5][3] = 1;
    matrix[5][4] = 1;
    matrix[5][5] = 1;
    matrix[5][6] = 1;
    matrix[6][5] = 1;
    matrix[9][0] = 1;
    matrix[9][4] = 1;
    matrix[9][5] = 1;
    matrix[9][6] = 1;

    cout << "Initial matrix M: " << endl; cout << endl;
    for(int i = 0; i < matrixSize; i++){
        cout << "| ";
        for(int j = 0; j < matrixSize; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;

    // Gathering the 1's positions
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++){
            if(matrix[i][j] == 1){
                distances[i][j] = 0;
                position.row = i;
                position.column = j;
                positionsQueue.push(position);
            }
        }
    }

    // Construction of Distances Matrix
    while(!positionsQueue.empty()){
        position = positionsQueue.pop();
        if(position.row - 1 >= 0){
            if(distances[position.row - 1][position.column] == -1){
                Position aux = position;
                distances[position.row - 1][position.column] = distances[position.row][position.column] + 1;
                aux.row--;
                positionsQueue.push(aux);
            }
        }
        if(position.column - 1 >= 0){
            if(distances[position.row][position.column - 1] == -1){
                Position aux = position;
                distances[position.row][position.column - 1] = distances[position.row][position.column] + 1;
                aux.column--;
                positionsQueue.push(aux);
            }
        }
        if(position.column + 1 < matrixSize){
            if(distances[position.row][position.column + 1] == -1){
                Position aux = position;
                distances[position.row][position.column + 1] = distances[position.row][position.column] + 1;
                aux.column++;
                positionsQueue.push(aux);
            }
        }
        if(position.row + 1 < matrixSize){
            if(distances[position.row + 1][position.column] == -1){
                Position aux = position;
                distances[position.row + 1][position.column] = distances[position.row][position.column] + 1;
                aux.row++;
                positionsQueue.push(aux);
            }            
        }
    }

    cout << "Distances Matrix: " << endl; cout << endl;
    for(int i = 0; i < matrixSize; i++){
        cout << "| ";
        for(int j = 0; j < matrixSize; j++){
            cout << distances[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;

}