#include <iostream>

using namespace std;

int main()
{
    int arr[12] = { 1, 2, 18, 20, 29, 30, 39, 44, 55, 56, 84, 96};

    int arrSize = sizeof(arr)/sizeof(arr[0]);

    // Print the array
    cout << "Initial array" << endl;
    for(int i = 0; i < arrSize; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    int searchedNumber = 18;

    int i = 0;
    int j = arrSize - 1;

    while(i <= j) {
        // first_third = i;
        int second_third = i + (j - i)/3;
        int third_third = j - (j - i)/3;

        if(searchedNumber == arr[second_third]){
            cout << "The number " << searchedNumber << " is in position " << second_third << endl;
            return 0;
        } else if (searchedNumber == arr[third_third]){
            cout << "The number " << searchedNumber << " is in position " << third_third << endl;
            return 0;
        } else if (searchedNumber < arr[second_third]) {
            // Going to the first part
            j = second_third - 1;
        } else if (searchedNumber > arr[third_third]) {
            // Going to the third part
            i = third_third + 1;
        } else {
            // Going to the second part
            i = second_third + 1;
            j = third_third - 1;
        }
    }

    return 0;
}
