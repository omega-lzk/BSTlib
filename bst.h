#ifndef BST_H
#define BST_H

#include <vector>

namespace bst {

    struct Node
    {
        int data;
        Node* left;
        Node* right;    

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };
    
    Node* insert(Node* root, int val);
    Node* search(Node* root, int val);
    void inorder(const Node* root, std::vector<int>& values);
    void preorder(const Node* root, std::vector<int>& values);
    void postorder(const Node* root, std::vector<int>& values);
    Node* remove(Node* root, int val);
    void clear(Node*& root);

}

#endif // BST_H