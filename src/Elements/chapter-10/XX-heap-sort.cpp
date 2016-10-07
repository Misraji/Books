#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::swap;
using std::copy;

#include <iterator>
using std::ostream_iterator;

template<typename T>
struct Heap {
	public:
		Heap(vector<T> &a) : values(a), heap_len(0) { }
		vector<T> &values;
		int heap_len;

		void max_heapify(int parent);
		void create_heap();
		void sort();
};

inline int parent(int i) {
	return i/2;
}

inline int left_child(int i) {
	return 2*i;
}

inline int right_child(int i) {
	return ((2*i) + 1);
}

template<typename T>
void Heap<T>::max_heapify(int parent) {

	int left = left_child(parent);
	int right = right_child(parent);
	int max ;

	max = parent;
	if ( (left < heap_len) && 
		 (values[left] > values[parent])
	) {
		max = left;	
	}

	if ( (right < heap_len) && 
		 (values[right] > values[max])
	) {
		max = right;	
	}

	if (max != parent) {
		swap(values[max], values[parent]);
		return max_heapify(max);
	}
}

template<typename T>
void Heap<T>::create_heap() {

	heap_len = values.size();

	for(int i = heap_len/2; i >= 0; i--) {
		max_heapify(i);
	}
}

template<typename T>
void Heap<T>::sort() {
	// assumes that the heap is valid.
	
	for(int i = (heap_len-1); i > 0; i--) {
		swap(values[0], values[i]);
		heap_len--;
		max_heapify(0);
	}
}


template<typename T>
void heap_sort(vector<T> &values) {

	vector<T> result;
	Heap<T> h(values);

	h.create_heap();
	h.sort();
}

int main(int argc, const char **argv) {

	int arr1[] = {10, 1, 300, 24, 5, 0};
	int arr1_len = (sizeof(arr1) / sizeof(int));
	vector<int> vec1(arr1, (arr1 + arr1_len));

	cout << "original array : " ;
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, ","));
	cout << endl;

	heap_sort(vec1);
	cout << "sorted array : " ;
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, ","));
	cout << endl;
}
