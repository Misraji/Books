#include <stdexcept>
using std::runtime_error;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::abs;
using std::max;

template<typename T>
struct Tree {
	public:
		T data;
		Tree<T> *left, *right;

		Tree(T d, Tree<T> *l, Tree<T> *r): data(d), left(l), right(r) {}
};

template<typename T>
int check_balance(Tree<T> *root) {

	if (root == NULL) {
		return 0;
	}

	int left_height = check_balance(root->left);
	int right_height = check_balance(root->right);

	int height_diff = abs(left_height - right_height);
	int height_max = max(left_height, right_height);

	if (height_diff > 1) {
		throw runtime_error("Tree is unbalanced.");
	}

	return (height_max + 1);
}

template<typename T>
bool is_balanced(Tree<T> *root) {

	try {
		check_balance(root);

	} catch(...) {
		return false;
	}

	return true;
}

int main(int argc, const char **argv) {

	Tree<int> *node3 = new Tree<int>(3, NULL, NULL);
	Tree<int> *node5 = new Tree<int>(5, node3, NULL);
	Tree<int> *node15 = new Tree<int>(15, NULL, NULL);
	Tree<int> *node10 = new Tree<int>(10, node5, node15);

	cout << "is_balanced(node10) = " << is_balanced(node10) << endl;
}
