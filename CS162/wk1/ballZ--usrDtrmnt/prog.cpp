#include <iostream>
#include "mult_div.h"
#include <stdlib.h>
#include <cctype>
#include <cstring>

using namespace std;

bool num_check(char* str) {
	for (int i = 0; i < strlen(str); i++) {
		if(!(isdigit(str[i]))) {
			return false;
		}
	}
	return true;
}

int main(int argc, char **argv) {

	if (!(argc == 3)) {
		cout << "Please enter 2 numbers." << endl;
		exit(EXIT_FAILURE);
	}

	if (!(num_check(argv[1]))) {
		cout << "Invalid input." << endl;
		exit(EXIT_FAILURE);
	}

	if (!(num_check(argv[2]))) {
		cout << "Invalid input." << endl;
		exit(EXIT_FAILURE);
	}

	int rows = atoi(argv[1]);
	int columns = atoi(argv[2]);
	struct mult_div_values** arr = init_array(rows, columns);

	fill_array(arr, rows, columns);
	print_mult_array(arr, rows, columns);
	cout << endl;
	print_div_array(arr, rows, columns);
	int answer;

	cout << "Would you like to use a different size matrix? (0 for no, 1 for yes)" << endl;
	cin >> answer;

	if (answer == 0) {
		return 0;
	}

	else {
		cout << "Enter a new number of rows: ";
		cin >> rows;
		cout << "Enter a new number of columns: ";
		cin >> columns;

		struct mult_div_values** arr = init_array(rows, columns);
		fill_array(arr, rows, columns);
		print_mult_array(arr, rows, columns);
		cout << endl;
		print_div_array(arr, rows, columns);
	}

	return 0;

}