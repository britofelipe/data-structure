#include <iostream>

using namespace std;

void addNumber(int* arr, int arrSize, int number){
    int i = 0;
    int j = arrSize - 1;

    while (j - i > 1){
        int half = (i + j)/2;

        if(arr[half] == number){
            i = half;
            j = half + 1;
        } else {
            if(number < arr[half]){
                j = half;
            } else {
                i = half;
            }
        }
    }

    for(int k = arrSize - 1; k > i; k--){
        arr[k + 1] = arr[k];
    }

    arr[j] = number;
}

int binarySearch(int* arr, int arrSize, int number){
    int i = 0;
    int j = arrSize - 1;

    while (i <= j){
        int half = (i + j)/2;
        if(arr[half] == number){
            return half;
        } else {
            if(arr[half] < number) {
                i = half + 1;
            } else {
                j = half - 1;
            }
        }
    }
}
void removeNumber(int* arr, int arrSize, int number){
    int index = binarySearch(arr, arrSize, number);

    while(index < arrSize){
        arr[index] = arr[index + 1];
        index++;
    }
}

int main()
{
    int arr[20] = { 1, 2, 4, 17, 20, 25, 31, 64, 71, 76, 84, 97};

    int arrSize = sizeof(arr)/sizeof(arr[0]);

    // Print the array
    cout << "Initial array" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    addNumber(arr, arrSize, 3);


    // Print the array
    cout << "Rearranged array" << endl;
    for(int i = 0; i < 13; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    removeNumber(arr, 12, 76);

    // Print the array
    cout << "Rearranged array" << endl;
    for(int i = 0; i < 12; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}
