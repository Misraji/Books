#include <stdexcept>
using std::runtime_error;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <stack>
using std::stack;

template<typename T>
void shift_stack(stack<T> &src, stack<T> &dest) {
	
	while (src.empty() == false) {
		dest.push(src.top());
		src.pop();
	}
}

template<typename T>
void sort_stack(stack<T> &src) {
	

	if (src.empty()) {
		return;
	}

	stack<T> tmp;
	tmp.push(src.top());
	src.pop();

	while (src.empty() == false) {

		T curr = src.top();
		src.pop();

		if (curr >= tmp.top()) {
			tmp.push(curr);

		} else {
			
			shift_stack(tmp, src);
			tmp.push(curr);
		}
	}

	while (tmp.empty() == false) {
		src.push(tmp.top());
		tmp.pop();
	}
}

int main(int argc, const char **argv) {

	stack<int> src;
	for (int i = 5; i > 0; i--) {
		src.push(i);
	}

	for (int i = 10; i < 20; i++) {
		src.push(i);
	}

	sort_stack(src);

	while(src.empty() == false) {
		cout << src.top() << ", " ;
		src.pop();
	}
	cout << endl;

}
