#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::copy;

#include <iterator>
using std::ostream_iterator;

template<typename T>
int smallest_value(vector<T> &A) {

	// Argument checks.
	if (A.empty()) {
		return -1;
	}

	// All variable initializations
	int l = 0, u = (A.size()-1), m = -1;

	while (l < u) {
		m = l + ((u-l) >> 1);

		if ( A[m] > A[u]) {
			l = m+1;

		} else {
			u = m;		
		}
	}

	return l;
}

int main(int argc, const char **argv) {

	int arr[] = {478, 550, 631, 103, 203, 220, 234, 279, 368} ;
	int arr_len = (sizeof(arr) / sizeof(int));
	vector<int> vec(arr, (arr + arr_len));

	int result = smallest_value(vec);

	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ","));
	cout << endl;
	cout << "result = " << result << endl;
}
