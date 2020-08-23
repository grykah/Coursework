#include <iostream>
#include <string>
#include "student.hpp"

void getCuts(float cutPoints[])
{
	float c;
	for (int k = 0; k < 4; k++)
	{
		std::cin >> c;
		cutPoints[k] = c;
	}
}

void passOutput(int k, student students[], float cutPoints[])
{
	if (students[k].total < cutPoints[2])
	{
		std::cout << students[k].id << " " << students[k].name << " F" << std::endl;
	}
	else
	{
		std::cout << students[k].id << " " << students[k].name << " P" << std::endl;
	}
}

void gradeOutput(int k, student students[], float cutPoints[])
{
	if (students[k].total >= cutPoints[0])
	{
		std::cout << students[k].id << " " << students[k].name << " A" << std::endl;
	}
	else if (students[k].total >= cutPoints[1])
	{
		std::cout << students[k].id << " " << students[k].name << " B" << std::endl;
	}
	else if (students[k].total >= cutPoints[2])
	{
		std::cout << students[k].id << " " << students[k].name << " C" << std::endl;
	}
	else if (students[k].total >= cutPoints[3])
	{
		std::cout << students[k].id << " " << students[k].name << " D" << std::endl;
	}
	else
	{
		std::cout << students[k].id << " " << students[k].name << " F" << std::endl;
	}
}