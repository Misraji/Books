#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <set>
using std::set;

void zero_matrix(vector<vector<int> > &matrix) {

	set<int> zero_dim_set;

	for(int i=0; i < matrix.size(); i++) {
		vector<int> &curr_row = matrix[i];

		for(int j=0; j < curr_row.size(); j++) {
			if (curr_row[j] == 0) {
				zero_dim_set.insert(i);			
				zero_dim_set.insert(j);			
			}
		}
	}

	for(int i=0; i < matrix.size(); i++) {
		vector<int> &curr_row = matrix[i];

		for(int j=0; j < curr_row.size(); j++) {
			if ((zero_dim_set.count(i) > 0) || 
				(zero_dim_set.count(j) > 0) ) {
				curr_row[j] = 0;
			}
		}
	}
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}
