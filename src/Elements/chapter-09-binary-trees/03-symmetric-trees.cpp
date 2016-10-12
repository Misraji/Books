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

#include <memory>
using std::shared_ptr;

template<typename T>
class BinaryTree {
	public:
		T data;
		shared_ptr<BinaryTree<T> > left, right;

};

template<typename T>
bool is_symmetric_rec(shared_ptr<BinaryTree<T> > left_root, shared_ptr<BinaryTree<T> > right_root) {

	// If both the nodes are null, return true
	if ((left_root == nullptr) && (right_root == nullptr)) {
		return true;
	}

	// If only one of the nodes is null, return false.
	if ((left_root == nullptr) || (right_root == nullptr)) {
		return false;
	}

	return ((left_root->val == right_root->val) && 
			is_symmetric_rec(left_root->left, right_root->right) &&
			is_symmetric_rec(left_root->right, right_root->left)
		   );
}

template<typename T>
bool is_symmetric(shared_ptr<BinaryTree<T> > root) {

	return ((root == nullptr) || is_symmetric_rec(root->left, root->right));
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}
