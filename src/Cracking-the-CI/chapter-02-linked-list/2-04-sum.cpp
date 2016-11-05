#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <stdexcept>
using std::runtime_error;

template<typename T>
struct List {
	public:
		T data;
		List<T> *next, *prev;

		List() : data(-1), next(NULL), prev(NULL) {}
		List(T d, List<T> *n, List<T> *p): data(d), next(n), prev(p) {}
};

template<typename T> 
List<T>* copy_list(List<T> *head, List<T> *curr, T carry) {

	while (head) {
		T sum = head->data + carry;
		
		List<T> *new_node = new List<T>((sum % 10), NULL, curr);
		curr->next = new_node;

		carry = (sum/10);
		curr = curr->next;
		head = head->next;
	}

	if (carry) {
		List<T> *new_node = new List<T>(carry, NULL, curr);
		curr->next = new_node;
		curr = curr->next;
	}

	return curr;
}

template<typename T>
List<T>* list_sum(List<T> *head1, List<T> *head2) {

	if ((head1 == NULL) && (head2 == NULL) ) {
		return NULL;

	} else if ((head1 == NULL) && head2) {
		return head2;

	} else if (head1 && (head2 == NULL)) {
		return head1;
	}

	// Now both head1 and head2 are NON-NULL: Hence sum will have atlead 1
	// Node

	// Creating dummy head to ease implementation.
	T carry = T();
	List<T> *dummy_head = new(List<T>);
	List<T> *curr = dummy_head;

	while(head1 && head2) {
		T sum = head1->data + head2->data + carry;
		
		List<T> *new_node = new List<T>((sum % 10), NULL, curr);
		curr->next = new_node;

		carry = (sum/10);
		curr = curr->next;

		head1 = head1->next;
		head2 = head2->next;
	}

	if (head1) {
		curr = copy_list(head1, curr, carry);

	} else if (head2) {
		curr = copy_list(head2, curr, carry);

	} else if (carry) {
		curr = copy_list<int>(NULL, curr, carry);
	}

	// Remove dummy head and return original head;
	List<T> *head = dummy_head->next;
	delete(dummy_head);
	head->prev = NULL;

	return head;
}

List<int>* create_list(int val) {
	
	List<int> *dummy_head = new List<int>(-1, NULL, NULL);
	List<int> *curr = dummy_head;

	while (val) {
		List<int> *tmp = new List<int>((val % 10), NULL, curr);
		curr->next = tmp;
		curr = curr->next;
		val = val/10;
	}

	// Remove dummy head and return original head;
	List<int> *head = dummy_head->next;
	delete(dummy_head);
	head->prev = NULL;

	return head;

}

int get_value(List<int> *head) {
	
	int result = 0;
	int place_val = 1;

	while(head) {
		result = result  + (head->data * place_val);
		place_val *= 10;
		head = head->next;
	}

	return result;
}

void test_sum(int val1, int val2) {
	
	List<int> *list1 = create_list(val1);
	List<int> *list2 = create_list(val2);

	List<int> *sum = list_sum(list1, list2);
	int result = get_value(sum);

	cout << "list_sum(" << val1 << " , " << val2 << ") = " << result << endl;
}

int main(int argc, const char **argv) {

	test_sum(1, 1);
	test_sum(100, 1);
	test_sum(1, 100);
	test_sum(15,25);
	test_sum(99, 1);
	test_sum(1, 99);
}
