#include "bst.h"
#include <vector>

namespace data_structures {

    // ==========================================
    // Costruttore e Distruttore
    // ==========================================

    BST::BST() : root(nullptr) {
        // Inizializza la radice a nullptr
    }

    BST::~BST() {
        // Pulisce la memoria liberando tutti i nodi quando l'oggetto viene distrutto
        clear(root);
    }

    // ==========================================
    // Metodi Pubblici (Interfaccia per l'utente)
    // ==========================================

    void BST::insert(int val) {
        root = insert(root, val);
    }

    bool BST::search(int val) const {
        return search(root, val) != nullptr;
    }

    void BST::remove(int val) {
        root = remove(root, val);
    }

    void BST::clear() {
        clear(root);
    }

    std::vector<int> BST::inorder() const {
        std::vector<int> values;
        inorder(root, values);
        return values;
    }

    std::vector<int> BST::preorder() const {
        std::vector<int> values;
        preorder(root, values);
        return values;
    }

    std::vector<int> BST::postorder() const {
        std::vector<int> values;
        postorder(root, values);
        return values;
    }

    // ==========================================
    // Metodi Privati (Helper Ricorsivi)
    // ==========================================

    Node* BST::insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        
        return node;
    }

    Node* BST::search(Node* node, int val) const {
        if (node == nullptr || node->data == val) {
            return node;
        }

        if (val < node->data) {
            return search(node->left, val);
        }

        return search(node->right, val);
    }

    void BST::inorder(const Node* node, std::vector<int>& values) const {
        if (node == nullptr) return;

        inorder(node->left, values);
        values.push_back(node->data);
        inorder(node->right, values);
    }

    void BST::preorder(const Node* node, std::vector<int>& values) const {
        if (node == nullptr) return;

        values.push_back(node->data);
        preorder(node->left, values);
        preorder(node->right, values);
    }

    void BST::postorder(const Node* node, std::vector<int>& values) const {
        if (node == nullptr) return;

        postorder(node->left, values);
        postorder(node->right, values);
        values.push_back(node->data);
    }

    Node* BST::remove(Node* node, int val) {
        if (node == nullptr) {
            return nullptr;
        }

        if (val < node->data) {
            node->left = remove(node->left, val);
            return node;
        }

        if (val > node->data) {
            node->right = remove(node->right, val);
            return node;
        }

        // Caso 1 e 2: Un solo figlio o nessun figlio
        if (node->left == nullptr) {
            Node* rightChild = node->right;
            delete node;
            return rightChild;
        }

        if (node->right == nullptr) {
            Node* leftChild = node->left;
            delete node;
            return leftChild;
        }

        // Caso 3: Due figli -> Trova il successore (il minimo nel sottoalbero destro)
        Node* successor = node->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }

        node->data = successor->data;
        node->right = remove(node->right, successor->data);
        return node;
    }

    void BST::clear(Node*& node) {
        if (node == nullptr) return;

        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }

} // namespace data_structures