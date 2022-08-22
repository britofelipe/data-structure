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
        if (arr[i] % 2 == 1) { // Checks if it's an odd number
            for(int j = i+(arrSize/2); j< arrSize; j++) { // Replace if an even number from the second half
                if (arr[j] % 2 == 0) {
                    aux = arr[j];
                    arr[j] = arr[i];
                    arr[i] = aux;
                }
            }
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
