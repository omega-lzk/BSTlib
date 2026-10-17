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

        else if (val > root->data)
        {
            root->right = insert(root->right, val);
        }
        
        return root;

    }

    Node* search(Node* root, int val){
        if (root == nullptr || root->data == val)
        {
            return root;
        }

        if (val < root->data)
        {
            return search(root->left, val);
        }

        return search(root->right, val);
    }

    void inorder(const Node* root, std::vector<int>& values){
        if (root == nullptr)
        {
            return;
        }

        inorder(root->left, values);
        values.push_back(root->data);
        inorder(root->right, values);
    }

    void preorder(const Node* root, std::vector<int>& values){
        if (root == nullptr)
        {
            return;
        }

        values.push_back(root->data);
        preorder(root->left, values);
        preorder(root->right, values);
    }

    void postorder(const Node* root, std::vector<int>& values){
        if (root == nullptr)
        {
            return;
        }

        postorder(root->left, values);
        postorder(root->right, values);
        values.push_back(root->data);
    }

    Node* remove(Node* root, int val){
        if (root == nullptr)
        {
            return nullptr;
        }

        if (val < root->data)
        {
            root->left = remove(root->left, val);
            return root;
        }

        if (val > root->data)
        {
            root->right = remove(root->right, val);
            return root;
        }

        if (root->left == nullptr)
        {
            Node* right = root->right;
            delete root;
            return right;
        }

        if (root->right == nullptr)
        {
            Node* left = root->left;
            delete root;
            return left;
        }

        Node* successor = root->right;
        while (successor->left != nullptr)
        {
            successor = successor->left;
        }

        root->data = successor->data;
        root->right = remove(root->right, successor->data);
        return root;
    }

    void clear(Node*& root){
        if (root == nullptr)
        {
            return;
        }

        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }

}