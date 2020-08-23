struct mult_div_values {
	int mult;
	float div;
};

void fill_array(struct mult_div_values **arr, int rows, int columns);
void print_mult_array(struct mult_div_values **arr, int rows, int columns);
void print_div_array(struct mult_div_values **arr, int rows, int columns);
struct mult_div_values** init_array(int rows, int columns);
bool num_check(char* str);