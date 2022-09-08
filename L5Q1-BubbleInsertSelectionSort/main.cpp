#include <iostream>

using namespace std;

void bubbleSort(int* arr, int arrSize){
    // The complexity is O(n²)
    bool swapped = true;
    while(swapped){
        swapped = false;
        for(int i = 0; i < arrSize - 1; i++){
            if(arr[i] > arr[i + 1]){
                int aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
                swapped = true;
            }
        }
    }
}

void bubbleSortAlternative(int* arr, int arrSize){
    // The complexity is O(n²)
    for(int i = 0; i < arrSize - 1; i++){
        for(int j = 0; j < arrSize - 1; j++){
            if(arr[j] > arr[j + 1]){
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

void selectionSort(int* arr, int arrSize){
    // The complexity is O(n²)
    for(int i = 0; i < arrSize - 1; i++){
        int pminimum = i;
        // For each of the unsorted elements
        for(int j = i; j < arrSize - 1; j++){
            if(arr[j] < arr[pminimum]){
                pminimum = j;
            }
        }
        int aux = arr[pminimum];
        arr[pminimum] = arr[i];
        arr[i] = aux;
    }
}

void selectionSortAlternative(int* arr, int arrSize){
    // The complexity is O(n²)
    for(int i = arrSize - 1; i >= 0; i--){
        int pmax = i;
        // For each of the unsorted elements
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[pmax]){
                pmax = j;
            }
        }

    }
}

void insertionSort(int* arr, int arrSize){
    // The complexity is O(n²)
    for(int i = 1; i < arrSize; i++){
        if(arr[i] < arr[i - 1]){
            int aux = arr[i];
            int j = i - 1;
            while(arr[j] > aux){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = aux;
        }
    }
}

int main()
{
    int arr[10];

    int arrSize = sizeof(arr)/sizeof(arr[0]);

    // Print and declare the array
    cout << "Initial array" << endl;
    for(int i = 0; i < arrSize; i++){
        arr[i] = rand()%100;
        cout << arr[i] << ", ";
    }
    cout << endl;

    insertionSort(arr, arrSize);

    // Print the array
    cout << "Rearranged array" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}
