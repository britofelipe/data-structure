#include <iostream>

using namespace std;

#define INITIAL_SIZE 2

/*
    IMPORTANT TOPICS: 
    1. Definition
    2. Basic operations:
        Deque.push_front(element)
        Deque.push_back(element)
        Deque.empty
        Deque.search_front(element)
        Deque.search_back(element)
        Deque.remove_front(element)
        Deque.remove_back(element)
    3. Resizing (t -> 2t) : What is the complexity?
*/

class Deque{
    
    double *arr;
    int maxSize;
    int front;
    int back;
    int count;

    public: 
        // Constructor method, initializes the deque
        Deque(){
            arr = new double[INITIAL_SIZE]; // Creates the vector with size 2
            maxSize = INITIAL_SIZE;
            front = 0; // Beggining of the deque
            back = -1; // End of the deque
            count = 0; // Number of elements
            cout << "Deque allocated" << endl;
        }

        ~Deque(){
            cout << "Deque deallocated" << endl;
        }

        double front_element(){
            return arr[front];
        }
        
        double back_element(){
            return arr[back];
        }

        void push_front(double element){
            if(count < maxSize || count == 0){
                count++;
                front = front - 1;
                if (front < 0)
                    front = maxSize - 1;
                arr[front] = element;
            } else{ 
                double_size();
                push_front(element);
            }
        }
        
        void push_back(double element){
            if(count < maxSize || count == 0){
                count++;
                back = ((back + 1) % maxSize);
                arr[back] = element;
            } else{
                double_size();
                push_back(element);
            }
        }

        double pop_front(){
            if(count > 0){
                double element = arr[front];
                arr[front] = -1;
                front = ((front + 1) % maxSize);
                count--;
                if (quarter_empty()){
                    cout << "HERE" << endl;
                    resize_deque();
                }
                return element;
            } else{
                cout << "The deque is empty" << endl;
            } 
        }
        
        double pop_back(){
            if(count > 0){
                double element = arr[back];
                arr[back] = -1;
                back = ((back - 1) % maxSize);
                count--;
                if (quarter_empty()){
                    resize_deque();
                }
                return element;
            } else{
                cout << "The deque is empty" << endl;
            }
            if (quarter_empty()){
                resize_deque();
            }
        }

        bool empty(){
            return count == 0;
        }

        bool quarter_empty(){
            return (count < maxSize/4);
        }

        void double_size() {
            double *aux = new double[2*maxSize];
            int i = front;
            int j = 0;

            while(i != back + 1){
                aux[j] = arr[i];
                i++;
                j++;

                if(i > maxSize)
                    i = 0;
            }                 
            front = 0;
            back = j - 1;
            maxSize = maxSize * 2;
            arr = aux;
            cout << "Deque with double size allocated: " << endl;
            print_all();
        }

        void resize_deque(){
            double *aux = new double[maxSize/4];
            int i = front;
            int j = 0;

            while(i != back + 1){
                aux[j] = arr[i];
                i++;
                j++;

                if(i > maxSize)
                    i = 0;
            }                 
            front = 0;
            back = j - 1;
            maxSize = maxSize / 4;
            arr = aux;
            cout << "Deque with quarter size allocated: " << endl;
            print_all();
        }

        void print_all(){
            for(int i = 0; i < maxSize; i++){
                cout << arr[i] << ", ";
            }
            cout << endl;
            cout << "Max Size: " << maxSize << '\t' << "Count: " << count << '\t' << "Front: " << front << '\t' << "Back: " << back << endl;
            cout << endl;
        }

        void print_values(){
            int i = front;
            while(i != back + 1){
                cout << arr[i] << ", ";
                i++;
                if(i > maxSize)
                    i = 0;
            }
            cout << endl;         
        }

        int number_elements(){
            return count;
        }

};

int main(){

    // Deque D;

    // D.push_back(1);  
    // D.push_back(2);  
    // D.push_back(3);

    // // D.print_all();
    // // D.print_values();

    // cout << "RE: " << D.front_element() << '\n';  
    // D.pop_front();

    // cout << "RE: " << D.front_element() << '\n';  
    // D.pop_front();

    // // D.print_all();
    // // D.print_values();

    // D.push_front(4);  
    // // D.print_all();
    
    // D.push_front(5);

    // // D.print_all();
    // // D.print_values();

    // cout << "RD: " << D.back_element() << '\n';  
    // D.pop_back();
    // cout << "RD: " << D.back_element() << '\n';  
    // D.pop_back();

    // cout << "Empty? -> " << D.empty() << '\n';

    // cout << "RD: " << D.back_element() << '\n';  
    // D.pop_back();

    // cout << "Empty? -> " << D.empty() << '\n';

    // D.print_all();
    // Deque C(D);
    // C.print_all();

    // D.push_front(6);  
    // D.push_front(7);  
    // D.push_back(8);

    // cout << "RD: " << D.back_element() << '\n';  
    // D.pop_back();
    // cout << "RD: " << D.back_element() << '\n';  D.pop_back();
    // cout << "RD: " << D.back_element() << '\n';  D.pop_back();

    Deque deque; 

    deque.push_back(1);
    deque.push_back(2);

    deque.print_all();

    deque.push_back(3);
    deque.print_all();

    deque.push_back(4);
    deque.print_all();

    deque.push_back(5);
    deque.print_all();

    deque.push_front(6);
    deque.print_all();

    deque.push_front(7);
    deque.print_all();

    deque.push_front(8);
    deque.print_all();

    deque.pop_back();
    deque.print_all();

    deque.pop_back();
    deque.print_all();

    deque.pop_back();
    deque.print_all();

    deque.pop_back();
    deque.print_all();

    deque.pop_front();
    deque.print_all();

    deque.pop_front();
    deque.print_all();

    deque.pop_front();
    deque.print_all();

    deque.pop_front();
    deque.print_all();
}