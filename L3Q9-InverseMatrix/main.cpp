#include <iostream>

using namespace std;

int main(){

    int A[3][3] = {{1, -4, 2}, {-2, 1, 3}, {2, 6, 8}};

    // int B[3][3] = {(1, -2, 1), (2, 1, -3), (4, -7, 1)};

    // int C[3][3] = {(1, 2, 3), (3, 2, 1), (2, 1, 3)};

    // int D[3][3] = {(1, 2, 3, 4), (1, 2, 4, 3), (2, 1, 3, 4), (4, 3, 2, 1)};


    // Print matrix
    cout << endl;
    cout << "Initial matrix: " << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << A[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;

    cout << endl;

    // Finding the determinant
    float determinant = 0;

    for(int i = 0; i < 3; i++) {
       determinant = determinant + (A[0][i] * (A[1][(i+1)%3] * A[2][(i+2)%3] - A[1][(i+2)%3] * A[2][(i+1)%3]));
    }

    cout<<"Determinant: " << determinant << endl;

    cout << endl;
    cout << "Inverse Matrix: " << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout<<((A[(j+1) % 3][(i+1) % 3] * A[(j+2) % 3][(i+2) % 3]) - (A[(j+1) % 3][(i+2) % 3] * A[(j+2) % 3][(i+1) % 3]))/ determinant << '\t';
        }
        cout << endl;
    }
    cout << endl;

    cout << endl;


    return 0;
}
