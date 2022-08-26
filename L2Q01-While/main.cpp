#include <iostream>

using namespace std;

int main()
{
    int n = 10; // Executed 1 time
    int aux = 1; // Executed 1 time
    int i = 0; // Executed 1 time
    while (i < n) { // Executed n + 1 times
        aux += i;  // Executed n times
        i++; // Executed n times
    }

    // Total: 3n +4 executions

    return aux;
}
