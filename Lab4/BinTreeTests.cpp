#include <assert.h>
#include <algorithm>
#include <iostream>

#include "BinTreeTests.h"

using std::cout;

TreeTester::TreeTester(const int size) : _max_size(size)
{
    test(size);
}

void TreeTester::test(const int size)
{
    add_and_size();
    destructor();
    remove();
    clear();
    assign();
    height();
    get_keys();
    min_key();
    max_key();
    sum_of_elements();
}

BinTree* TreeTester::allocate_tree()
{
    return new BinTree;
}

void TreeTester::deallocate_tree(BinTree* tree)
{
    delete tree;
}

void TreeTester::add_and_size()
{
    BinTree* tree = allocate_tree();

    for (int i = 0; i < _max_size; ++i) {
        tree->insert_node(i);
        check_add_and_size(*tree, i + 1);
    }
    check_add_and_size(*tree, _max_size);

    deallocate_tree(tree);
}

void TreeTester::check_add_and_size(const BinTree& tree, const int size)
{
    assert(tree.get_node_size() == size);
}

void TreeTester::destructor()
{
    for (int j = 0; j < 500; ++j)
    {
        BinTree* tree = allocate_tree();
        for (int i = 0; i < _max_size; ++i)
            tree->insert_node(i);
        deallocate_tree(tree);
    }
}

void TreeTester::remove()
{
    std::vector<int> nodeKeys;
    BinTree* tree = allocate_tree();

    tree->delete_by_key(5);

    for (int i = 0; i < _max_size; ++i) {
        int key = rand() % 500;
        nodeKeys.push_back(key);
        tree->insert_node(key);
    }

    while (!nodeKeys.empty()) {
        int random_index = rand() % nodeKeys.size();

        tree->delete_by_key(nodeKeys[random_index]);
        nodeKeys.erase(nodeKeys.begin() + random_index);
        check_remove(*tree, nodeKeys.size());
    }

    deallocate_tree(tree);
}

void TreeTester::clear()
{
    BinTree* tree1 = allocate_tree();
    BinTree* tree2 = allocate_tree();

    for (int i = 0; i < _max_size; i++)
        tree1->insert_node(i), tree2->insert_node(i);
    tree1->clear();
    check_clear(*tree1, 0);


    int node_number = tree2->get_node_size(tree2->root()->left());
    tree2->clear_sub_tree(tree2->root()->left());
    check_clear(*tree2, _max_size - node_number);

    tree2->clear_sub_tree(tree2->root());
    check_clear(*tree2, 1);

    deallocate_tree(tree1);
    deallocate_tree(tree2);
}

void TreeTester::check_remove(const BinTree& tree, const int size)
{
    assert(tree.get_node_size() == size);
}

void TreeTester::height()
{
    height_trivialCases();
    height_longOnlyLeftSubtree();
    height_longOnlyRightSubtree();
    height_longOnlyLeftAndRightSubtrees();
    height_longRandomZigzagSubtrees();
}

void TreeTester::min_key()
{
    BinTree* tree = allocate_tree();
    for (int i = 0; i < _max_size; i++)
        tree->insert_node(i);

    int min_value = tree->min_key();
    assert(min_value == 0);

    tree->clear();

    int min_key = 999;
    for (int i = 0; i < _max_size; i++) {
        int key = rand() % 100;
        if (min_key > key) {
            min_key = key;
        }
        tree->insert_node(key);
    }

    min_value = tree->min_key();
    assert(min_value == min_key);
    deallocate_tree(tree);
}

void TreeTester::max_key()
{
    BinTree* tree = allocate_tree();
    for (int i = 0; i < _max_size; i++)
        tree->insert_node(i);

    int max_value = tree->max_key();
    assert(max_value == _max_size - 1);

    int max_key = -999;
    for (int i = 0; i < _max_size; i++) {
        int key = rand() % 100;
        if (max_key < key) {
            max_key = key;
        }
        tree->insert_node(key);
    }

    max_value = tree->max_key();
    assert(max_value == max_key);
    deallocate_tree(tree);
}

void TreeTester::sum_of_elements()
{
    BinTree* tree = allocate_tree();
    for (int i = 0; i < _max_size; i++)
        tree->insert_node(rand() % 100);

    std::vector<int> nodes = tree->get_keys();
    int sum = 0;
    for (auto x : nodes)
        sum += x;

    check_sum(*tree, sum);
    deallocate_tree(tree);
}

void TreeTester::check_height(const BinTree& tree, const int height)
{
    assert(tree.height() == height);
}

