#include <iostream>

using namespace std;

void turnZeroPositionBelowDiagonal(int i, int j, float** M, int n, int m) {
    // Turning into zero a position above the main diagonal
    if (i > j) {
        cout << "Invalid number";
        return;
    }

    for (int k = 0; k < m; k++) {
        M[i][k] = M[i][k] - (M[i][j]/M[j][j])*M[j][k];
    }
}

int main()
{
    int n = 10;
    int m = 10;

    float** arr = new float*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new float[m];
    }

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

    turnZeroPositionBelowDiagonal(4, 3, arr, n, m);

    // Print matrix
    cout << endl;
    cout << "After turning into zero the position where i < j: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;

    cout << endl;


    return 0;
}
