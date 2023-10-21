#pragma once
#include "Node.h"
#include "binTree.h"

class SearchTree : public BinTree {
public:
	SearchTree() {};
	~SearchTree() override {};

	SearchTree copy_sub_tree(const Node* from);

	using BinTree::insert_node;
	Node* insert_node(Node* root, const int key);

	const Node* search(const int key) const;
	const Node* search(const Node* root, const int key) const;

	using BinTree::delete_by_key;
	bool delete_by_key(Node*& root, const int key);

	using BinTree::max_key;
	using BinTree::min_key;

	int min_key(const Node* root) const;
	int max_key(const Node* root) const;

	using BinTree::get_level;
	int get_level(const Node* root, const int key) const;

	SearchTree& operator=(const SearchTree& other);

protected:
	Node* removeNode(Node* root, const int key, bool& isDeleted);
};
