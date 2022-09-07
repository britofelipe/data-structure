#include <iostream>

using namespace std;

int numberOfInversions(int* arr, int arrSize){
    int inversions = 0;
    for(int i = 0; i < arrSize; i++){
        for(int j = i + 1; j < arrSize; j++){
            if(i < j && arr[i] > arr[j]){
                inversions++;
            }
        }
    }
    return inversions;
}

int main()
{
    int arr[12] = { 1, 2, 26, 17, 20, 25, 31, 64, 71, 76, 100, 97};

    int arrSize = sizeof(arr)/sizeof(arr[0]);

    // Print the array
    cout << "Initial array" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    cout << "Number of necessary inversions: " << numberOfInversions(arr, arrSize);

    return 0;
}
