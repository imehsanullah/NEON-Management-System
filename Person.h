#pragma once

#include"Helper.h"
#include<iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;

class Person  //Abstract Class With Pure Virtual Function Purpose()
{
	char* name;
	char* Password;
	static int totalppl; //Defined at the End of University File
public:
	//Default Constructor
	Person()
	{
		name = 0;
		cout << " Default Person() called" << endl;
		Password = new char[6]{"None"};
	}
	//Parameterized Constructor
	Person(const char* name1)
	{
		cout << "Person() called" << endl;
		if (name1 != 0)
		{
			name = new char[strlen(name1) + 1];
			for (int i = 0; name1[i] != '\0'; i++)
			{
				name[i] = name1[i];
			}
			name[strlen(name1)] = '\0';
		}
		else
		{
			name = 0;
		}
		Password = new char[6]{ "None" };
		totalppl++;
	}
	//Returns the Total People Work/Study at the University
	static int gettotalppl()
	{
		return totalppl;
	}
	//To Check if the User has not Assigned a Password Yet
	bool isPasswordNone()
	{
		if (strcmp(Password, "None") == 0)
		{
			return true;
		}
		return false;
	}
	// To check the Status of Password (Matched or Not)
	bool CheckPassword(char*Pass)
	{
		if (strcmp(Password, Pass) == 0)
		{
			return false;
		}
		return true;
	}
	//To Set/Change Password
	void SetPassword(char*Pass)
	{
		if (Password != 0)
		{
			delete[]Password;
		}
		Password = new char[strlen(Pass)+1];
		for (int i = 0; Pass[i] != '\0'; i++)
		{
			Password[i] = Pass[i];
		}
		Password[strlen(Pass)] = '\0';
	}
	//Returns the Name of the Person
	char* getname()
	{
		return name;
	}
	//To change Name by IT-Manager from Department Class
	void changename(char*na)
	{
		if (name != 0)
		{
			delete[]name;
		}
		name = new char[strlen(na) + 1];
		for (int i = 0; na[i] != '\0'; i++)
		{
			name[i] = na[i];
		}
		name[strlen(na)] = '\0';
	}
	//Returns the Password of the Person
	char* getPassword()
	{
		return Password;
	}
	
	//Virtual Function for Polymorphic Approach
	virtual void Print()
	{
		if (name != 0) {
			cout << name;
		}
		else
		{
			cout << "Name not Assigned" << endl;
		}
	}

	//A pure Virtual Function (I will use it to differentiate b/w Student and TA)
	// It returns the Type of Entity like Teacher,Student 
	virtual const char* Purpose() const throw() = 0;
	
	virtual ~Person()
	{
		cout << "~Person() called" << endl;
		delete[]name;
		delete [] Password;
	}
};
