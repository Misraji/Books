#include <stdexcept>
using std::runtime_error;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <set>
using std::set;

#include <queue>
using std::queue;

template<typename T>
struct Graph {
	public:
		T data;
		vector<Graph<T>*> adjacent;
};

template<typename T> 
class Search {
	public:
		Search(Graph<T> *r) : root(r) {}
		bool find_node(Graph<T> *n);

	private:
		bool find_node_rec(T data);

		bool been_visited(Graph<T> *n);
		bool curr_visiting(Graph<T> *n);

		Graph<T> *root;

		queue<Graph<T>*> node_queue;
		set<Graph<T>*> visited;
		set<Graph<T>*> visiting;
};

template<typename T>
bool Search<T>::been_visited(Graph<T> *n) {
	return (visited.count(n) > 0);
}

template<typename T>
bool Search<T>::curr_visiting(Graph<T> *n) {
	return (visiting.count(n) > 0);
}

template<typename T>
bool Search<T>::find_node(Graph<T> *n) {

	// Resetting internal data;
	node_queue = queue<T>();
	visited = set<Graph<T>*>();
	visiting = set<Graph<T>*>();

	node_queue.push(root);
	visiting.insert(root);

	while (node_queue.empty() == false) {

		Graph<T> *curr = node_queue.top();
		node_queue.pop();

		for(auto itr = curr->adjacent.begin(); itr != curr->adjacent.end(); itr++) {

			Graph<T> *child = *itr;

			if (been_visited(child) || curr_visiting(child)) {
				// Dont do anything. Just skip.
			} else {

				if (child == n) {
					return true;
				}

				node_queue.push(child);
				visiting.insert(child);
			}
		}

		visiting.erase(curr);
		visited.insert(curr);
	}

	return false;
}

int main(int argc, const char **argv) {

}
