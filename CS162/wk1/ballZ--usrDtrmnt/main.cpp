#include "./mult_div.h"
#include <string>


using namespace std;

bool is_valid_dimensions(int &m, int &n) {
	if (m <= 0) {
		cout << "You did not input a valid row." << endl;
		cout << "Please enter an integer greater than 0 for the rows" << endl;
		//cin >> m;
	}

	if (n <= 0) {
		cout << "you did not input a valid column" << endl;
		cout << "Please enter an integer greater than 0 for the column" << endl;
		//cin >> n;	
	}		
}

mult_div_values** create_table(int rows, int cols) {
	mult_div_values** table;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			table[i][j] = new mult_div_values;
		}
	}
	return table;
}


void set_mult_values(mult_div_values **table, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			table.mult[i][j] = (i+1) * (j+1);
			cout << table.mult[i][j] << " ";	
		}
		cout << endl;
	}
}


void set_div_value(mult_div_values **table, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			table.div[i][j] = (i+1) / (j+1);
			cout << table.div[i][j] << " ";
		}
		cout << endl;
	}
}


void delete_table(mult_div_values ***table, int m) {
	for (int i = 0; i < m; i++) {
		delete *table;
	}
}


int main (int argc, char *argv[]) {
	int rows = atoi(argv[1]);
	int cols = atoi(argv[2]);
	mult_div_values** table;
	if (argc < 3) {
		cout << "Please enter the correct number of arguments" << endl;
	}
	is_valid_dimensions(rows, cols);
	table = mult_div_values** create_table(rows, cols);
	set_mult_values(table, rows, cols);
	set_div_value(table, rows, cols);
	delete_table(table, rows);

}