#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

bool uniq_chars_01(const string &word) {
	
	const int NUM_CHARS = 256;
	bool char_map[NUM_CHARS];

	for (int i=0; i < NUM_CHARS; i++) {
		char_map[i] = false;
	}

	for (int i=0; i < word.size(); i++) {
		char curr_char = word[i];

		if (char_map[curr_char]) {
			return false;
		}
		char_map[curr_char] = true;
	}

	return true;
}

bool uniq_chars_02(string &word) {
	
	if (word.empty()) {
		return true;
	}

	sort(word.begin(), word.end());
	
	char prev_char = word[0];
	char curr_char = 0;

	for(int i=1; i < word.size(); i++) {
		curr_char = word[i];

		if (prev_char == curr_char) {
			return false;
		}

		prev_char = curr_char;
	}
	return true;
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");
	cout << "uniq_chars_01(Hello World!!!) = " << uniq_chars_01(output) << endl;
	cout << "uniq_chars_01(Hello World!!!) = " << uniq_chars_01(output) << endl;

	string test("uniq");
	cout << "uniq_chars_01(uniq) = " << uniq_chars_01(test) << endl;
	cout << "uniq_chars_02(uniq) = " << uniq_chars_02(test) << endl;
}
