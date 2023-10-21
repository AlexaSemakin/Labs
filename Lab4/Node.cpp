#include "Node.h"

Node::Node(const int key) : m_key(key),
m_left(nullptr),
m_right(nullptr) {};

Node::Node(const int key, Node* left, Node* right) : m_key(key),
m_left(left),
m_right(right) {};

int Node::key() const {
    return m_key;
}

void Node::key(const int key) {
    m_key = key;
}

void Node::left(Node* left) {
    m_left = left;
}

void Node::right(Node* right) {
    m_right = right;
}

const Node* Node::left() const {
    return m_left;
}
const Node* Node::right() const {
    return m_right;
}

Node*& Node::left() {
    return m_left;
}
Node*& Node::right() {
    return m_right;
}
