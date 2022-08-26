#include <iostream>

using namespace std;

void changeLines(int i, int j, float** M, int n, int m) {
    // Change lines i and j of matrix M and dimensions
    int aux = 0;
    for (int k = 0; k < m; k++) {
        aux = M[i][k];
        M[i][k] = M[j][k];
        M[j][k] = aux;
    }
}

void multiplyByScalar(int i, float a, float** M, int n, int m) {
    // Multiply the line i of matrix M and dimensions n x m
    for (int k = 0; k < m; k++) {
        M[i][k] = M[i][k] * a;
    }

}

void sumLines(int i, int j, float a, float** M, int n, int m) {
    // Sum to the line i the product of line j by a
    //in matrix M of dimensions n x m
    for (int k = 0; k < m; k++) {
        M[i][k] = M[i][k] + M[j][k] * a;
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

    int element =0;

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

    changeLines(3, 5, arr, n, m);

    // Print matrix
    cout << endl;
    cout << "Changing lines from M: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;

    multiplyByScalar(3, 3, arr, n, m);

    cout << "Multiplying by scalar: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }

    cout << endl;

    sumLines(3, 3, 3, arr, n, m);

    cout << "Sum by the multiple of a line: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }

    cout << endl;


    return 0;
}
