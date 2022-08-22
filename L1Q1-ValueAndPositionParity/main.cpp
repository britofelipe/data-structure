#include <iostream>

using namespace std;

int main() {

    int arr[10] = {16, 19, 41, 8, 42, 39, 33, 22, 29, 48};

    int arrSize = sizeof(arr)/sizeof(arr[0]);

    cout << "Initial array: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }

    int aux = 0;
    for(int i = 0; i < arrSize; i++) {
        if ((i + 1) % 2 == 1 && !(arr[i] % 2 == 1)) { // Checks if it's an odd index with an odd number
            aux = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = aux;
        } else if ((i + 1) % 2 == 0 && !(arr[i] % 2 == 0)) { // Checks if it's an even index with an even number
            aux = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = aux;
        }
    }

    cout << endl;
    cout << "Rearranged array: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }

    cout << endl;
    return 0;
}
