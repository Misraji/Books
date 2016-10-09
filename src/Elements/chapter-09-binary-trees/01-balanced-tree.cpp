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
using std::max;

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

template<typename T>
pair<int, bool> is_tree_balanced(shared_ptr<BinaryTree<T> > root) {

	if (root == nullptr) {
		return make_pair(0, true);
	}

	auto left_val = is_tree_balanced(root->left);
	auto right_val = is_tree_balanced(root->right);

	bool is_balanced = (left_val.second && right_val.second 
						&& (abs(left_val.first - right_val.first) <= 0));

	bool height = max(left_val.first, right_val.first);

	return make_pair(height, is_balanced);
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}
