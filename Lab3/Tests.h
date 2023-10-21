#pragma once

#include "BinTreeTests.h"
#include "SearchTree.h"

class SearchTreeTester : public TreeTester
{
public:
	SearchTreeTester(const int);
	SearchTreeTester() = default;
	~SearchTreeTester() = default;

protected:

	void test(const int size);
	BinTree* allocate_tree() override;
	virtual void check_find(const BinTree& tree, const int node, const int result);
	virtual void check_bst(const BinTree& tree);
	void check_add_and_size(const BinTree& tree, const int size) override;
	void check_remove(const BinTree& tree, const int size) override;
	void find();
};


