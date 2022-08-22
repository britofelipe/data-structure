#include <iostream>

using namespace std;

int main() {

    int arr[10] = {16, 19, 41, 8, 42, 39, 33, 22, 29, 48};

    int arrSize = sizeof(arr)/sizeof(arr[0]);

    cout << "Initial array: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    int aux = 0;
    int arrHalfSize = arrSize/2;

    for(int i = 0; i < arrHalfSize; i++) {
        aux = arr[arrSize-i-1];
        arr[arrSize-i-1] = arr[i];
        arr[i] = aux;
    }

    cout << endl;
    cout << "Rearranged array: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}
