#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

template<typename T>
int index_equals_number(const vector<T> &A) {
	
	// Argument checks.
	if (A.empty()) {
		return -1;
	}

	if (A[0] == 0) {
		return 0;
	}

	if (A[A.size()-1] == (A.size()-1)) {
		return (A.size()-1);
	}

	// All variable initializations
	int l = 0, u = (A.size()-1), m=-1;

	while (l <= u) {
		m = l + ((u-l) >> 1);

		if (A[m] == m) {
			return m;

		} else if (A[m] > m ){
			u = m - 1;

		} else {
			l = m + 1;
		}
	}

	return -1;
}

int main(int argc, const char **argv) {

	int arr[] = {-14, -10, 2, 108, 108, 243, 285, 285, 401} ;
	int arr_len = (sizeof(arr) / sizeof(int));
	vector<int> vec(arr , (arr + arr_len));

	int result = -1;
	
	result = index_equals_number(vec);
	cout << "index_equals_number(vec) = " << result << endl;

}
