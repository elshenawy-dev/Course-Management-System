#pragma once
#include <iostream>
#include <string>
using namespace std;

class ClsEnrollment
{
private:
	int StudentId;
	int CourseId;
	float StudentGrade;

public:
	int GetStudentId();

	int GetCourseId();

	void SetStudentGrade(float studentgrade);
	float GetStudentGrade();

	ClsEnrollment(int studentid, int courseid, float studentgrade);
};

