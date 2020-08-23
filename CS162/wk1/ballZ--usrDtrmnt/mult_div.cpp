#include "./mult_div.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

void fill_array(struct mult_div_values **arr, int rows, int columns) { 
	float num1, num2;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			num1 = i + 1;
			num2 = j + 1;
			arr[i][j].mult = num1*num2;
			arr[i][j].div = num1/num2;
		}
	}
}

void print_mult_array(struct mult_div_values **arr, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << arr[i][j].mult;
			cout << "\t";
		}
		cout << endl;
	}
}

void print_div_array(struct mult_div_values **arr, int rows, int columns) {
	cout << fixed;
	cout << setprecision(2);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << arr[i][j].div;
			cout << "\t";
		}
		cout << endl;
	}
}

struct mult_div_values** init_array(int rows, int columns) {
	struct mult_div_values** table = new struct mult_div_values* [rows];
	for (int i = 0; i < rows; i++) {
		table[i] = new struct mult_div_values [columns];
	}
	return table;
}