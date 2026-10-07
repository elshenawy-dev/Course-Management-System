#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ClsStudent.h"
#include "ClsCourse.h"
#include "ClsEnrollment.h"
using namespace std;
class ClsCourseManagementSystem
{
private:
	vector< ClsStudent > Students;
	vector< ClsCourse > Courses;
	vector< ClsEnrollment > Enrollments;

public:
	bool AddStudent(ClsStudent student);
	bool AddCourse(ClsCourse course);
	bool AddEnrollments(ClsEnrollment enrollment);

	void DisplayStudent();
	void DisplayCourse();
	void DisplayEnrollment();

	void DisplayStudentCourse(int StudentId);

	void DisplayCourseStudents(int CourseId );
	
	bool UpdateStudentGrade(int StudentId, int CourseId, float NewGrade);

	bool RemoveEnrollment(int StudentId, int CourseId);

};

