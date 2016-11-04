#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

void remove_dup(string &str) {

	int i = 0;
	int str_size = str.size();
	int num_dups = 0;

	while (i < (str_size - num_dups)) {

		char curr_char = str[i];

		int j = i+1;
		while (j < (str_size - num_dups)) {
			char next_char = str[j];

			if (curr_char == next_char) {

				// Shift all characters forward by 1 space.
				for (int k = j; k < (str_size - num_dups - 1); k++) {
					str[k] = str[k+1];	
				}

				// Increase num_dups to affect chars checked.
				num_dups++;

				// NOTE: Do NOT increase j. We need to restart checking from
				// j

			} else {

				// This char was safe. Skip it.
				j++;
			}
		}

		// Removed all references of ith character.
		i++;
	}

	str.resize((str_size - num_dups));
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
