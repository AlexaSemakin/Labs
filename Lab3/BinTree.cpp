#include <iostream>

#include "Node.h"
#include "BinTree.h"

using std::cout;

BinTree::BinTree() {
    _root = nullptr;
}

BinTree::BinTree(const BinTree& other) {
    _root = _copy_tree(other._root);
}

BinTree::~BinTree() {
    clear();
}

const Node* BinTree::root() const {
    return _root;
}

Node* BinTree::root() {
    return _root;
}

void BinTree::clear() {
    _clear_sub_tree(_root);
    _root = nullptr;
}

bool BinTree::empty() const {
    return (!_root);
}

int BinTree::height() const {
    return height(_root);
}

int BinTree::get_node_size() const {
    return get_node_size(_root);
}

int BinTree::min_key() const {
    return min_key(_root);
}

int BinTree::max_key() const {
    return max_key(_root);
}

void BinTree::insert_node(const int key) {
    _root = insert_node(_root, key);
}

bool BinTree::delete_by_key(const int key) {
    return delete_by_key(_root, key);
}

bool BinTree::is_balanced() const {
    return is_balanced(_root);
}

int BinTree::sum() const {
    return sum(_root);
}

int BinTree::get_level(const int key) const {
    return get_level(_root, key);
}

void BinTree::print_horizontal(int marginLeft, int levelSpacing) const {
    print_horizontal(_root, marginLeft, levelSpacing);
}

void BinTree::print_leafs() const {
    print_leafs(_root);
}

std::vector<int> BinTree::get_keys() const {
    std::vector<int> node_values;
    _get_keys(_root, node_values);
    return node_values;
}

bool BinTree::empty(const Node* root) const {
    return (!root);
}

