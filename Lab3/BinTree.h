#pragma once

#include "Node.h"
#include <vector>

class BinTree {
public:
    BinTree();
    BinTree(const BinTree& other);
    virtual ~BinTree();

    const Node* root() const;
    Node* root();
    void clear();
    bool empty() const;
    int height() const;
    int get_node_size() const;
    int min_key() const;
    int max_key() const;
    void insert_node(const int key);
    bool delete_by_key(const int key);
    bool is_balanced() const;
    int sum() const;
    int get_level(const int key) const;
    void print_horizontal(int marginLeft, int levelSpacing) const;
    void print_leafs() const;
    std::vector<int> get_keys() const;

    bool empty(const Node* root) const;
    int height(const Node* root) const;
    int get_node_size(const Node* root) const;
    bool is_balanced(const Node* root) const;
    int sum(const Node* root) const;
    void print_horizontal(const Node* root, int marginLeft, int levelSpacing) const;
    void print_leafs(const Node* root) const;
    void clear_sub_tree(Node* root);
    virtual int min_key(const Node* root) const;
    virtual int max_key(const Node* root) const;
    virtual Node* insert_node(Node* root, const int key);
    virtual bool delete_by_key(Node*& root, const int key);
    virtual int get_level(const Node* root, const int key) const;
    std::vector<int> get_keys(const Node* root) const;
    BinTree copy_tree(const Node* from);

    BinTree& operator=(const BinTree& other);

protected:
    Node* _get_parent(Node* root, const int key);
    void _get_keys(const Node* root, std::vector<int>& nodeValues) const;
    int _get_level(const Node* root, const int key, int height) const;
    void _delete_root(Node*& root);
    virtual void _clear_sub_tree(Node* root);
    int _balanced(const Node* root) const;
    Node* _copy_tree(const Node* from);

protected:
    Node* _root = nullptr;
};
