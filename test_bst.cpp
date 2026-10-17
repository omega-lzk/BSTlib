using namespace data_structures;
using namespace std;

#include "bst.h"
#include <iostream>
#include <vector>

namespace {

    bool same(const std::vector<int>& actual, const std::vector<int>& expected) {
        return actual == expected;
    }

    bool check(bool condition, const char* message) {
        if (!condition) {
            std::cerr << "FAIL: " << message << '\n';
            return false;
        }
        return true;
    }

}

int main() {
    // Creiamo un oggetto della classe BST
    BST albero;

    albero.insert(8);
    albero.insert(3);
    albero.insert(10);
    albero.insert(1);
    albero.insert(6);
    albero.insert(14);
    albero.insert(4);
    albero.insert(7);
    albero.insert(13);
    albero.insert(8); // Duplicato (ignorato o gestito)

    bool success = true;

    // Test di ricerca
    success = check(albero.search(6) == true, "search finds an existing value") && success;
    success = check(albero.search(99) == false, "search returns false for a missing value") && success;

    // Test Inorder
    success = check(same(albero.inorder(), {1, 3, 4, 6, 7, 8, 10, 13, 14}),
                    "inorder returns sorted values") && success;

    // Test Preorder
    success = check(same(albero.preorder(), {8, 3, 1, 6, 4, 7, 10, 14, 13}),
                    "preorder returns the expected order") && success;

    // Test Postorder
    success = check(same(albero.postorder(), {1, 4, 7, 6, 3, 13, 14, 10, 8}),
                    "postorder returns the expected order") && success;

    // Test Rimozione
    albero.remove(1);
    success = check(albero.search(1) == false, "remove deletes a leaf") && success;

    albero.remove(14);
    success = check(albero.search(14) == false && albero.search(13) == true,
                    "remove deletes a node with one child") && success;

    albero.remove(3);
    success = check(albero.search(3) == false && albero.search(4) == true,
                    "remove deletes a node with two children") && success;

    // Test Clear
    albero.clear();
    success = check(albero.search(8) == false, "clear releases the tree") && success;
    
    // Clear su albero già vuoto
    albero.clear();
    success = check(albero.search(8) == false, "clear accepts an empty tree") && success;

    if (success) {
        std::cout << "All BST class tests passed successfully!\n";
        return 0;
    }

    return 1;
}