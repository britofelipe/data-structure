#include <iostream>

using namespace std;

struct Node{
    public:
        int key;
        Node* next = NULL;

    Node* new_linked_list(int n){
        Node* c;
        Node* h;
        c = new Node;

        h = c;

        for(int i = 0; i < n-1; i++){
            h->next = new Node;
            h = h->next;
        }

        return c;
    }
};

int main(){
    // Node* c;
    // Node* h;
    // c = new Node;
    // h = c; // h is a new node
    // h->next = new Node; // creating a new node from h
    // h = h->next; // h is the other node
    // h->next = new Node;
    // h = h->next;
    // h->next = new Node;

    Node* c;
    Node* h;

    c = new Node;
    c->key = 0;

    h = c;
    for(int i = 1; i < 8; i++){
        h->next = new Node;
        h = h->next;
        h->key = i*i;
    }

    int x = 9;
    bool found;

    h = c;
    found = false;

    while(h != NULL){
        if(h->key == x){
            found = true;
            break;
        }
        h = h->next;
    }

    h = c; 

    cout << h << endl;
    cout << found << endl;

    cout << "First linked list: " << endl;

    for(int i = 0; i < 8; i++){
        cout << h->key << endl;
        h = h->next;
    }

    h = c;

    // To insert at the beggining of the list:
    h = new Node;

    h->next = c;
    c = h;

    h->key = 0;

    cout << "Second linked list: " << endl;
    
    for(int i = 0; i < 9; i++){
        cout << h->key << endl;
        h = h->next;
    }

    // To insert at the end of the list
    h = new Node; // Node to be inserted on the list

    if(c == NULL){ // In case the list is empty
        c = h;
    }
    else{ // In case the list is not empty
        Node* aux = c; // Auxiliar pointer
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = h;
    }
    // since the "next" on the list is just the "h" pointer, we just have to put a new key on it
    h->key = 102;

    h = c;

    cout << "Third list" << endl;

    for(int i = 0; i < 10; i++){
        cout << h->key << endl;
        h = h->next;
    }

    // Ordered linked list: Insertion
    h = new Node;
    h->key = 11;

    if(c == NULL){
        c = h;
    }
    else{ // In case the list is not empty
        if(c->key > h->key){
            h->next = c;
            c = h;
        }
        else{
            Node* aux = c;

            while((aux->next != NULL) && (aux->next->key < h->key))
                aux = aux->next;
            h->next = aux->next; // The aux->next is the number, on the list, for which h is closer, but still smaller
            aux->next = h; // Then we have to put the aux->next to be h, so as the list can be ordered again
        }
    }

    cout << "Fourth list" << endl;

    h = c;

    for(int i = 0; i < 11; i++){
        cout << h->key << endl;
        h = h->next;
    }

}

