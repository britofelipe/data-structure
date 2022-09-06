#include <iostream>

using namespace std;

int main()
{
    int arr[12] = { 1, 2, 18, 20, 4, 17, 96, 97, 18, 77, 84, 85};
    int arrM[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int arrSize = sizeof(arr)/sizeof(arr[0]);

    // Print the array
    cout << "Initial array" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    int first_third = 0;
    int second_third = arrSize/3;
    int third_third = (2*arrSize/3);

    int k = 0;

    while(k < arrSize){
        if((arr[first_third] <= arr[second_third]) && first_third < arrSize/3) {
            if((arr[first_third] <= arr[third_third]) && third_third < arrSize) {
                cout << "First: " << first_third << endl;
                arrM[k] = arr[first_third];
                first_third++;
            } else if ((arr[first_third] > arr[third_third]) && third_third < arrSize) {
                cout << "Third: " << third_third << endl;
                arrM[k] = arr[third_third];
                third_third++;
            }
        } else {
            if(arr[second_third] <= arr[third_third] && second_third < (2*arrSize/2)) {
                cout << "Second: " << second_third << endl;
                arrM[k] = arr[second_third];
                second_third++;
            } else if (arr[second_third] > arr[third_third] && third_third < (2*arrSize/2)) {
                cout << "Third: " << third_third << endl;
                arrM[k] = arr[third_third];
                third_third++;
            }
        }
        k++;
    }


    // Print the array
    cout << "Rearranged array" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arrM[i] << ", ";
    }
    cout << endl;

    return 0;
}
