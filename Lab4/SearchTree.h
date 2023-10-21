#pragma once
#include <iostream>
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

	static SearchTree get_optimal_tree(std::vector<int> d, std::vector<int> p, std::vector<int> q){
		if (d.size() != p.size() || p.size() != q.size() - 1) {
			throw new std::exception("size was different");
		}
		std::vector<std::vector<int>> w(q.size(), std::vector<int>(q.size(), 0));
		std::vector<std::vector<int>> c(q.size(), std::vector<int>(q.size(), 0));
		std::vector<std::vector<int>> r(q.size(), std::vector<int>(q.size(), 0));
		for (int i = 0; i < q.size(); i++)
		{
			for (size_t j = i; j < q.size(); j++)
			{
				if (i == j) {
					w[i][j] = q[i];
					c[i][j] = q[i];
				}
				else {
					w[i][j] = w[i][j - 1] + p[j-1] + q[j];
				}
			}
		}
		int t = 0;
		for (int i = t; t < q.size(); t++)
		{
			i = 0;
			for (size_t j = t+1; j < q.size(); j++, i++)
			{
				int min = 112341234;
				int index = 0;
				for (int k = i+1; k <= j; k++) {
					if (min >= c[i][k - 1] + c[k][j]) {
						min = c[i][k - 1] + c[k][j];
						index = k;
					}
				}
				c[i][j] = w[i][j] + min;
				r[i][j] = index;
			}
		}
		
		
		for (int i = 0; i < q.size(); i++)
		{
			for (size_t j = 0; j < q.size(); j++)
			{
				std::cout << w[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		
		for (int i = 0; i < q.size(); i++)
		{
			for (size_t j = 0; j < q.size(); j++)
			{
				std::cout << c[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

		for (int i = 0; i < q.size(); i++)
		{
			for (size_t j = 0; j < q.size(); j++)
			{
				std::cout << r[i][j] << " ";
			}
			std::cout << std::endl;
		}
		Node* result = create_tree(d, r, 0, r.size() - 1);
		SearchTree tree;  
		return tree.copy_sub_tree(result);
	}
	
	static Node* create_tree(std::vector<int>& d, std::vector<std::vector<int>>& r, int i, int j) {
		if (i >= j) {
			return nullptr; 
		}
		int k = r[i][j];
		return new Node(d[k-1], create_tree(d, r, i, k-1), create_tree(d, r, k, j));
	}


	SearchTree& operator=(const SearchTree& other);

protected:
	Node* removeNode(Node* root, const int key, bool& isDeleted);
};
