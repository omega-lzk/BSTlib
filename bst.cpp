#include "bst.h"

namespace bst {

    Node* insert(Node* root, int val){

        if (root == nullptr)
        {
            return new Node(val);
        }

        if (val < root->data)
        {
            root->left = insert(root->left, val);
        }

        if (val > root->data)
        {
            root->right = insert(root->right, val);
        }
        
        return root;

    }

    
}