#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

template<typename T>
int first_element_larger_than_k(vector<T> &A, T &t) {

	// All argument checks (return if needed)
	if (A.empty()) {
		return -1;
	}
	
	// Check the last element.
	if (A[A.size()-1] == t) {
		return -1;
	}

	// All variable initializations
	int result = -1;
	int l = 0, u = (A.size()-1);
	int m  = -1;

	while (l <= u) {
		m = l + ((u-l) >> 1);

		if (A[m] > t) {
			result = m;
			u = m-1;

		} else {
			l = m + 1;
		}
	}

	return result;
}

int main(int argc, const char **argv) {

	int arr1[] = {1, 2, 3, 3, 4, 4 };
	int arr1_len = (sizeof(arr1) / sizeof(int));
	vector<int> vec1(arr1, (arr1 + arr1_len));

	int result = -1;
	int t = -1;

	t = 4;
	result = first_element_larger_than_k(vec1, t);
	cout << "first_element_larger_than_k(vec1, 4) = " << result << endl;

	t = 3;
	result = first_element_larger_than_k(vec1, t);
	cout << "first_element_larger_than_k(vec1, 3) = " << result << endl;

	t = 0;
	result = first_element_larger_than_k(vec1, t);
	cout << "first_element_larger_than_k(vec1, 0) = " << result << endl;
}
