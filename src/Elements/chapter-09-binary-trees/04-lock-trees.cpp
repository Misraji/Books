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
		shared_ptr<BinaryTree<T> > parent, left, right;

		bool locked;
		int  num_desc_locked;

		BinaryTree(T &val) : data(val), locked(false), num_desc_locked(0) {}

		bool is_locked();
		bool lock();
		void unlock();
};

template<typename T>
bool BinaryTree<T>::is_locked() {
	return locked;
}

template<typename T>
bool BinaryTree<T>::lock() {

	if (locked) {
		return true;
	}

	bool ancestor_locked = false;
	bool result = false;

	auto ancestor = parent;
	while (ancestor) {
		ancestor_locked = (ancestor_locked || ancestor->locked);
		ancestor = ancestor->parent;
	}

	result = ((ancestor_locked == false) && (num_desc_locked == 0));
	if (result) {
		locked = true;

		auto ancestor = parent;
		while (ancestor) {
			ancestor->num_desc_locked++;
			ancestor = ancestor->parent;
		}
	}

	return result;
}

template<typename T>
void BinaryTree<T>::unlock() {

	if (locked == false) {
		return ;
	}

	auto ancestor = parent;
	while (ancestor) {
		ancestor->num_desc_locked--;
		ancestor = ancestor->parent;
	}
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}
