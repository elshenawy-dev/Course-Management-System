#include <iostream>
#include <string>
#include <limits>
#include "ClsStudent.h"
#include "ClsCourse.h"
#include "ClsEnrollment.h"
#include "ClsCourseManagementSystem.h"
using namespace std;

 int ReadInt(string message)
 {
    int number = 0;

     while (true)
     {
       cout << message;

       if (cin >> number)
       {
        return number;
       }

       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');

       cout << "Invalid input. Please enter a number.\n";
     }
 }

 float ReadGrade(string massage)
 {
     float number = 0;
     while(true)
     {
         cout << massage;
         if (cin>>number)
         {
             return number;
         }
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');

         cout << "Invalid input. Please enter a number.\n";

     }
 }

void ReadAndAddStudent(ClsCourseManagementSystem& management)
{
    string StudentName;

    //int StudentId =0 ;
    //cout << "\n Enter Student ID : ";
    //cin >> StudentId;
    int StudentId = ReadInt("Enter Student ID: ");

    cout << " Enter Student Name : ";
    getline(cin >>ws, StudentName);


    ClsStudent student(StudentId, StudentName);
    if (management.AddStudent(student) )
    {
        cout << "\n Student Is Added. " << endl;
    }
    else
    {
        cout << "\n Student No : " << StudentId<<" Is AlreAdy Added Before. \n";
    }
    //management.DisplayStudent();
}

void ReadAndAddCourse(ClsCourseManagementSystem& management)
{
    string CourseName;
    string InstructorName;

    //int CourseId = 0;
    //cout << "\n Enter Course ID : ";
    //cin >> CourseId;
    int CourseId = ReadInt("Enter Course ID: ");

    cout << " Enter Course Name : ";
    getline(cin >> ws, CourseName);

    cout << " Enter Instructor Name : ";
    getline(cin >> ws, InstructorName);

    ClsCourse course(CourseId, CourseName, InstructorName);
    if (management.AddCourse(course))
    {
        cout << "\n Course Is Added. " << endl;
    }
    else
    {
        cout << "\n Course No : " << CourseId << " Is AlreAdy Added Before. \n";
    }
    //management.DisplayCourse();


}

void ReadAndAddEnrollment(ClsCourseManagementSystem& management)
{

    //int StudentId = 0;
    //cout << "\n Enter Student ID : ";
    //cin >> StudentId;
    int StudentId = ReadInt("Enter Student ID: ");

    //int CourseId = 0;
    //cout << "\n Enter Course ID : ";
    //cin >> CourseId;
    int CourseId = ReadInt("Enter Course ID: ");

    //float StudentGrade = 0 ;
    //cout << "\n Enter Student Grade : ";
    //cin >> StudentGrade;
    float  StudentGrade = ReadGrade("\n Enter Student Grade : ");

    ClsEnrollment enrollment(StudentId, CourseId, StudentGrade);
    if (management.AddEnrollments(enrollment))
    {
        cout << "\n Enrollment Succesed " << endl;
    }
    else 
    {
        cout << "\n Enrollment Failed" << endl;
    }
    //management.DisplayEnrollment();
}
 
void DisplayMenu()
{
    cout << " 1. Add Student " << endl;

    cout << " 2. Add Course " << endl;

    cout << " 3. Add Enrollment " << endl;

    cout << " 4. Display Student " << endl;

    cout << " 5. Display Course " << endl;

    cout << " 6. Display Enrollment " << endl;

    cout << " 7. Update Grade " << endl;

    cout << " 8. Remove Enrollment " << endl;

    cout << " 9. Display Student Courses " << endl;

    cout << " 10. Display Course Students " << endl;

    cout << " 0. Exit " << endl;
}

void ReadAndUpdateGrade(ClsCourseManagementSystem& management)
{

    //int StudentId = 0;
    //cout << " Enter Student ID : " << endl;
    //cin >> StudentId;
    int StudentId = ReadInt("Enter Student ID: ");


    //int CourseId = 0;
    //cout << " Enter Course ID : " << endl;
    //cin >> CourseId;
    int CourseId = ReadInt("Enter Course ID: ");

    //float NewGrade = 0;
    //cout << " Enter New Grade : " << endl;
    //cin >> NewGrade;
    float NewGrade = ReadGrade("Enter New Grade : ");

    if (management.UpdateStudentGrade(StudentId, CourseId, NewGrade))
    {
        cout << "\n Grade Update Is Succesed" << endl;
    }
    else
    {
        cout << "\n Grade Update Is Failed" << endl;
    }
}

void ReadAndRemoveEnrollment(ClsCourseManagementSystem& management)
{
    //int StudentId = 0;
    //int CourseId = 0;

    //cout << "\n Enter Student ID : ";
    //cin >> StudentId;

    //cout << "\n Enter Course ID : ";
    //cin >> CourseId;
    int StudentId = ReadInt("Enter Student ID: ");

    int CourseId = ReadInt("Enter Course ID: ");

    if (management.RemoveEnrollment(StudentId, CourseId))
    {
        cout << "\n Remove Enrollment Is Succesed " << endl;
    }
    else
    {
        cout << "\n Remove Enrollment Is Failed" << endl;
    }
}

void ReadAndDisplayStudentCourses(ClsCourseManagementSystem& management)
{
    //int StudenId = 0;

    //cout << " Enter ID Of Student : " << endl;
    //cin >> StudenId;
    int StudentId = ReadInt("Enter Student ID: ");

    management.DisplayStudentCourse(StudentId);
}

void ReadAndDisplayCourseStudents(ClsCourseManagementSystem& management)
{
    //int CourseId = 0;
    //cout << " Enter Course ID : " << endl;
    //cin >> CourseId;
    int CourseId = ReadInt("Enter Course ID: ");
    management.DisplayCourseStudents(CourseId);
}


int main ()
{
    ClsCourseManagementSystem management; // كدا انا استدعيت السيستيم 
    int choise = 0;
    do
    {
        

        system("cls");
        DisplayMenu();
        cout << "\n Enter Your Choise ";
        if (!(cin >> choise))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choise = -1;

            cout << "Please enter a number. Press Enter to try again.";
            cin.get();

            continue;
        }        system("cls");

        
        switch(choise)
        {
        case 1:
            ReadAndAddStudent(management);
            break;
        case 2:
            ReadAndAddCourse(management);
            break;
        case 3:
            ReadAndAddEnrollment(management);
            break;
        case 4:
            management.DisplayStudent();
            break;
        case 5:
            management.DisplayCourse();

            break;
        case 6:
            management.DisplayEnrollment();
            break;
        case 7:
            ReadAndUpdateGrade(management);

            break;
        case 8:
            ReadAndRemoveEnrollment(management);
            break;
        case 9:
            ReadAndDisplayStudentCourses(management);
            break;
        case 10:
            ReadAndDisplayCourseStudents(management);
            break;
        case 0:
            cout << "\n Thank You For Using My System  \n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n" << endl;
            break;
        }
        // for delede chat and start new
        if ( choise != 0 )
        {
            cout << " \n Press Enter To Return To Menu ..... \n";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }  

    } while (choise != 0); // menu 
}