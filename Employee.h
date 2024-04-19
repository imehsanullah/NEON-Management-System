#pragma once
#include"Person.h"
class Employee :virtual public Person
{
	int Empnum;
public:
	//Default Constructor
	Employee()
	{
		cout << "Employee() called" << endl;
		Empnum = 0;
	}
	//Parameterized Constructor
	Employee(int Empnum1, const char* name) :Person(name)
	{
		cout << "Employee() called" << endl;
		Empnum = Empnum1;
	}
	//Returns the EmployeeID
	int getemployeeid()   
	{
		return Empnum;
	}
	//Over-Riding of the Virtual Function in Person Class
	void Print()
	{
		cout << "The name is ";
		Person::Print();
		cout << " and Employee number is " << Empnum << endl;
	}
	const char* Purpose() const throw()
	{
		return "Employee";
	}
	virtual ~Employee()
	{
		cout << "~Employee() called" << endl;
	}
};



