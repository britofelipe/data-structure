#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {16, 19, 22, 8, 42, 39, 33, 22, 29, 48};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    cout << "Initial array: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[i] == arr[j] ) {
                cout << "The number " << arr[i] << " is repeated" << endl;
            }
        }
    }

    return 0;
}
