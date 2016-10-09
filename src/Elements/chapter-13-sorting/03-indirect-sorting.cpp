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

template<typename T>
class Sorter {
	public:
		Sorter(vector<T> &A);

		bool operator()(int i, int j);

		void sort() ;

	private:
		// int partition(int i, int j);
		// void quick_sort(int i, int j);
		vector<T> &values;
		vector<int> indexes;
		vector<int> permutation;
};


template<typename T> 
Sorter<T>::Sorter(vector<T> &A) : values(A), indexes(A.size()), permutation(A.size()) {
	for(int i=0; i < A.size() ; i++) {
		indexes[i] = i;
	}
}

template<typename T> 
bool Sorter<T>::operator()(int i, int j) {
	return (values[i] < values[j]);
}

/*
template<typename T> 
int Sorter<T>::partition(int l, int u) {

	if ( l > u) {
		return -1;	
	}

	if (l == u) {
		return l;
	}

	T &curr = values[ indexes[u] ];
	int k = l;

	for (int i = l ; i < u; i++) {
		
		if ( values[index[i]] <= curr) {
			
			swap

		}
	}
	
}

template<typename T> 
void Sorter<T>::quick_sort(int i, int j) {

	if (i < j) {
		int k = partition(i, j);
		quick_sort(i, k-1);
		quick_sort(k+1, j);
	}
}



*/


template<typename T>
void Sorter<T>::sort() {

	// Indirect sorting.
	std::sort(indexes.begin(), indexes.end(), *this);

	// Lets do the final permutation.
	for (int i=0; i < indexes.size(); i++) {
		permutation[ indexes[i]	] = i;
	}

	for(int i=0; i < values.size(); i++) {

		if (permutation[i] != i) {

			int prev_idx = i;
			int curr_idx = permutation[i];

			T prev_value = values[prev_idx];

			// We continue the cycle till the permutation[i] = i;
			// That is, the element is in its right-ful place.
			while (curr_idx != prev_idx) {

				T tmp_value;

				// Store the value of curr_idx in temp variable.
				// Assign curr_idx from prev_value;
				tmp_value = values[curr_idx];
				values[curr_idx] = prev_value;

				// Move the curr (index + value) to being prev (index + value)
				prev_idx = curr_idx;
				prev_value = tmp_value;

				// Move the next element forward by 1. 
				curr_idx = permutation[prev_idx];
				// Reset the permutation to itself.
				permutation[prev_idx] = prev_idx;

			}
		}
	}
}

template<typename T>
void indirect_sort(vector<T> &A) {

	Sorter<T> sorter_obj(A);
	sorter_obj.sort();
}

int main(int argc, const char **argv) {

	int arr[] = {100, 10, 50, 25, 45, 200, 150};
	int arr_len = (sizeof(arr)/sizeof(int));
	vector<int> vec(arr, (arr + arr_len));

	cout << "Unsorted array: ";
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ","));
	cout << endl;

	indirect_sort(vec);

	cout << "Sorted array: " ;
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ","));
	cout << endl;

}
