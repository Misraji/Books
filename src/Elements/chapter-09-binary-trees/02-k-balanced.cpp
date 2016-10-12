#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iterator>
using std::ostream_iterator;

#include <algorithm>
using std::copy;
using std::abs;

#include <memory>
using std::shared_ptr;

#include <utility>
using std::pair;
using std::make_pair;

template<typename T>
class BinaryTree {
	public:
		T data;
		shared_ptr<BinaryTree<T> > left, right;

};

// This method returns back offending node and the num nodes in subtree
template<typename T>
pair<shared_ptr<BinaryTree<T> >, int> is_k_balanced_rec(BinaryTree<T> *root, int k) {

	if (root == nullptr) {
		return make_pair(root, 0);
	}

	auto left_ret = is_k_balanced_rec(root->left, k);
	auto right_ret = is_k_balanced_rec(root->right, k);
	shared_ptr<BinaryTree<T> > ret_node;

	if (left_ret.first) {
		ret_node = left_ret.first;

	} else if (right_ret.first) {
		ret_node = right_ret.first;

	} else if ((abs(left_ret.second - right_ret.second)) > k ) {
		ret_node = root;
	}

	return make_pair(ret_node, (left_ret.second + right_ret.second + 1));
}


template<typename T>
BinaryTree<T>* is_k_balanced(BinaryTree<T> *root, int k) {

	auto ret = is_k_balanced_rec(root, k);
	return ret.first; 
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}
