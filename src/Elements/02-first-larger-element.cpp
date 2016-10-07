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

template<typename T>
int search_first_larger_k(const vector<T> &A, const T &t ) {

	// cout << "t = " << t << endl;
	
	int result = -1;

	// TODO: Empty size check.
	if (A.empty()) {
		// returning -1;
		return result;
	}

	int l = 0, u = A.size() - 1;

	// The largest index == t. There cant be any greater number.
	if (A[u] == t) {
		// returning -1;
		return result;
	}

	while (l <= u) {
		int m = l + ((u-l) >> 1);
		const T &curr = A[m];

		if (curr > t) {
			// cout << "In Greater: l, u, m = " << l << ", " << u << ", " << m << endl;
			result = m;
			u = m-1;

		} else  {
			// cout << "In Less than: l, u, m = " << l << ", " << u << ", " << m << endl;
			l = m+1;
		} 
	}

	return (result);
}

int main(int argc, const char **argv) {

	int result = -1;

	int arr1[] = {1,2,2,3,4};
	int arr1_len = (sizeof(arr1)/sizeof(int));
	vector<int> vec1(arr1, arr1 + arr1_len);

	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, ","));
	cout << endl;

	result = search_first_larger_k(vec1, 4);
	cout << "search_first_larger_k(vec1, 4) = " << result << endl;

	result = search_first_larger_k(vec1, 2);
	cout << "search_first_larger_k(vec1, 2) = " << result << endl;

	result = search_first_larger_k(vec1, 1);
	cout << "search_first_larger_k(vec1, 1) = " << result << endl;
}
