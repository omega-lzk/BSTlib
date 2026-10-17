#ifndef BST_H
#define BST_H

#include <vector>

namespace data_structures {

    // Definizione del nodo
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    class BST {
    private:
        Node* root; // La radice dell'albero è un attributo privato della classe

        // Funzioni helper ricorsive (private perché l'utente non deve passare i nodi manualmente)
        Node* insert(Node* current, int val);
        Node* search(Node* current, int val) const;
        void inorder(const Node* current, std::vector<int>& values) const;
        void preorder(const Node* current, std::vector<int>& values) const;
        void postorder(const Node* current, std::vector<int>& values) const;
        Node* remove(Node* current, int val);
        void clear(Node*& current);

    public:
        BST();  // Costruttore
        ~BST(); // Distruttore

        // Metodi pubblici (interfaccia pulita per l'utente)
        void insert(int val);
        bool search(int val) const;
        std::vector<int> inorder() const;
        std::vector<int> preorder() const;
        std::vector<int> postorder() const;
        void remove(int val);
        void clear();
    };

}

#endif