#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::swap;

void remove_dup(string &str) {

	if (str.empty() || (str.size() < 2)) {
		return;
	}

	int num_uniq_chars = 1;

	for(int i = 1; i < str.size(); i++) {

		char curr_char = str[i];

		int j = 0;
		for (j = 0; j < num_uniq_chars; j++) {
				
			char uniq_char = str[j];
			if (uniq_char == curr_char) {
				// because of this j != num_uniq_chars in the if-statement outside this
				// loop.
				break;
			}
		}

		if (j == num_uniq_chars) {
			// curr_char was encountered for the first time. 
			swap(str[num_uniq_chars], str[i]);
			num_uniq_chars++;
		}
	}

	str.resize(num_uniq_chars);
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");
	cout << "remove_dup(" << output << ") = ";
	remove_dup(output);
	cout << output << endl;

	string test1("aaaaaaaaaaaaaaaaaaaaaaaaaa");
	cout << "remove_dup(" << test1 << ") = ";
	remove_dup(test1);
	cout << test1 << endl;

	cout << "remove_dup(" << test1 << ") = ";
	remove_dup(test1);
	cout << test1 << endl;
}
