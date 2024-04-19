#pragma once

#include"Employee.h"

class ITManager :public Employee
{
public:
	//Default Constructor
	ITManager()
	{
		cout << "ITManager() Called" << endl;
	}
	//Parameterized Constructor
	ITManager(int Empnum, const char* name) :Employee(Empnum, name), Person(name)
	{
		cout << "ITManager() Called" << endl;
	}
	//Overriding of Virtual Fuction in Person
	void Print()
	{
		Employee::Print();
	}
	//For Filing
	void WriteData(ofstream& fout )
	{
		fout << 1<<endl;
		fout << getemployeeid() << ',' << getname() << ',' << getPassword() <<endl;
	}
	//Returns the Type of Entity (IT-Manager in this Purpose)
	const char* Purpose() const throw()
	{
		return "ITManager";
	}
	virtual ~ITManager()
	{
		cout << "~ITManager() Called" << endl;
	}
};


