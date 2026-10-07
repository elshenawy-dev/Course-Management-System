#pragma once
#include <iostream>
#include <string>
using namespace std;

class ClsCourse
{
private:
	int CourseId;
	string CourseName;
	string InstructorName;

public:

	int GetCourseId();

	void SetCourseName(string coursename);
	string GetCourseName();

	void SetInstructorName(string instructorname);
	string GetInstructorName();

	ClsCourse(int courseid, string CourseName, string InstructorName);
};

