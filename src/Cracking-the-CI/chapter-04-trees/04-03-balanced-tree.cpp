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
struct Graph {
	public:
		T data;
		vector<Graph<T>*> adjacent;
};

template<typename T>
struct Tree {
	public:
		T data;
		Tree<T> *left, right;

		Tree(T d, Tree<T> *l, Tree<T> *r): data(d), left(l), right(r) {}
};

template<typename T>
Tree<T> * gen_tree_rec(T arr[], int start, int end) {

	if (start > end) {
		// We have exhausted the array range.
		return nullptr;
	}

	int mid = (start + end)/2; 

	Tree<T> *left = gen_tree_rec(arr, start, (mid-1));
	Tree<T> *right = gen_tree_rec(arr, (mid+1), end);

	return Tree<T>(arr[mid], left, right);
}

template<typename T>
Tree<T>* gen_tree(T arr[], int len) {
	return gen_tree_rec(arr, 0, (len-1));
}

int main(int argc, const char **argv) {

}
