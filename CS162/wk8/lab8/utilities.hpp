/*********************************************************************
 ** Program Filename: utilities.hpp
 ** Author: Hailey Wilder
 ** Date: 3/2/17
 ** Description: Header for declaring functions in the utilities 
 **				 namespace which provides I/O validation.            
 ** Input: std::cin
 ** Output: std::cout
 *********************************************************************/

#include <fstream>
#include <string>

namespace utilities
{
    double get_valid_double();
    double get_valid_double_in_range(const double low, const double high);
    int get_valid_int();
    int get_valid_int_in_range(const int low, const int high);

    std::ifstream& open_in_file(std::ifstream& fs, std::string fn);
    std::ofstream& open_out_file(std::ofstream& fs, std::string fn);
}
