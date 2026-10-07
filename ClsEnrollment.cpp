#include "ClsEnrollment.h"

int ClsEnrollment::GetStudentId()
{
    return StudentId;
}

int ClsEnrollment::GetCourseId()
{
    return CourseId;
}

void ClsEnrollment::SetStudentGrade(float studentgrade)
{
    StudentGrade = studentgrade;
}
float ClsEnrollment::GetStudentGrade()
{
    return StudentGrade;
}

ClsEnrollment::ClsEnrollment(int studentid, int courseid, float studentgrade)
{
    StudentId = studentid;
    CourseId = courseid;
    StudentGrade = studentgrade;
}
