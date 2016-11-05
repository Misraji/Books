#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

void rotate(vector<vector<int> > &matrix, int i, int j) {

	int N = matrix.size();
	int tmp = matrix[i][j];

	matrix[i][j] = matrix[N-j-1][i];
	matrix[N-j-1][i] = matrix[N-i-1][N-j-1];
	matrix[N-i-1][N-j-1] = matrix[j][N-i-1];
	matrix[j][N-i-1] = tmp;
}

void rotate_matrix(vector<vector<int> > &matrix) {

	int N = matrix.size();
	for (int i=0; i < N/2; i++) {
		for (int j=i ; j < (N - i - 1); j++) {
			rotate(matrix, i, j);
		}
	}
}

void print_matrix(vector<vector<int> > &matrix) {
	for(int i=0; i < matrix.size(); i++) {
		vector<int> &curr_row = matrix[i];
		for(int j=0; j < curr_row.size(); j++) {
			cout << curr_row[j] << ",";
		}
		cout << endl;
	}
	cout << endl;
}

void fill_matrix(vector<vector<int> > &matrix, const int N) {
	
	int counter = 1;
	matrix.clear();

	for(int i = 0; i < N; i++) {
		vector<int> new_row;
		matrix.push_back(new_row);

		for(int j = 0; j < N; j++) {
			matrix[i].push_back(counter++);
		}
	}
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	vector<vector<int> > matrix;
	fill_matrix(matrix,3);

	cout << "Original matrix" << endl;
	print_matrix(matrix);
	rotate_matrix(matrix);
	cout << "Rotated matrix" << endl;
	print_matrix(matrix);


	fill_matrix(matrix,5);

	cout << "Original matrix" << endl;
	print_matrix(matrix);
	rotate_matrix(matrix);
	cout << "Rotated matrix" << endl;
	print_matrix(matrix);
}
