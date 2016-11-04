#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <stdexcept>
using std::runtime_error;

template<typename T>
struct List {
	public:
		T data;
		List<T> *prev, *next;
};

template<typename T>
T nth_to_last(List<T> *head, const int N) {

	List<T> curr, nth;
	int counter = 0;

	curr = head;
	while ((curr != NULL) && (counter < (N-1))) {
		curr = curr->next;
		counter++;
	}

	if (counter < N) {
		throw(runtime_error("List does not have N elements"));
	}

	nth = head;
	curr = curr->next;

	while(curr) {
		nth = nth->next;
		curr = curr->next;
	}

	return nth->data;
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");
	cout << output << endl;
}
