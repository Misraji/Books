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

	int l = 0, u = arr.size()-1;

	// Note that you have to check the endpoints first.
	if (arr[l] == t) {
		return l;
	} 

	if (arr[u] == t) {
		return u;
	}

	// Primary binary search algorithm.
	// NOTE: That <= is absolutely important!!!!
	while (l <= u) {
		int m = l + ((u-l) >> 1);
		if (arr[m] == t) {
			return m;

		} else if (arr[m] < t) {
			l = m + 1;

		} else {
			u = m - 1;
		}
	}
	return -1;
}

int main(int argc, const char **argv) {

	int result = -1;

	// Even number of elements.
	int arr1[] = {1,33,4,56,100,21, 20, 30};
	vector<int> vec1(arr1, arr1 + 8);

	sort(vec1.begin(), vec1.end());
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, ","));
	cout << endl;

	result = bsearch(4, vec1);
	cout << "bsearch(4, vec1) = " << result << endl;

	result = bsearch(30, vec1);
	cout << "bsearch(30, vec1) = " << result << endl;

	result = bsearch(21, vec1);
	cout << "bsearch(21, vec1) = " << result << endl;

	// Odd number of elements.
	vec1.push_back(110);
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, ","));
	cout << endl;

	result = bsearch(30, vec1);
	cout << "bsearch(30, vec1) = " << result << endl;

}