int BinTree::height(const Node* root) const {
    if (root) {
        int left_height = height(root->left());
        int right_height = height(root->right());

        if (left_height > right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
    return 0;
}

int BinTree::get_node_size(const Node* root) const {
    if (root) {
        int left_size = get_node_size(root->left());
        int right_size = get_node_size(root->right());
        return left_size + right_size + 1;
    }
    else {
        return 0;
    }
}

bool BinTree::is_balanced(const Node* root) const {
    if (_balanced(root) == -1)
        return false;
    return true;
}

int BinTree::sum(const Node* root) const {
    if (!root)
        return 0;

    int sum = root->key();
    sum += BinTree::sum(root->left());
    sum += BinTree::sum(root->right());

    return sum;
}

void BinTree::print_horizontal(const Node* root, int marginLeft, int levelSpacing) const {
    if (root == nullptr)
        return;

    print_horizontal(root->right(), marginLeft + levelSpacing, levelSpacing);
    cout << std::string(marginLeft, ' ') << root->key() << std::endl;
    print_horizontal(root->left(), marginLeft + levelSpacing, levelSpacing);
}

void BinTree::print_leafs(const Node* root) const {
    if (!root)
        return;

    if (!root->left() && !root->right())
        cout << root->key() << " ";

    print_leafs(root->left());
    print_leafs(root->right());
}

void BinTree::clear_sub_tree(Node* root) {
    if (!root)
        return;

    _clear_sub_tree(root->left());
    _clear_sub_tree(root->right());

    root->left(nullptr);
    root->right(nullptr);
}

int BinTree::min_key(const Node* root) const {
    if (!root)
        return -1;

    int min = root->key();

    if (root->left()) {
        int min_left = min_key(root->left());
        if (min >= min_left)
            min = min_left;
    }
    if (root->right()) {
        int min_right = min_key(root->right());
        if (min >= min_right)
            min = min_right;
    }

    return min;
}

int BinTree::max_key(const Node* root) const {
    if (!root)
        return -1;

    int max = root->key();

    if (root->left()) {
        int maxLeft = max_key(root->left());
        max = max > maxLeft ? max : maxLeft;
    }
    if (root->right()) {
        int maxRight = max_key(root->right());
        max = max > maxRight ? max : maxRight;
    }
    return max;
}

Node* BinTree::insert_node(Node* root, const int key) {
    if (!root)
        root = new Node(key);
    else if (rand() % 2)
        root->left(insert_node(root->left(), key));
    else
        root->right(insert_node(root->right(), key));

    return root;
}

bool BinTree::delete_by_key(Node*& root, const int key) {
    if (!root)
        return false;

    Node* parent = _get_parent(root, key);
    if (root->key() == key) {
        _delete_root(root);
        return true;
    }
    else if (!parent) {
        return false;
    }

    Node* temp;
    bool is_left = true;
    if (parent->left() && parent->left()->key() == key) {
        temp = parent->left();
    }
    else {
        temp = parent->right();
        is_left = false;
    }

    Node* replacement_node = nullptr;
    if (!temp->left() && !temp->right()) {
        if (is_left)
            parent->left(nullptr);
        else
            parent->right(nullptr);

        delete temp;
    }
    else if (!temp->left()) {
        replacement_node = temp->right();
        if (is_left)
            parent->left(nullptr);
        else
            parent->right(nullptr);

        delete temp;
        if (is_left)
            parent->left(replacement_node);
        else
            parent->right(replacement_node);

    }
    else if (!temp->right()) {
        replacement_node = temp->left();
        if (is_left)
            parent->left(nullptr);
        else
            parent->right(nullptr);

        delete temp;
        if (is_left)
            parent->left(replacement_node);
        else
            parent->right(replacement_node);
    }
    else {
        Node* runner = temp;
        while (runner->left()->left())
            runner = runner->left();

        replacement_node = runner->left();
        runner->left(runner->left()->right());
        replacement_node->left(temp->left());
        replacement_node->right(temp->right());

        if (is_left)
            parent->left(nullptr);
        else
            parent->right(nullptr);

        delete temp;
        if (is_left)
            parent->left(replacement_node);
        else
            parent->right(replacement_node);
        is_left ? parent->left(replacement_node) : parent->right(replacement_node);
    }

    return true;
}

int BinTree::get_level(const Node* root, const int key) const {
    return _get_level(root, key, 1);
}

std::vector<int> BinTree::get_keys(const Node* root) const {
    std::vector<int> node_values;
    _get_keys(root, node_values);
    return node_values;
}

BinTree BinTree::copy_tree(const Node* orig) {
    BinTree copy;
    copy._root = _copy_tree(orig);
    return copy;
}

Node* BinTree::_get_parent(Node* root, const int key) {
    if (!root || root->key() == key)
        return nullptr;

    if (root->left() && root->left()->key() == key)
        return root;

    if (root->right() && root->right()->key() == key)
        return root;

    Node* left_parent = _get_parent(root->left(), key);
    if (left_parent != nullptr)
        return left_parent;

    return _get_parent(root->right(), key);
}

BinTree& BinTree::operator=(const BinTree& other) {
    if (_root != nullptr)
        clear();

    _root = _copy_tree(other._root);

    return *this;
}

void BinTree::_get_keys(const Node* root, std::vector<int>& node_keys) const {
    if (!root)
        return;

    _get_keys(root->left(), node_keys);
    node_keys.push_back(root->key());
    _get_keys(root->right(), node_keys);
}

int BinTree::_get_level(const Node* root, const int key, int height) const {
    if (!root)
        return -1;

    if (root->key() == key)
        return height;

    int left_height = _get_level(root->left(), key, height + 1);
    int right_height = _get_level(root->right(), key, height + 1);

    if (left_height == -1 && right_height == -1)
        return -1;
    else if (left_height == -1)
        return right_height;
    return left_height;
}

void BinTree::_delete_root(Node*& root) {
    if (!root)
        return;

    Node* replacement_node = nullptr;
    if (!root->left() && !root->right()) {
        delete root;
        root = nullptr;
    }
    else if (!root->left()) {
        Node* temp = root;
        root = root->right();
        delete temp;
    }
    else if (!root->right()) {
        Node* temp = root;
        root = root->left();
        delete temp;
    }
    else {
        Node* runner = root;
        while (runner->left()->left())
            runner = runner->left();

        replacement_node = runner->left();
        runner->left(runner->left()->right());
        replacement_node->left(root->left());
        replacement_node->right(root->right());

        Node* temp = root;
        root = replacement_node;
        delete temp;
    }
}

void BinTree::_clear_sub_tree(Node* root) {
    if (!root)
        return;

    _clear_sub_tree(root->left());
    _clear_sub_tree(root->right());

    delete root;
}

int BinTree::_balanced(const Node* root) const {
    if (!root)
        return 0;

    int leftHeight = _balanced(root->left());
    if (leftHeight == -1)
        return -1;

    int rightHeight = _balanced(root->right());
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return std::max(leftHeight, rightHeight) + 1;
}

Node* BinTree::_copy_tree(const Node* orig) {
    if (!orig)
        return nullptr;

    Node* copy = new Node(orig->key());
    copy->left(_copy_tree(orig->left()));
    copy->right(_copy_tree(orig->right()));

    return copy;
}