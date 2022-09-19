#include <iostream>

using namespace std;

class Position {
    public:
        int l; // line
        int c ; // column
        // constructor to initialize the position
        Position(int line , int column ){
            l = line ;
            c = column ;
        }
};

int main (){
    // creating a object Position in variable p
    Position p (10 , 15);
    cout << "Initial positions: " << p.l << ", " << p.c << endl;
    cout << "Enter the line position: ";
    cin >> p.l;

    cout << "Enter the column position: ";
    cin >> p.c;
    cout << "\nChanging positions with user entries: " << p.l << ", " << p.c << endl;
    p.l = 17;
    p.c = 18;
    cout << "Changing positions with code: " << p.l << ", " << p.c << endl;
}
