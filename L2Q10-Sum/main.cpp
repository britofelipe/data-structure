#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {16, 19, 41, 8, 42, 39, 33, 22, 29, 48};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    int k = 81;

    cout << "Initial array: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[i] + arr[j] == k) {
                cout << "The number " << k << " is the sum of " << arr[i] << " + " << arr[j] << "." << endl;
            }
        }
    }

    return 0;
}
