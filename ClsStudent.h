#pragma once
#include <iostream>
#include <string>
using namespace std;

class ClsStudent
{
private:
	int Id;
	string Name;

public:

	int GetId();

	void SetName(string name);
	string GetName();

	ClsStudent(int id, string name);
};

