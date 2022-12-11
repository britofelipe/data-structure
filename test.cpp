        // Making new node
        Node *newNode = new Node(element);

        // 1. If the tree is empty, then the root will be equal to the new node
        if(isEmpty()){ 
            root = newNode;
            return root;

        } else{ // 2. If the tree is not empty, then it will be on the left or in the right

            // 2.1. In case the tree is on the left
            if(element < root->data){
                root->left = insert(root->left, element);
            } else if (element > root->data){ // 2.1. If the new element will be on the right of current node
                root->right = insert(root->right, element);
            } else{
                cout << "Insertion is not possible: the element is already on the tree" << endl;
                return root;
            }
        }


        // Making new node
        Node *newNode = new Node(element);

        if(isEmpty(root)){
            root = newNode;
        } else{
            Node *temp = root;
            for(;;) { // while true
                if(newNode->data < temp->data){
                    if(temp->left == nullptr){
                        temp->left = newNode;
                        break;
                    } else{
                        temp = temp->left;
                    }
                } else{
                    if(temp->right == nullptr){
                        temp->right = newNode;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }



        // 1. If the tree is empty, then the root will be equal to the new node    
        if(root == nullptr)
            return (new Node(element));

        // 2. If the tree is not empty, then it will be on the left or in the right
        else{

            // 2.1. In case the tree is on the left
            if(element < root->data)
                root->left = insert(root->left, element);

            // 2.2. If the new element will be on the right of current node
            else if(element > root->data)
                root->right = insert(root->right, element);

            // 2.3. Otherwise, the element is already on the tree
            else{
                cout << "Insertion is not possible: the element is already on the tree" << endl;
                return root;
            }
        }


        if (root == NULL) {
            root = newNode;
            cout << "Value inserted successfully" << endl;
            return root;
        }

        if (element < root->data) {
            root->left = insert(root->left, element);
        } else if (element > root->data) {
            root->right = insert(root->right, element);
        } else {
            cout << "No duplicate values allowed!" << endl;
            return root;
        }