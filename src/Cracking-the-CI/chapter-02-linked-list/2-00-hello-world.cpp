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

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}
