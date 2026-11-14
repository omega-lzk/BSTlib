#ifndef BST_H
#define BST_H

#include <vector>

namespace bst {

    class Node
    {
    public:
        Node(int value) : data(value), left(nullptr), right(nullptr) { }

        int data;
        Node* left;
        Node* right;
    };

    class BinarySearchTree
    {
    public:
        BinarySearchTree();
        ~BinarySearchTree();

        void insert(int value);
        bool search(int value) const;
        bool remove(int value);

        std::vector<int> inorder() const;
        std::vector<int> preorder() const;
        std::vector<int> postorder() const;

        void clear();
        bool empty() const;

    private:
        Node* root;

        Node* insert(Node* node, int value);
        bool search(Node* node, int value) const;
        Node* remove(Node* node, int value, bool& removed);
        void inorder(Node* node, std::vector<int>& values) const;
        void preorder(Node* node, std::vector<int>& values) const;
        void postorder(Node* node, std::vector<int>& values) const;
        void clear(Node* node);
    };

}

#endif // BST_H
