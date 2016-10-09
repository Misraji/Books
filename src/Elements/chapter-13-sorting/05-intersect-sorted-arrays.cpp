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
vector<T> intersect(vector<T> &vec1, vector<T> &vec2) {

	// All argument checks 
	// No checks in this case because empty vectors are correctly handled by
	// the algorithm.

	// All variable initializations.
	vector<T> result;
	auto itr1 = vec1.begin();
	auto itr2 = vec2.begin();

	while ((itr1 != vec1.end()) && (itr2 != vec2.end())) {

		T &val1 = *itr1;
		T &val2 = *itr2;

		if (val1 == val2) {
			result.push_back(val1);
			itr1++; itr2++;

		} else if (val1 < val2) {
			++itr1;

		} else {
			++itr2;
		}
	}

	return result;
}

int main(int argc, const char **argv) {

	int arr1[] = {1};
	int arr1_len = (sizeof(arr1) / sizeof(int));
	vector<int> vec1(arr1, (arr1 + arr1_len));

	int arr2[] = {1,2,3};
	int arr2_len = (sizeof(arr2) / sizeof(int));
	vector<int> vec2(arr2, (arr2 + arr2_len));

	vector<int> result;

	result = intersect(vec1, vec2);
	copy(result.begin(), result.end(), ostream_iterator<int>(cout, ","));
	cout << endl;

	int arr3[] = {2,3,4,5,};
	int arr3_len = (sizeof(arr3) / sizeof(int));
	vector<int> vec3(arr3, (arr3 + arr3_len));

	result = intersect(vec3, vec2);
	copy(result.begin(), result.end(), ostream_iterator<int>(cout, ","));
	cout << endl;
}
