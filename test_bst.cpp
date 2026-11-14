#include "bst.h"

#include <iostream>
#include <vector>

namespace {

    bool check(bool condition, const char* message)
    {
        if (!condition)
        {
            std::cerr << "FAIL: " << message << '\n';
            return false;
        }

        return true;
    }

}

int main()
{
    bst::BinarySearchTree tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);
    tree.insert(8);

    bool success = true;
    success = check(!tree.empty(), "insert creates a non-empty tree") && success;
    success = check(tree.search(6),
                    "search finds an existing value") && success;
    success = check(!tree.search(99),
                    "search returns false for a missing value") && success;

    success = check(
        tree.inorder() == std::vector<int>{1, 3, 4, 6, 7, 8, 10, 13, 14},
        "inorder returns sorted values without duplicates") && success;
    success = check(
        tree.preorder() == std::vector<int>{8, 3, 1, 6, 4, 7, 10, 14, 13},
        "preorder returns the expected order") && success;
    success = check(
        tree.postorder() == std::vector<int>{1, 4, 7, 6, 3, 13, 14, 10, 8},
        "postorder returns the expected order") && success;

    success = check(tree.remove(1), "remove deletes a leaf") && success;
    success = check(!tree.search(1), "removed leaf is no longer searchable") && success;
    success = check(tree.remove(14), "remove deletes a node with one child") && success;
    success = check(!tree.search(14) && tree.search(13),
                    "one-child removal preserves the child") && success;
    success = check(tree.remove(3), "remove deletes a node with two children") && success;
    success = check(!tree.search(3) && tree.search(4),
                    "two-child removal preserves the subtrees") && success;
    success = check(tree.remove(8), "remove deletes the root") && success;
    success = check(tree.inorder() == std::vector<int>{4, 6, 7, 10, 13},
                    "root removal uses the inorder successor") && success;
    success = check(!tree.remove(100),
                    "removing a missing value returns false") && success;

    tree.clear();
    success = check(tree.empty(), "clear releases the tree") && success;
    tree.clear();

    if (success)
    {
        std::cout << "All object-oriented BST tests passed.\n";
        return 0;
    }

    return 1;
}
