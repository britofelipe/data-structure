#include <iostream>

using namespace std;

#define MAX_SIZE 2

/*
    IMPORTANT TOPICS: 
    1. Definition
    2. Basic operations:
        Deck.push_front(element)
        Deck.push_back(element)
        Deck.empty
        Deck.search_front(element)
        Deck.search_back(element)
        Deck.remove_front(element)
        Deck.remove_back(element)
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
            arr = new double[MAX_SIZE]; // Creates the vector with size 2
            maxSize = MAX_SIZE;
            front = 0; // Beggining of the deque
            back = 0; // End of the deque
            count = 0; // Number of elements
            cout << "Deque allocated" << endl;
        }

        // Copy constructor method
        Deque(const Deque &rhs){ 
            // &rhs means address of the object which reference is referecing to
            this->arr = new double[rhs.maxSize*2]; // Creates the vector with size 2
            int i = rhs.front;
            int j = rhs.maxSize/2;
            while(i != rhs.back + 1){
                this->arr[j] = rhs.arr[i];
                i++;
                j++;

                if(i > rhs.maxSize)
                    i = 0;
            }
            this->maxSize = rhs.maxSize*2;
            this->front = rhs.maxSize/2; // Beggining of the deque
            this->back = j - 1; // End of the deque
            this->count = rhs.count; // Number of elements
            cout << "Deque with double size allocated" << endl;
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
                cout << "The deque is full!" << endl;
                // TODO
            }
        }
        
        void push_back(double element){
            if(count < maxSize || count == 0){
                count++;
                back = ((back + 1) % maxSize);
                arr[back] = element;
            } else{
                cout << "The deque is full!" << endl;
            }
        }

        double pop_front(){
            if(count > 0){
                double element = arr[front];
                arr[front] = -1;
                front = ((front + 1) % maxSize);
                count--;
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
                return element;
            } else{
                cout << "The deque is empty" << endl;
            }
        }

        bool empty(){
            return count == 0;
        }

        bool quarter_empty(){
            return (count < maxSize/4);
        }

        void print_all(){
            for(int i = 0; i < maxSize; i++){
                cout << arr[i] << ", ";
            }
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
    deque.print_values();
    deque.print_all();

    Deque copy(deque);
    copy.print_all();

    copy.push_front(3);
    copy.print_all();

    copy.push_front(4);
    // cout << copy.number_elements() << endl;
    // copy.print_values();
    copy.print_all();

    copy.push_back(5); 
    copy.print_all();

    copy.push_back(5);
    copy.print_all();

}