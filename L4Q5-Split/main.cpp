#include <iostream>

using namespace std;

void split(int* arr, int arrSize){

    int number = arr[arrSize/2];
    int j = arrSize - 1;

    for(int i = 0; i < arrSize; i++){
        if(arr[i] == number){
            // Put the number on its place
            int k = i;
            while(arr[k + 1] < number){
                arr[k] = arr[k + 1];
                arr[k + 1] = number;
                k++;
            }
            return;
        }

        if(arr[i] > number) {
            while(arr[j] > number){
                j--;
            }
            int aux = arr[j];
            arr[j] = arr[i];
            arr[i] = aux;
        }
    }
}

int main()
{
    int arr[15] = {16, 43, 4, 90, 46, 41, 8, 42, 39, 33, 22, 2, 5, 49, 41};

    int arrSize = sizeof(arr)/sizeof(arr[0]);

    // Print the array
    cout << "Initial array" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    split(arr, arrSize);

    // Print the array
    cout << "Rearranged array" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}
