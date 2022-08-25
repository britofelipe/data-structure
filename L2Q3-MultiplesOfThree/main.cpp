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

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 3 == 0) {
            arr[i] = arr[i] / 3;
            arr[i] = arr[i] * arr[i];
        }
    }

    cout << endl;
    cout << "Rearranged array: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    // a) The incrementation occurs n (arrSize) times
    // b) The division by 3 occurs "d" times
    // c) The total executions of the algorithm is 1 + n(d(2)+1) + 1 = 2 + 2dn + n times
    // d) Worst case scenario: n = d, total executions = 2n^2 + n + 2

    return 0;
}