void TreeTester::check_assign(const BinTree* first_tree, const BinTree* second_tree)
{
    std::vector<int> tree1 = second_tree->get_keys();
    std::vector<int> tree2 = first_tree->get_keys();
    assert(tree1.size() == tree2.size());
    for (unsigned int i = 0; i < tree1.size(); i++)
        assert(tree1[i] == tree2[i]);

    check_pointers(second_tree->root(), first_tree->root());
}

void TreeTester::check_clear(const BinTree& tree, const int size)
{
    assert(tree.get_node_size() == size);
}

void TreeTester::check_sum(const BinTree& tree, const int sumOfNodeKeys)
{
    assert(tree.sum() == sumOfNodeKeys);
}

void TreeTester::check_node_keys(const BinTree& tree, const std::vector<int> rhs)
{
    std::vector<int> lhs = tree.get_keys();
    std::sort(lhs.begin(), lhs.end());
    assert(lhs.size() == rhs.size());
    for (unsigned int i = 0; i < lhs.size(); i++)
        assert(lhs[i] == rhs[i]);
}

void TreeTester::check_is_search_tree(const BinTree& tree)
{
    std::vector<int> nodeKeys = tree.get_keys();
    for (int i = 0; i < nodeKeys.size() - 1; i++)
        assert(nodeKeys[i] <= nodeKeys[i + 1]);
}

void TreeTester::check_pointers(const Node* first_node, const Node* second_node)
{
    if (!first_node && !second_node)
        return;

    assert(first_node != second_node);
    check_pointers(first_node->left(), second_node->left());
    check_pointers(first_node->right(), second_node->right());
}

void TreeTester::height_trivialCases()
{
    BinTree tree;
    check_height(tree, 0);
    tree.insert_node(0);
    check_height(tree, 1);
}

void TreeTester::height_longOnlyLeftSubtree()
{
    BinTree long_tree;
    long_tree.insert_node(0);
    Node* runner = long_tree.root();
    for (int i = 1; i < _max_size; ++i) {
        runner->left(new Node(i));
        runner = runner->left();
        check_height(long_tree, i + 1);
    }
}

void TreeTester::height_longOnlyRightSubtree()
{
    BinTree long_tree;
    long_tree.insert_node(0);
    Node* runner = long_tree.root();
    for (int i = 1; i < _max_size; ++i) {
        runner->right(new Node(i));
        runner = runner->right();
        check_height(long_tree, i + 1);
    }
}

void TreeTester::height_longOnlyLeftAndRightSubtrees()
{
    BinTree long_tree;
    long_tree.insert_node(0);
    Node* left_runner = long_tree.root();
    Node* right_runner = long_tree.root();
    for (int i = 1; i < _max_size / 2; ++i) {
        left_runner->left(new Node(i));
        left_runner = left_runner->left();
        check_height(long_tree, i + 1);

        right_runner->right(new Node(i));
        right_runner = right_runner->right();
        check_height(long_tree, i + 1);
    }
}

void TreeTester::height_longRandomZigzagSubtrees()
{
    BinTree long_tree;
    long_tree.insert_node(0);
    Node* left_runner = long_tree.root();
    Node* right_runner = long_tree.root();

    left_runner->left(new Node(1));
    left_runner = left_runner->left();
    right_runner->right(new Node(1));
    right_runner = right_runner->right();

    for (int i = 2; i < _max_size / 2; ++i) {
        if (rand() % 2 == 0)
        {
            left_runner->left(new Node(i));
            left_runner = left_runner->left();
        }
        else
        {
            left_runner->right(new Node(i));
            left_runner = left_runner->right();
        }
        check_height(long_tree, i + 1);

        if (rand() % 2 == 0)
        {
            right_runner->left(new Node(i));
            right_runner = right_runner->left();
        }
        else
        {
            right_runner->right(new Node(i));
            right_runner = right_runner->right();
        }
        check_height(long_tree, i + 1);
    }
}

void TreeTester::assign()
{
    BinTree* tree1 = allocate_tree();
    for (int i = 0; i < _max_size; ++i)
        tree1->insert_node(i);

    BinTree* tree2 = allocate_tree();
    *tree2 = *tree1;
    check_assign(tree1, tree2);

    *tree1 = *tree2;
    check_assign(tree1, tree2);

    deallocate_tree(tree1);
    deallocate_tree(tree2);
}



void TreeTester::get_keys()
{
    std::vector<int> nodes;
    BinTree* tree = allocate_tree();
    check_node_keys(*tree, nodes);

    for (int i = 0; i < _max_size; i++)
    {
        int key = rand() % 100;
        nodes.push_back(key);
        tree->insert_node(key);
    }
    std::sort(nodes.begin(), nodes.end());
    check_node_keys(*tree, nodes);

    deallocate_tree(tree);
}
