#pragma once
#include"Student.h"
#include"Teacher.h"

// Diamond Problem For TA has been solved by making Employee and Student virtually
// inherited from Person
class TA :public Student, public Teacher
{
public:
	//Parameterized Constructor's
	TA(int ID, int EmpID, const char* name) :Person(name), Teacher(EmpID, name), Student(ID, name)
	{
		cout << "TA() called" << endl;
	}

	TA(int ID, int EmpID, const char* name,Registration** list,int Sregs) :Person(name), Teacher(EmpID, name), Student(ID, name)
	{
		cout << "TA() called" << endl;
		listofRegistrations = list;
		currentregs = Sregs;
		
	}
	//Over-Riding of Virtual Function in Person
	void Print()
	{
		Student::Print(); Teacher::Print();
	}
	//Returns the Type of Entity
	 const char* Purpose()const throw()
	{
		return "TA";
	}
	virtual ~TA()
	{
		cout << "~TA() called" << endl;
	}
};

