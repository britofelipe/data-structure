#include <iostream>

using namespace std;

int main()
{

    int arr[10] = {16, 19, 41, 8, 42, 39, 33, 22, 29, 48};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    cout << "Initial array: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    int maxim, minim = arr[0];

    for (int i = 1; i < arrSize; i++) {
        if (arr[i] > maxim) {
            maxim = arr[i];
        }
        if (arr[i] < minim) {
            minim = arr[i];
        }
    }

    cout << maxim << endl;
    cout << minim << endl;

    return 0;
}
