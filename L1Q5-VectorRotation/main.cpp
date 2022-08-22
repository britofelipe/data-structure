#include <iostream>

using namespace std;

int main() {

    int arr[10] = {16, 39, 10, 50};

    int arrSize = sizeof(arr)/sizeof(arr[0]);

    cout << "Initial array: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    int numberOfElements = 0;

    // Counting the number of non null elements
    for(int i = 0; i < arrSize; i++) {
        if (arr[i] != 0) {
            numberOfElements++;
        }
    }

    int aux = arr[numberOfElements-1];

    // Rotating the vector
    for(int i = (numberOfElements - 1); i >= 0; i--) {
        arr[i] = arr[i-1];
    }

    arr[0]=aux;

    cout << endl;
    cout << "Rearranged array: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    cout << "Number of elements: " << numberOfElements << endl;

    return 0;
}
