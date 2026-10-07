#include "ClsCourseManagementSystem.h"
#include "ClsStudent.h"
#include <iostream>
#include <string>
#include <vector>
#include "ClsCourse.h"
using namespace std;

// Students ==>  ال vector  اللي عندي
// student ==>  الطالب الجديد اللي مطلوب نضيفه
// existingstudent ==>  الطالب اللي موجود و مطلوب نفحصه

bool ClsCourseManagementSystem::AddStudent(ClsStudent student) 
{
	for (auto& existingstudent: Students ) // هنلف علي المجموعه اللي موجوده و نشوف الطلاب اللي فيها واحد واحد
	{
		if(existingstudent.GetId() == student.GetId())  // بنقارن رقم الطالب اللي موجود برقم الطالب الجديد
		{
			return false; // لو متكرر يبقا مش هنضيفه و نخرج من اللوب 
		}
	}
	Students.push_back(student); // لو جدسد هنضيف طالب جديد
		return true;
}

// Courses ==>  ال vector  اللي عندي 
// course  ==> الكورس الجديد اللي هضيفه 
// existingcourse ==> الكورس اللي موجود و مطلوب افحصه 

bool ClsCourseManagementSystem::AddCourse(ClsCourse course)
{
	for (auto& existingcourse : Courses)
	{
		if(existingcourse.GetCourseId() == course.GetCourseId())
		{
			return false;
		}
	}
	Courses.push_back(course);
	return true;
}

// Enrollments ==> ال vector اللي عندي 
// enrollment ==> التسجيل الجديد اللي هيتصاف عندي 
// existingenrollment ==>  التسجيل اللي موجود و مطلوب افحص هو مسجل قبل كدا ولا لا 

bool ClsCourseManagementSystem::AddEnrollments(ClsEnrollment enrollment)
{
	bool studentfound = false;
	for (auto& student : Students)
	{
		if (student.GetId() == enrollment.GetStudentId())  // بنقارن رقم الطالب الحالي برقم الطالب ف التسجيل الجديد
		{
			studentfound = true; // لو ملقنهوش يبقا هيسجل وخلاص ننهي اللوب 
			break;
		}
	}
	if (studentfound == false) // لو لقيناه متكرر يبقي نرفض التسجيل 
	{
		return false;
	}

	bool coursefound = false;
	for (auto& course : Courses)
	{
		if (course.GetCourseId() == enrollment.GetCourseId())
		{
			coursefound = true; // يعني لو انا مسجل الكورس دا خلاص هيعرفني اني مسجله قبل كدا و يخرج من التسجيل
			break;
		}
	}
	if (coursefound == false)
	{
		return false;
	}


	for (auto& existingenrollment : Enrollments)
	{
		if (existingenrollment.GetStudentId() == enrollment.GetStudentId() && existingenrollment.GetCourseId() == enrollment.GetCourseId())
		{
			return false;
		}
	}

	Enrollments.push_back(enrollment);
	return true;
}


// Display Information About Student
void ClsCourseManagementSystem::DisplayStudent()
{
	cout << "\n********** Students Info ************\n" << endl;
	for(auto& student : Students)
	{
		cout << " Student Id is : " << student.GetId() << " | Student Name Is : " << student.GetName() << endl;
	}
}

// Display Information About Course
void ClsCourseManagementSystem::DisplayCourse()
{
	cout << "******* Courses *********" << endl;
	for (auto& course : Courses)
	{
		cout << " Course Id is : " << course.GetCourseId() << " | Course Name Is : " << course.GetCourseName()  << "| Course Instructor Name Is : " << course.GetInstructorName() << endl;
	}
}

// Display Information About Enrollment
void ClsCourseManagementSystem::DisplayEnrollment()
{
	cout << "\n*********** Course Enrollments ***********\n" << endl;
	for (auto& enrollment : Enrollments )
		for(auto& course : Courses)
		{
			if( course.GetCourseId() == enrollment.GetCourseId() )
			{
				cout << " Student Id is : " << enrollment.GetStudentId() << " | Course Name is : "  << course.GetCourseName() << " | Course Grade Is : " << enrollment.GetStudentGrade() << endl;
				break;
			}
		}
}

void ClsCourseManagementSystem::DisplayStudentCourse(int studentid)
{

	bool found = false;
		cout << " \n  *********************** Enrollments Of Student No : " << studentid << " **********************" << endl;

	for (auto& enrollment : Enrollments)
	{

		if ( enrollment.GetStudentId() == studentid )
		{
		    found = true;
			cout << " Course Id Is : " << enrollment.GetCourseId() << " |  Student Grade Is : " << enrollment.GetStudentGrade() << endl;
		}
	}
	 if ( found == false )
	 {
		 cout << " No Enrollments For This Studeent " << endl;
	 }
}

void ClsCourseManagementSystem::DisplayCourseStudents(int CourseId )
{
	bool found = false;

	// For The Head
	string CourseName;
	for(auto& course:Courses)
	{
		if ( course.GetCourseId() == CourseId )
		{
			CourseName = course.GetCourseName();
			cout << " *********************** Enrollments Of Course : \" " << CourseName << " \" Is :  **********************" << endl;
			break;
		}
	}

	// For Display List Of Student In Specific Course
	for ( auto& enrollment : Enrollments)
	{
		if ( enrollment.GetCourseId() == CourseId )
		{
			for ( auto& student : Students)
			{
				if ( student.GetId() == enrollment.GetStudentId() )
				{
					found = true;
					cout << " Student Name Is : " << student.GetName() << " |  Student Grade Is : " << enrollment.GetStudentGrade() << endl;
					break;
				}
			}

		}
	}
	// For No Enrollments
	if (found == false)
	{
		cout << " No Enrollments For This Course " << endl;
	}
}

bool ClsCourseManagementSystem::UpdateStudentGrade(int StudentId, int CourseId, float NewGrade)
{
	for ( auto& enrollment : Enrollments)
	{
		if ( enrollment.GetStudentId() == StudentId && enrollment.GetCourseId() == CourseId)
		{
			enrollment.SetStudentGrade(NewGrade);
			return true;
		}
	}
	return false;
}

bool ClsCourseManagementSystem::RemoveEnrollment(int StudentId, int CourseId)
{
	for (auto it=Enrollments.begin() ; it != Enrollments.end() ; ++it)
	{
		if ( it->GetStudentId()== StudentId && it->GetCourseId() == CourseId )
		{
			Enrollments.erase(it);
			return true;
		}
	}
	return false;
}
