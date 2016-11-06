#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include <stdexcept>
using std::runtime_error;

template<typename T> 
struct my_queue {
	public:
		stack<T> true_stack;
		stack<T> inv_stack;

		void push(T val);
		T top();
		void pop();

	private:
		void invert_stacks();
};

template<typename T>
void my_queue<T>::invert_stacks() {

	if (inv_stack.empty() == false) {
		throw runtime_error("inv_stack is not empty.");
	}

	while (true_stack.empty() == false) {

		T &curr = true_stack.top();
		inv_stack.push(curr);
		true_stack.pop();
	}
}

template<typename T>
void my_queue<T>::push(T val) {
	true_stack.push(val);
}

template<typename T>
T my_queue<T>::top() {

	if (inv_stack.empty() && true_stack.empty()) {
		throw runtime_error("Stack empty.");
	}

	if (inv_stack.empty() == false) {
		return inv_stack.top();
	}

	// Invert stacks.
	invert_stacks();

	return inv_stack.top();
}

template<typename T>
void my_queue<T>::pop() {

	if (inv_stack.empty() && true_stack.empty()) {
		throw runtime_error("Stack empty");
	}

	if (inv_stack.empty() == false) {
		inv_stack.pop();
		return;
	}

	// Invert stacks.
	invert_stacks();

	inv_stack.pop();
	return;
}

int main(int argc, const char **argv) {

	my_queue<int> tmp;
	for(int i = 0; i < 5; i++) {
		tmp.push(i);
		tmp.push(i);
		tmp.pop();
	}

	for (int i = 0; i < 5; i++) {
		cout << "tmp[ " << i << "] = " << tmp.top() << endl;
		tmp.pop();
	}

	cout << endl;
}
