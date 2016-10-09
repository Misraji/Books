#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

void print_char_count(string s) {
	// Argument checks
	if (s.empty()) {
		cout << "string is empty." << endl;
		return;
	}
	
	// All variable initializations.
	sort(s.begin(), s.end());

	auto itr = s.begin();
	int curr_count = 1;
	char curr_char =  *itr;

	for(++itr; itr != s.end(); itr++) {
		if (*itr == curr_char) {
			curr_count++;

		} else {
			cout << "< '" << curr_char << "', " << curr_count << " >" << endl;
			curr_count = 1;
			curr_char = *itr;
		}	
	}
	cout << "< '" << curr_char << "', " << curr_count << " >" << endl;
	cout << endl;
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");
	print_char_count(output);
}
