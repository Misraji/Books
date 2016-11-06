#include <stdexcept>
using std::runtime_error;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

template<typename T>
struct Tree {
	public:
		T data;
		Tree<T> *left, right;

		Tree(T d, Tree<T> *l, Tree<T> *r): data(d), left(l), right(r) {}
};

int main(int argc, const char **argv) {

}
