#include <iostream>

using namespace std;

int main()
{

    int arr[11] = {2, 5, 3, 6, 2, 7, 1, 10, 4, 16, 0};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    cout << "Initial array: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    int lastTop = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            if (arr[i] > lastTop) {
                lastTop = arr[i];
                cout << arr[i] << endl;
            } else {
                break;
            }
        }
    }

    return 0;
}
