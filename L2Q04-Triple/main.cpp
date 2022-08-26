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
        } else if (arr[i] % 3 == 1) {
            cout << "The remainder of " << arr[i] << " divided by 3 is 1" << endl;
        } else if (arr[i] % 3 == 2) {
            arr[i] = i * arr[i];
            arr[i] = arr[i]/3;
            arr[i] = arr[i] - 1;
        }
    }

    cout << endl;
    cout << "Rearranged array: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    // a) The loop occurs n (arrSize) + 1 times
    // b) The "Remainder 1 checker" happens n - x0 times
    // c) The total executions of the algorithm is 1 + n + 1 + x0(2) + x1(1) + x2(3) + n
    // => 2n + 2(x0) + x1 + 3(x2) + 2
    // d) Best case scenario: x1 = n, total executions = 3n + 2
    // Worst case scenario: x2 = n, total executions = 5n +2

    return 0;
}
