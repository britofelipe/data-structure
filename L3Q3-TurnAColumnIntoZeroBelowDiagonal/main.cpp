#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int m = 10;
    int column = 3;
    int arr[n][m];

    int element = 0;

    // Declare and print matrix
    cout << "Initial matrix M: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] = element;
            cout << arr[i][j] << '\t';
            element++;
        }
        cout << endl;
    }

    cout << endl;
    cout << "Turn into zero a column below the diagonal: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (i > j && j == column) {
                arr[i][j] = 0;
            }
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
