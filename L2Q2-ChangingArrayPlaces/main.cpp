#include <iostream>

using namespace std;

int main()
{
    int arrL[10] = {16, 19, 41, 8, 42, 39, 33, 22, 29, 48};
    int arrLSize = sizeof(arrL)/sizeof(arrL[0]);

    int arrV[10] = {2, 5, 17, 9, 35, 19, 23, 72, 91, 44};
    int arrVSize = sizeof(arrV)/sizeof(arrV[0]);

    cout << "Initial array L: ";
    for(int i = 0; i < arrLSize; i++) {
        cout << arrL[i] << ", ";
    }
    cout << endl;

    cout << "Initial array V: ";
    for(int i = 0; i < arrVSize; i++) {
        cout << arrV[i] << ", ";
    }
    cout << endl;

    int aux = 0;
    for(int i = 0; i < arrLSize; i++) {
        aux = arrL[i];
        arrL[i] = arrV[i];
        arrV[i] = aux;
    }


    cout << "Rearranged array L: ";
    for(int i = 0; i < arrLSize; i++) {
        cout << arrL[i] << ", ";
    }
    cout << endl;

    cout << "Rearranged array V: ";
    for(int i = 0; i < arrVSize; i++) {
        cout << arrV[i] << ", ";
    }
    cout << endl;

    return 0;
}
