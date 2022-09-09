#include <iostream>

using namespace std;

void cocktailSort(int* arr, int arrSize){
    // The complexity is O(n²)
    bool swapped = true;
    int bottom = 0;
    int top = arrSize - 1;
    while(swapped){
        swapped = false;
        for(int i = bottom; i < top; i++){
            if(arr[i] > arr[i + 1]){
                int aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
                swapped = true;
            }
        }
        top--;
        for(int j = top; j > bottom; j--){
            if(arr[j] < arr[j - 1]){
                int aux = arr[j];
                arr[j] = arr[j- 1];
                arr[j - 1] = aux;
                swapped = true;
            }
        }
        bottom++;
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

    cocktailSort(arr, arrSize);

    // Print the array
    cout << "Rearranged array" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}
