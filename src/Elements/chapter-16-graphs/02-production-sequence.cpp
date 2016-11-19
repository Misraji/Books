#include <stdexcept>
using std::runtime_error;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

#include <queue>
using std::queue;

#include <utility>
using std::pair;
using std::make_pair;

int find_seq_len(unordered_set<string> dict, string start, string end) {

	queue<pair<string, int> > visit_queue;

	visit_queue.push(make_pair(start, 0));
	dict.erase(start);

	while(visit_queue.empty() == false) {

		pair<string, int> curr(visit_queue.front());

		if (curr.first == end) {
			return curr.second;
		}

		string tmp(curr.first);

		for(int i=0; i < curr.first.size(); i++) {

			for(int j=0; j < 26; j++) {
		
				tmp[i] = 'a' + j;

				auto itr = dict.find(tmp);

				if (itr != dict.end()) {
					dict.erase(tmp);
					visit_queue.push(make_pair(tmp, (curr.second+1)));
				}

				tmp[i] = curr.first[i];
			}
		}

		visit_queue.pop();
	}

	return -1;
}

int main(int argc, const char **argv) {

}
