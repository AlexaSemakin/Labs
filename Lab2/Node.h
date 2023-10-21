#pragma once
class Node {
private:
    int m_key;
    Node* m_left = nullptr;
    Node* m_right = nullptr;

public:
    Node(const int key);
    Node(const int key, Node* left, Node* right);
    ~Node() = default;

    int key() const;
    void key(const int key);

    Node*& left();
    const Node* left() const;
    void left(Node* left);

    Node*& right();
    const Node* right() const;
    void right(Node* left);
};
