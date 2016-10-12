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

#include <stack>
using std::stack;

#include <stdexcept>
using std::runtime_error;

template<typename T>
class BinaryTree {
	public:
		T data;
		shared_ptr<BinaryTree<T> > parent, left, right;

		BinaryTree(T &val) : data(val) {}
		BinaryTree(T val) : data(val) {}
};

template<typename T>
void inorder_traversal(shared_ptr<BinaryTree<T> > root) {
	// All argument checks.
	if (!root) {
		return;
	}

	// All variable initializations.
	shared_ptr<BinaryTree<T> > curr, prev;
	curr = root;

	// This loop is operational 
	while (curr) {

		if (prev == curr->parent) {
		
			if (curr->left) {
				prev = curr;
				curr = curr->left;

				continue;
			} 

			// No left child.
			// Lets print the value.
			cout << curr->data << ", ";

			if (curr->right) {
				//  Recurse to the right child now.
				prev = curr;
				curr = curr->right;

			} else {

				// No right node. Lets move to parent.
				prev = curr;
				curr = curr->parent;
			}

		} else if (prev == curr->right) {

			// We just finished visiting the right child.
			// Lets go one level upwards.
			prev = curr;
			curr = curr->parent;

		} else if (prev == curr->left) {

			// Ok. Left sub-tree done. Lets do right subtree.
			cout << curr->data << ", ";

			if (curr->right) {
				//  Recurse to the right child now.
				prev = curr;
				curr = curr->right;

			} else {

				// No right node. Lets move to parent.
				prev = curr;
				curr = curr->parent;
			}

		} else {
			cout << "Cant recognize prev" << endl;
			return;
		}
	}

	cout << endl;
}

int main(int argc, const char **argv) {

	shared_ptr<BinaryTree<int> > node10(new BinaryTree<int>(10));
	shared_ptr<BinaryTree<int> > node13(new BinaryTree<int>(13));
	shared_ptr<BinaryTree<int> > node15(new BinaryTree<int>(15));
	shared_ptr<BinaryTree<int> > node05(new BinaryTree<int>(5));
	shared_ptr<BinaryTree<int> > node07(new BinaryTree<int>(7));

	node10->right = node15; node15->parent = node10;
	node10->left = node05; node05->parent = node10;

	node05->right = node07; node07->parent = node05;
	node15->left = node13; node13->parent = node15;

	inorder_traversal(node10);
}
