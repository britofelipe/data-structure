#include <iostream>

using namespace std;

void bubbleSortHalves(int* arr, int arrSize){
    // The complexity is O(n²)
    bool swapped = true;
    while(swapped){
        swapped = false;
        for(int i = 0; i < (arrSize)/2 - 1; i++){
            if(arr[i] > arr[i + 1]){
                int aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
                swapped = true;
            }
        }
    }
    do {
        swapped = false;
        for(int i = arrSize/2; i < arrSize - 1; i++){
            if(arr[i] > arr[i + 1]){
                int aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
                swapped = true;
            }
        }
    } while(swapped);
}

void mergeHalves(int* arr, int arrSize, int* arrMerged){
    int k = 0;
    int i = 0;
    int j = arrSize/2;
    while(k < arrSize){
        if(arr[i] < arr[j] && i < arrSize/2) {
            arrMerged[k] = arr[i];
            i++;
        } else if(j < arrSize){
            arrMerged[k] = arr[j];
            j++;
        }
        k++;
    }

}

int main()
{
    int arr[20];

    int arrSize = sizeof(arr)/sizeof(arr[0]);

    // Print and declare the array
    cout << "Initial array" << endl;
    for(int i = 0; i < arrSize; i++){
        arr[i] = rand()%100;
        cout << arr[i] << ", ";
    }
    cout << endl;

    bubbleSortHalves(arr, arrSize);

    // Print the array
    cout << "Rearranged array" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    // Print and declare the auxiliar array
    int arrMerged[20];

    cout << "Initial merged array" << endl;
    for(int i = 0; i < arrSize; i++){
        arrMerged[i] = 0;
        cout << arrMerged[i] << ", ";
    }
    cout << endl;

    mergeHalves(arr, arrSize, arrMerged);

    // Print the array
    cout << "Rearranged merged array" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arrMerged[i] << ", ";
    }
    cout << endl;

    // In worst case scenario, we have (n/2)² + (n/2)² + n operations

    return 0;
}
