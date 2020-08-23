#include <iostream>
#include <string>
#include "student.hpp"

void getArtifacts(int artifactCount, int points[], int weights[])
{
	int temp;
	for (int i = 0; i < artifactCount; i++)
	{
		std::cin >> temp;
		points[i] = temp;
	}
	std::cin.ignore(1);
	for (int i = 0; i < artifactCount; i++)
	{
		std::cin >> temp;
		weights[i] = temp;
	}
	std::cin.ignore(1);
}

void getStudents(int studentCount, student students[])
{
	int tempId;
	std::string tempName;
	char tempOption;

	for (int i = 0; i < studentCount; i++)
	{
		std::cin >> tempId >> tempOption;
		std::cin.ignore(1);
		std::getline(std::cin,tempName);
		student s = {tempId, tempOption, tempName, 0.0};
		students[i] = s;
	}
}

void getScores(int scoreCount, int studentCount, int artifactCount, student students[], int points[], int weights[])
{
	int num, tempId;
	for (int i = 0; i < scoreCount; i++)
	{
		std::cin >> tempId;
		for (int k = 0; k < studentCount; k++)
		{
			if (students[k].id == tempId)
			{
				for (int j = 0; j < artifactCount; j++)
				{
					std::cin >> num;
					students[k].total = students[k].total + (num/static_cast<float>(points[j]))*weights[j];
				}
			}
			else if (students[k].id != tempId && k == studentCount-1)
			{
				std::cin.ignore(10000, '\n');
			}
		}

	}
}