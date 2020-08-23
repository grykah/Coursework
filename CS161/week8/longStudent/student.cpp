#include <iostream>
#include <sstream>
#include <string>
#include "student.hpp"
#include "getInput.hpp"
#include "cutOutput.hpp"

int main()
{
	//Artifacts
	int artifactCount;
	std::cin >> artifactCount;
	std::cin.ignore(1);
	int* points = new int[artifactCount];
	int* weights = new int[artifactCount];
	getArtifacts(artifactCount, points, weights);

	//Students
	int studentCount;
	std::cin >> studentCount;
	std::cin.ignore(1);
	student* students = new student[studentCount];
	getStudents(studentCount, students);

	//Scores
	int scoreCount;
	std::cin >> scoreCount;
	std::cin.ignore(1);
	getScores(scoreCount, studentCount, artifactCount, students, points, weights);
	
	std::cout << "TOTAL SCORES" << std::endl;
	for (int i = 0; i < studentCount; i++)
	{
		std::cout << students[i].id << " " << students[i].name << " " << students[i].total << std::endl;
	}

	//Cutpoints
	int cutCount;
	std::cin >> cutCount;
	std::cin.ignore(1);
	float* cutPoints = new float[4];

	for (int i = 1; i <= cutCount; i++)
	{
		std::cout << "CUTPOINT SET " << i << std::endl;
		getCuts(cutPoints);
		for (int k = 0; k < studentCount; k++)
		{
			if (students[k].option == 'P')
			{
				passOutput(k, students, cutPoints);
			}
			else
			{
				gradeOutput(k, students, cutPoints);
			}
		}
		std::cin.ignore(1);
	}

	delete[] cutPoints;
	delete[] points;
	delete[] weights;
	delete[] students;

    return 0;
}