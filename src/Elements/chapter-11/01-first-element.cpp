#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;
using std::copy;

#include <iterator>
using std::ostream_iterator;

int bsearch(const int &t, const vector<int> &arr) {

	// Note that the empty check must be before using the size of the vector.
	// The iterativ loop would work fine with u == -1, however the end-point
	// check wouldnt.
	if (arr.empty()) {
		return -1;
	}

	int result = -1;
	int l = 0, u = arr.size()-1;

	// Note that you have to check the endpoints first.
	if (arr[l] == t) {
		// If the first element is the required number, there can be any index
		// less than that.
		return l;
	} 

	if (arr[u] == t) {
		// Since we have find the lowest such index, we must continue
		// searching.
		result = u;
	}

	// Primary binary search algorithm.
	// NOTE: That <= is absolutely important!!!!
	while (l <= u) {
		int m = l + ((u-l) >> 1);
		if (arr[m] == t) {
			result = m;
			u = m - 1;

		} else if (arr[m] < t) {
			l = m + 1;

		} else {
			u = m - 1;
		}
	}
	return result;
}

int main(int argc, const char **argv) {

	int result = -1;

	// Even number of elements.
	int arr1[] = {1, 1, 2, 2, 3, 4, 4 };
	int arr1_len = sizeof(arr1)/sizeof(int);
	vector<int> vec1(arr1, arr1 + arr1_len);

	sort(vec1.begin(), vec1.end());
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, ","));
	cout << endl;

	result = bsearch(1, vec1);
	cout << "bsearch(1, vec1) = " << result << endl;

	result = bsearch(2, vec1);
	cout << "bsearch(2, vec1) = " << result << endl;
	
	result = bsearch(4, vec1);
	cout << "bsearch(4, vec1) = " << result << endl;

}
