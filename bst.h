#ifndef BST_H
#define BST_H

namespace bst {

    struct Node
    {
        int data;
        Node* left;
        Node* right;    

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };
    
    Node* insert(Node* root, int val);

}

#endif // BST_H