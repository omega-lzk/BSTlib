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
    bst::Node* root = nullptr;
    root = bst::insert(root, 8);
    root = bst::insert(root, 3);
    root = bst::insert(root, 10);
    root = bst::insert(root, 1);
    root = bst::insert(root, 6);
    root = bst::insert(root, 14);
    root = bst::insert(root, 4);
    root = bst::insert(root, 7);
    root = bst::insert(root, 13);
    root = bst::insert(root, 8);

    bool success = true;
    success = check(bst::search(root, 6) != nullptr,
                    "search finds an existing value") && success;
    success = check(bst::search(root, 99) == nullptr,
                    "search returns nullptr for a missing value") && success;

    std::vector<int> values;
    bst::inorder(root, values);
    success = check(values == std::vector<int>{1, 3, 4, 6, 7, 8, 10, 13, 14},
                    "inorder returns sorted values without duplicates") && success;

    values.clear();
    bst::preorder(root, values);
    success = check(values == std::vector<int>{8, 3, 1, 6, 4, 7, 10, 14, 13},
                    "preorder returns the expected order") && success;

    values.clear();
    bst::postorder(root, values);
    success = check(values == std::vector<int>{1, 4, 7, 6, 3, 13, 14, 10, 8},
                    "postorder returns the expected order") && success;

    root = bst::remove(root, 1);
    success = check(bst::search(root, 1) == nullptr,
                    "remove deletes a leaf") && success;
    root = bst::remove(root, 14);
    success = check(bst::search(root, 14) == nullptr &&
                    bst::search(root, 13) != nullptr,
                    "remove deletes a node with one child") && success;
    root = bst::remove(root, 3);
    success = check(bst::search(root, 3) == nullptr &&
                    bst::search(root, 4) != nullptr,
                    "remove deletes a node with two children") && success;
    root = bst::remove(root, 8);
    success = check(root != nullptr && root->data == 10,
                    "remove replaces the root with its inorder successor") && success;
    root = bst::remove(root, 100);
    success = check(root != nullptr,
                    "removing a missing value keeps the tree") && success;

    bst::clear(root);
    success = check(root == nullptr,
                    "clear releases the tree and resets the root") && success;
    bst::clear(root);

    if (success)
    {
        std::cout << "All procedural BST tests passed.\n";
        return 0;
    }

    return 1;
}
