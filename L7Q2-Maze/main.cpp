#include <iostream>
#include <stack>

using namespace std;

class Position{
    public:
        int row;
        int column;
};

class Stack{
    public:
        Position* arr;
        int maxSize;
        int top;
        int count; // number of elements in the stack

        // Constructor method, initializes the stack
        Stack(int arrSize){
            arr = new Position[arrSize];
            maxSize = arrSize;
            top = -1;
            count = 0;
        }

        // Insert an element at the top of the stack
        void push(Position position){
            if(count < maxSize){
                count++;
                top = ((top + 1) % maxSize);
                arr[top] = position;
            } else{
                cout << "The stack is full!" << endl;
            }
        }
        
        // Removes the element on the top of the stack
        Position pop(){
            if(count > 0){
                Position element = arr[top];
                arr[top].row = -1;
                arr[top].column = -1;

                top = ((top - 1) % maxSize);
                count--;
                return element;
            } else{
                cout << "The queue is empty!";
            }
        }

        // Empty
        int empty(){
            return count == 0;
        }

        // Returns top element, without removing it
        Position topElement(){
            Position element = arr[top];
            return element;
        }
};

int main() {
    int n = 12;
    int m = 20;
    
char maze[n][m] = {
        "####################",
        "#s                 #",
        "### ###### # # ## ##",
        "# # #    # ### ## ##",
        "#     ## ##    ## ##",
        "#### ##  ## ###   ##",
        "#    ## # ###   # ##",
        "## #### # #   #   ##",
        "#  #      # ##### ##",
        "#### ###### ## ## ##",
        "####   #    #     ##",
        "##########e#########",
    };

    // char maze[n][m] = {
    //     "####################",
    //     "# #  #      # # #  e",
    //     "# # # ### ## # # # #",
    //     "# # # #    # # # # #",
    //     "# # # # # ## # # # #",
    //     "#        s         #",
    //     "## # # ## #### #####",
    //     "## # # ## ## #     #",
    //     "#  # #       ## # ##",
    //     "## # #### ##      ##",
    //     "## #   ## ##########",
    //     "####################",
    // };

    Stack positions(n*m);

    Position start;
    // Finding the start position
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maze[i][j] == 's'){
                start.row = i;
                start.column = j;
            }
        }
    }

    positions.push(start);
    bool found_exit = false;

    while(!found_exit){
        Position now = positions.topElement();
        int i = now.row;
        int j = now.column;

        maze[i][j] = '.';
        
        found_exit = i == 0 || i == n-1 || j == 0 || j == m-1;

        // Pushing the adjacent positions
        Position right;
        right.row = i;
        right.column = j + 1;

        Position bottom;
        bottom.row = i + 1;
        bottom.column = j;
        
        Position left;
        left.row = i;
        left.column = j - 1;

        Position up;
        up.row = i - 1;
        up.column = j;

        bool is_inside = i >= 0 && i < n && j >= 0 && j < m;

        if(is_inside && maze[right.row][right.column] != '#' && maze[right.row][right.column] != '.'){
            positions.push(right);
        } else if (is_inside && maze[bottom.row][bottom.column] != '#' && maze[bottom.row][bottom.column] != '.'){
            positions.push(bottom);
        } else if (is_inside && maze[left.row][left.column] != '#' && maze[left.row][left.column] != '.'){
            positions.push(left);
        } else if (is_inside && maze[up.row][up.column] != '#' && maze[up.row][up.column] != '.'){
            positions.push(up);
        } else{
            positions.pop();
        }

        cout << "--------------------------------" << endl;

        // Printing the track
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}