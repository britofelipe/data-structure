#include <iostream>

using namespace std;

void bubbleSortOdd(int* arr, int arrSize){
    // The complexity is O(n²)
    bool swapped = true;
    while(swapped){
        swapped = false;
        for(int i = 1; i < arrSize - 1; i+=2){
            if(arr[i] > arr[i + 2]){
                int aux = arr[i];
                arr[i] = arr[i + 2];
                arr[i + 2] = aux;
                swapped = true;
            }
        }
    }
}

void bubbleSortEven(int* arr, int arrSize){
    // The complexity is O(n²)
    bool swapped = true;
    while(swapped){
        swapped = false;
        for(int i = 0; i < arrSize - 1; i+=2){
            if(arr[i] > arr[i + 2]){
                int aux = arr[i];
                arr[i] = arr[i + 2];
                arr[i + 2] = aux;
                swapped = true;
            }
        }
    }
}

int main()
{
    int arr[100];

    int arrSize = sizeof(arr)/sizeof(arr[0]);

    // Print and declare the array
    cout << "Initial array" << endl;
    for(int i = 0; i < arrSize; i++){
        arr[i] = rand()%100;
        cout << arr[i] << ", ";
    }
    cout << endl;

    bubbleSortOdd(arr, arrSize);

    // Print the array
    cout << "Rearranged array (Odd)" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    bubbleSortEven(arr, arrSize);

    // Print the array
    cout << "Rearranged array (Even)" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;


    return 0;
}
