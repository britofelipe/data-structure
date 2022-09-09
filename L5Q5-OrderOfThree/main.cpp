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

void orderOfThreeInverted(int* arr, int arrSize){
    for(int i = 0; i < arrSize; i+=3){
        int aux = arr[i];
        arr[i] = arr[i + 2];
        arr[i + 2] = aux;
    }
}

int main()
{
    int arr[21];

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

    orderOfThreeInverted(arr, arrSize);

    // Print the array
    cout << "Array in order of three array" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ", ";
        if((i + 1) % 3 == 0){
            cout << '\t';
        }
    }
    cout << endl;
}
