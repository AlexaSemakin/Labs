#include <assert.h>
#include <algorithm>
#include <iostream>
#include "Tests.h"

SearchTreeTester::SearchTreeTester(const int size)
{
    _max_size = size;
    test(size);
}

void SearchTreeTester::test(const int size)
{
    add_and_size();
    destructor();
    remove();
    clear();
    assign();
    get_keys();
    min_key();
    max_key();
    find();
}

BinTree* SearchTreeTester::allocate_tree()
{
    return new SearchTree;
}

void SearchTreeTester::check_find(const BinTree& tree, const int node, const int result)
{
    const SearchTree* searchTree = dynamic_cast<const SearchTree*>(&tree);
    assert(searchTree != nullptr);
    const Node* ptr = searchTree->search(node);
    if (!ptr)
        assert(result == -1);
    else 
        assert(ptr->key() == result);
}

void SearchTreeTester::check_bst(const BinTree& tree)
{
    std::vector<int> nodes;
    nodes = tree.get_keys();
    for (int i = 1; i < nodes.size(); i++)
        assert(nodes[i - 1] <= nodes[i]);
}

void SearchTreeTester::check_add_and_size(const BinTree& tree, const int size)
{
    assert(tree.get_node_size() == size);
    check_bst(tree);
}

void SearchTreeTester::check_remove(const BinTree& tree, const int size)
{
    assert(tree.get_node_size() == size);
    check_bst(tree);
}

void SearchTreeTester::find()
{
    BinTree* tree = allocate_tree();
    std::vector<int> node_keys;

    // check empty tree
    check_find(*tree, 4, -1);
    for (int i = 0; i < _max_size; i++)
    {
        int key = rand() % 50;
        node_keys.push_back(key);
        tree->insert_node(key);
    }

    // check tree
    for (auto x : node_keys)
        check_find(*tree, x, x);

    for (int i = 0; i < _max_size; i++)
        check_find(*tree, rand() % 50 + 50, -1);

    deallocate_tree(tree);
}
