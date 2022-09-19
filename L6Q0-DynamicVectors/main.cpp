#include <iostream>

using namespace std;

class Position {
    public :
        int l ;
        int c ;
};

int main() {
    Position* v ;
    int n = 10;
    v = new Position[n];

    for (int i = 0; i < n ; i ++){
        v[i].l = i * i ;
        v[i].c = i * i * i ;
    }

    for (int i = 0; i < n; i++){
        cout << "The line is " << v[i].l << " and the column is " << v [i].c << endl;
    }
}
