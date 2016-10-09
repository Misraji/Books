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

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}
