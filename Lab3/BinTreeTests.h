#pragma once

#include <vector>
#include "BinTree.h"

class TreeTester {
public:
    TreeTester() = default;
    TreeTester(const int size);
    ~TreeTester() = default;

protected:
    void test(const int size);
    virtual BinTree* allocate_tree();
    void deallocate_tree(BinTree* tree);

    void add_and_size();
    void destructor();
    void remove();
    void clear();
    void assign();
    void get_keys();
    void height();
    void min_key();
    void max_key();
    void sum_of_elements();

    virtual void check_add_and_size(const BinTree& tree, const int size);
    virtual void check_remove(const BinTree& tree, const int size);
    virtual void check_height(const BinTree& tree, const int size);
    virtual void check_assign(const BinTree* first_tree, const BinTree* second_tree);
    virtual void check_clear(const BinTree& tree, const int size);
    virtual void check_sum(const BinTree& tree, const int sumOfNodeKeys);
    virtual void check_node_keys(const BinTree& tree, const std::vector<int> nodeKeys);
    virtual void check_is_search_tree(const BinTree& tree);
    virtual void check_pointers(const Node* first_tree, const Node* second_tree);

    void height_trivialCases();
    void height_longOnlyLeftSubtree();
    void height_longOnlyRightSubtree();
    void height_longOnlyLeftAndRightSubtrees();
    void height_longRandomZigzagSubtrees();
protected:
    int _max_size;
};

