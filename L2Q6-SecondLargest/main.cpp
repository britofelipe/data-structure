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

    int maxim = 0;
    int secondMaxim = 0;

    if (arr[0] > arr[1]) {
        maxim = arr[0];
        secondMaxim = arr[1];
    } else {
        maxim = arr[1];
        secondMaxim = arr[0];
    }

    for (int i = 2; i < arrSize; i++) {
        if (arr[i] > maxim) {
            secondMaxim = maxim;
            maxim = arr[i];
        } else if(arr[i] > secondMaxim) {
            secondMaxim = arr[i];
        }
    }

    cout << secondMaxim << endl;

    return 0;
}
