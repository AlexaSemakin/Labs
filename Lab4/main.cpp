#include "Tests.h"
#include "BinTree.h"
#include "SearchTree.h"





int main() {

	//SearchTreeTester tree(50);
	SearchTree::get_optimal_tree({ 10, 20, 30, 40 }, { 2, 1, 1, 5 }, { 1, 10, 1, 1, 10 }).print_horizontal(10, 5);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	SearchTree::get_optimal_tree({10, 20, 30, 40}, {2, 1, 1, 5}, {0,0,0,0,0}).print_horizontal(10, 5);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	SearchTree::get_optimal_tree({ 10, 20, 30, 40 }, { 0,0,0,0 }, { 1, 10, 1, 1, 10 }).print_horizontal(10, 5);
	return 0;
}
