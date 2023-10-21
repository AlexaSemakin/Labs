#include "SearchTree.h"

#include "SearchTree.h"

const Node* SearchTree::search(const int key) const {
	return search(_root, key);
}

const Node* SearchTree::search(const Node* root, const int key) const {
	if (!root)
		return nullptr;

	const Node* runner = root;
	while (runner) {
		if (key > runner->key()) {
			runner = runner->right();
		}
		else if (key < runner->key()) {
			runner = runner->left();
		}
		else {
			return runner;
		}
	}
	return nullptr;
}

bool SearchTree::delete_by_key(Node*& root, const int key) {
	bool is_del = false;
	root = removeNode(root, key, is_del);
	return is_del;
}

Node* SearchTree::removeNode(Node* root, const int key, bool& is_del) {
	if (!root) {
		return nullptr;
	}
	if (key < root->key()) {
		root->left(removeNode(root->left(), key, is_del));
	}
	else if (key > root->key()) {
		root->right(removeNode(root->right(), key, is_del));
	}
	else {
		is_del = true;
		if (!root->left()) {
			Node* right = root->right();
			delete root;
			return right;
		}
		else if (!root->right()) {
			Node* left = root->left();
			delete root;
			return left;
		}
		else {
			Node* temp = root->right();
			Node* parent_node = nullptr;

			while (temp->left()) {
				parent_node = temp;
				temp = temp->left();
			}

			if (!parent_node) {
				temp->left(root->left());
				delete root;
				return temp;
			}

			parent_node->left(temp->right());
			temp->left(root->left());
			temp->right(root->right());
			delete root;
			return temp;
		}
	}
	return root;
}

int SearchTree::min_key(const Node* root) const {
	if (!root) {
		return INT_MAX;
	}
	const Node* runner = root;
	while (runner->left()) {
		runner = runner->left();
	}

	return runner->key();
}

int SearchTree::max_key(const Node* root) const {
	if (!root) {
		return INT_MIN;
	}
	const Node* runner = root;
	while (runner->right()) {
		runner = runner->right();
	}

	return runner->key();
}

int SearchTree::get_level(const Node* root, const int key) const {
	if (!root) {
		return -1;
	}

	const Node* runner = root;
	int level = 1;
	while (runner) {
		if (runner->key() < key) {
			runner = runner->right();
			level++;
		}
		else if (runner->key() > key) {
			runner = runner->left();
			level++;
		}
		else {
			return level;
		}
	}

	return -1;
}

SearchTree& SearchTree::operator=(const SearchTree& other) {
	if (_root != nullptr) {
		clear();
	}
	_root = _copy_tree(other._root);
	return *this;
}

SearchTree SearchTree::copy_sub_tree(const Node* from) {
	SearchTree to;
	to._root = _copy_tree(from);
	return to;
}

Node* SearchTree::insert_node(Node* root, const int key) {
	if (!root) {
		root = new Node(key);
		return root;
	}
	if (root->key() > key) {
		root->left(insert_node(root->left(), key));
	}
	else {
		root->right(insert_node(root->right(), key));
	}

	return root;
}
