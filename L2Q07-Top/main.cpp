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
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1])

        cout << arr[i] << endl;
    }

    return 0;
}
