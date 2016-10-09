#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::swap;

#include <iterator>
using std::ostream_iterator;

template<typename T>
int partition(vector<T> &A, int start, int end) {

	if (start == end) {
		return start;

	} else if (start < end) {
		
		T &target = A[end];
		int final = start;

		for(int i = start; i < end; i++) {

			if (A[i] <= target) {
				swap(A[i], A[final]);
				final++;
			} 
		}

		swap(A[end], A[final]);
		return final;
	}

	return -1;
}

template<typename T>
void sort_rec(vector<T> &A, int start, int end) {
	
	if (start < end) {
		int mid = partition(A, start, end);
		sort_rec(A, start, (mid-1));
		sort_rec(A, (mid+1), end);
	}
}

template<typename T>
void quicksort(vector<T> &A) {

	if (A.size() > 0) {
		sort_rec(A, 0, (A.size()-1));
	}
}

int main(int argc, const char **argv) {

	// int arr1[] = {1, 232, 25, 100, 4, 49};
	int arr1[] = {2,1,1,2,1,1};
	int arr1_len = (sizeof(arr1) / sizeof(int));
	vector<int> vec1(arr1, arr1 + arr1_len);

	quicksort(vec1);
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, ","));
	cout << endl;
}
