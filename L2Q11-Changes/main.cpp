#include <iostream>

using namespace std;

int findMinimumOfArray(int arr[], int arrSize) {
    int minim = arr[0];
    int index = 0;

    for(int i = 0; i < arrSize; i++) {
        if (arr[i] < minim) {
            minim = arr[i];
            index = i;
        }
    }
    return index;
}

int findMaximumOfArray(int arr[], int arrSize) {
    int maxim = 0;
    int index = 0;

    for(int i = 0; i < arrSize; i++) {
        if (arr[i] > maxim) {
            maxim = arr[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    int arrL[10] = {16, 19, 41, 8, 42, 39, 33, 22, 29, 48};
    int arrLSize = sizeof(arrL)/sizeof(arrL[0]);
    int arrV[10] = {2, 5, 17, 9, 35, 19, 23, 72, 91, 44};
    int arrVSize = sizeof(arrV)/sizeof(arrV[0]);

    cout << "Initial array 1: ";
    for(int i = 0; i < arrLSize; i++) {
        cout << arrL[i] << ", ";
    }
    cout << endl;

    cout << "Initial array 2: ";
    for(int i = 0; i < arrVSize; i++) {
        cout << arrV[i] << ", ";
    }
    cout << endl;

    int aux = 0;
    int indexMinL = 0;
    int indexMaxV = 0;
    int minL = 0;
    int maxV = 0;

    do {
        indexMinL = findMinimumOfArray(arrL, arrLSize);
        indexMaxV = findMaximumOfArray(arrV, arrVSize);

        minL = arrL[indexMinL];
        maxV = arrV[indexMaxV];

        aux = arrL[indexMinL];
        arrL[indexMinL] = arrV[indexMaxV];
        arrV[indexMaxV] = aux;

    } while (minL < maxV);

    cout << "Final array 1: ";
    for(int i = 0; i < arrLSize; i++) {
        cout << arrL[i] << ", ";
    }
    cout << endl;

    cout << "Final array 2: ";
    for(int i = 0; i < arrVSize; i++) {
        cout << arrV[i] << ", ";
    }
    cout << endl;

    // Maximum number of changes: n
    // Maximum number of steps: an² + bn + c

    return 0;
}
