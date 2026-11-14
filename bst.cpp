#include "bst.h"

namespace bst {

    BinarySearchTree::BinarySearchTree()
    {
        root = nullptr;
    }

    BinarySearchTree::~BinarySearchTree()
    {
        clear();
    }

    void BinarySearchTree::insert(int value)
    {
        root = insert(root, value);
    }

    bool BinarySearchTree::search(int value) const
    {
        return search(root, value);
    }

    bool BinarySearchTree::remove(int value)
    {
        bool removed = false;
        root = remove(root, value, removed);
        return removed;
    }

    std::vector<int> BinarySearchTree::inorder() const
    {
        std::vector<int> values;
        inorder(root, values);
        return values;
    }

    std::vector<int> BinarySearchTree::preorder() const
    {
        std::vector<int> values;
        preorder(root, values);
        return values;
    }

    std::vector<int> BinarySearchTree::postorder() const
    {
        std::vector<int> values;
        postorder(root, values);
        return values;
    }

    void BinarySearchTree::clear()
    {
        clear(root);
        root = nullptr;
    }

    bool BinarySearchTree::empty() const
    {
        return root == nullptr;
    }

    Node* BinarySearchTree::insert(Node* node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }

        return node;
    }

    bool BinarySearchTree::search(Node* node, int value) const
    {
        if (node == nullptr)
        {
            return false;
        }

        if (node->data == value)
        {
            return true;
        }

        if (value < node->data)
        {
            return search(node->left, value);
        }

        return search(node->right, value);
    }

    Node* BinarySearchTree::remove(Node* node, int value, bool& removed)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (value < node->data)
        {
            node->left = remove(node->left, value, removed);
            return node;
        }

        if (value > node->data)
        {
            node->right = remove(node->right, value, removed);
            return node;
        }

        removed = true;

        if (node->left == nullptr)
        {
            Node* right = node->right;
            delete node;
            return right;
        }

        if (node->right == nullptr)
        {
            Node* left = node->left;
            delete node;
            return left;
        }

        Node* successor = node->right;
        while (successor->left != nullptr)
        {
            successor = successor->left;
        }

        node->data = successor->data;
        node->right = remove(node->right, successor->data, removed);
        return node;
    }

    void BinarySearchTree::inorder(
        Node* node, std::vector<int>& values) const
    {
        if (node == nullptr)
        {
            return;
        }

        inorder(node->left, values);
        values.push_back(node->data);
        inorder(node->right, values);
    }

    void BinarySearchTree::preorder(
        Node* node, std::vector<int>& values) const
    {
        if (node == nullptr)
        {
            return;
        }

        values.push_back(node->data);
        preorder(node->left, values);
        preorder(node->right, values);
    }

    void BinarySearchTree::postorder(
        Node* node, std::vector<int>& values) const
    {
        if (node == nullptr)
        {
            return;
        }

        postorder(node->left, values);
        postorder(node->right, values);
        values.push_back(node->data);
    }

    void BinarySearchTree::clear(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }

        clear(node->left);
        clear(node->right);
        delete node;
    }

}
