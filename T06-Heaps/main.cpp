#include <iostream>
using namespace std;

class Heap {
    // Attributes
    double* arr;
    int maxSize;
    int _size;

    //      a
    //     / \
    //    b   c
    //   / \  / \
    //  d   e f  g
    // / \ / \ /   \
    //h  i j k l    m

    // a    b   c   d   e   f   g   h   i   j   k   l   m
    // 0    1   2   3   4   5   6   7   8   9  10   11  12 

    int parent(int i) { return (i - 1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); } 

    public:

        Heap(int maxSize) {
            // maxSize must be >=1
            if(maxSize < 1)
                return;
            arr = new double[maxSize];
            this->maxSize = maxSize;
            this->_size = 0;
            cout << "New heap allocated" << endl;
        }

        ~Heap () { 
            deleteHeap();
            cout << "Heap deallocated" << endl;
        }

        int isEmpty() { return _size == 0; }
        int isFull() { return _size >= maxSize; }
        int capacity () { return maxSize; }
        int size() { return _size; }

        void swap(double &a, double &b){
            double aux = a;
            a = b;
            b = aux;
        }

        void shiftUp(int i) {
            if(i > _size) return;
            if(i == 0) return; // Reached the root
            if(arr[i] > arr[parent(i)]) 
                swap(arr[i], arr[parent(i)]); // Swap child with parent
            shiftUp(parent(i)); // Recursively perform the same operation with the parent
            
        }

        void shiftDown(int i) {
            if(i > _size) return;

            int swapId = i;

            if(left(i) < _size && arr[i] < arr[left(i)]) // Meaning that it exists in the array and it has a child
                swapId = left(i);
            if(right(i) < _size && arr[swapId] < arr[right(i)]) // Meaning that R > L 
                swapId = right(i);
            
            if(swapId != i) { // while it is not on the top
                swap(arr[i], arr[swapId]);
                shiftDown(swapId);
            }

        }

        void insert(int element) {
            if(_size >= maxSize) {
                throw runtime_error("The heap is already full!");
            }
            arr[_size] = element;
            shiftUp(_size);
            _size++;
            return;
        }

        double remove() {
            if(isEmpty()) {
                throw runtime_error("The heap is empty!");
            }
            int max = arr[0];
            swap(arr[0], arr[_size - 1]); // Swap with smallets number
            _size--;
            shiftDown(0);
            return max;
        }

        double getMax(){
            if(isEmpty()) {
                throw runtime_error("The heap is empty!");
            }
            return arr[0];
        }

        void print() {
            if(isEmpty()) {
                throw runtime_error("The heap is empty!");
            }
            cout << "[ ";
            for(int i = 0; i < _size - 1; i++) cout << arr[i] << ", ";
            cout << arr[_size - 1] << " ]" << endl;
        }

        void deleteHeap() {
            delete arr; 
        }
};

int main () {

    Heap heap(10); 

    if (heap.capacity() != 10 or heap.size() != 0)
        return 1;

    for (int i = 0; i < 10; ++i) { heap.insert(i); heap.print(); }

    heap.print();

    for (int i = 0; i < 9; ++i) { heap.remove(); heap.print(); }
    heap.remove();

    cout << "Press any key to continue..." << endl;
    getchar();
}