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
List<T>* list_sum(List<T> *head1, List<T> *head2) {

	// Creating dummy head to ease implementation.
	T carry = T();
	List<T> *dummy_head = new(List<T>);
	List<T> *curr = dummy_head;

	while(head1 || head2 || carry)  {
		T sum = carry;

		if (head1) {
			sum += head1->data;
		}

		if (head2) {
			sum += head2->data;
		}
		
		List<T> *new_node = new List<T>((sum % 10), NULL, curr);
		curr->next = new_node;

		carry = (sum/10);
		curr = curr->next;

		if (head1) {
			head1 = head1->next;
		}

		if (head2) {
			head2 = head2->next;
		}
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
