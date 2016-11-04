#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

void replace_space(string &line) {

	int num_spaces = 0;
	int i = 0;
	int end = 0;

	for(i=0; i < line.size(); i++) {
		if (line[i] == ' ') {
			num_spaces++;
		}
	}

	i = line.size()-1;
	line.resize(line.size() + (2*num_spaces));
	end = line.size() - 1;

	for (; i >= 0; i--) {
		if (line[i] == ' ') {
			line[end--] = '0';
			line[end--] = '2';
			line[end--] = '%';

		} else {
			line[end--] = line[i];
		}
	}
}

int main(int argc, const char **argv) {

	string output(" Hel lo world! ! ! ");

	cout << "replace_space(" << output << ") = ";
	replace_space(output);
	cout << output << endl;
}
