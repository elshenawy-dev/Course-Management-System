
#include "ClsStudent.h"
#include <iostream>
#include <string>
using namespace std;

int ClsStudent::GetId()
{
    return Id;
}

void ClsStudent::SetName(string name)
{
    Name = name;
}
string ClsStudent::GetName()
{
    return Name;
}

ClsStudent::ClsStudent(int id, string name)
{
    Id = id;
    Name = name;
}
