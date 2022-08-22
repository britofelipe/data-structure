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
    int j = 0;
    bool replaced = false;

    for(int i = 0; i < arrSize; i++) {
        // Checks if it's an odd number
        if (arr[i] % 2 == 1) {

            j = i;
            // Looks for the next even number to replace with the odd number
            while(j < arrSize && replaced == false) {

                // Checks if it's even
                if (arr[j] % 2 == 0) {

                    // Store the even number
                    aux = arr[j];

                    // Making the array "move" to the right
                    int n = j;
                    while(n > i) {
                        arr[n] = arr[n-1];
                        n--;
                    }

                    // Puts the even number on its place
                    arr[i] = aux;
                    replaced = true;
                }
                j++;
            }
        }
        replaced = false;
    }

    cout << endl;
    cout << "Rearranged array: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }

    cout << endl;
    return 0;
}
