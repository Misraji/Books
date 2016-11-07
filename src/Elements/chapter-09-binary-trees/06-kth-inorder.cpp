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
		int size;
		shared_ptr<BinaryTree<T> > left, right;
};

template<typename T>
shared_ptr<BinaryTree<T> > find_kth_node(shared_ptr<BinaryTree<T> > r, int k) {

	while (r && k) {

		int left_size = (r->left == nullptr) ? 0 : r->left->size;

		if ( k == (left_size + 1)) {
			return r;

		} else if (k <= left_size) {
			r = r->left;

		} else {
			r = r->right;
			k -= left_size + 1;
		}
	}
	return nullptr;
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}
