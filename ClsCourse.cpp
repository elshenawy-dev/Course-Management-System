#include "ClsCourse.h"
#include <iostream>
#include <string>
using namespace std;


int ClsCourse::GetCourseId()
{
    return CourseId;
}

void ClsCourse::SetCourseName(string coursename)
{
    CourseName = coursename;
}
string ClsCourse::GetCourseName()
{
    return CourseName;
}

void ClsCourse::SetInstructorName(string instructorname)
{
    InstructorName = instructorname;
}
string ClsCourse::GetInstructorName()
{
    return InstructorName;
}

ClsCourse::ClsCourse(int courseid, string coursename, string instructorname)
{
    CourseId = courseid;
    CourseName = coursename;
    InstructorName = instructorname;
}
