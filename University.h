#pragma once
#include"Department.h"

class University
{
	char* Uniname;
	//Template Class like Vectors Which Stores Pointers
	List<Department> listofdepts1;//List is Defined in Helper.h
public:
	//Default Constuctor
	University()
	{
		cout << "University() called" << endl;
		Uniname = 0;	
	}
	//Parameterized Constructor
	University(const char *name)
	{
		cout << "University() called" << endl;
		if (name != 0)
		{
			Uniname = new char[strlen(name)+1];
			for (int i = 0; name[i] != '\0'; i++)
			{
				Uniname[i] = name[i];
			}
			Uniname[strlen(name)] = '\0';
		}
		else
		{
			Uniname = 0;
		}	
	}
	//To add a Department in Uni
	void addDepartment(Department* Dept)
	{
		listofdepts1.Pushback(Dept);
	}
	//To add a Department in Uni
	void addDepartmentbyName(const char* Dept)
	{
		Department* temp = new Department(Dept);
		listofdepts1.Pushback(temp);
	}
	void Print()
	{
		cout << Uniname;
	}
	//To Return the Uni-name
	char* getname()
	{
		return Uniname;
	}
	//To Set an IT-Manager in Specific Department
	void SetITManager(ITManager*obj,int n)
	{
		listofdepts1[n]->SetITManager(obj);
	}
	//To Set an HOD in Specific Department
	void SetHOD(Teacher* obj, int n)
	{
		listofdepts1[n]->SetHOD(obj);
	}
	//For a USER to go to their Specific Departments
	void Manual()
	{
		int  flag = 0;
		while (flag==0)
		{
			int index = -99;
			system("cls");
			cout << "Enter -1 to exit" << endl;
			cout << "Welcome to " << Uniname << "  University" << endl;
			if (listofdepts1.getsize() != 0)
			{
				gotoxy(22, 30);
				cout << "Our University,"<<Uniname << " has" << endl;
				gotoxy(23, 30);
				cout << Person::gettotalppl() << "  no. of People Working/Studying here"<<endl;
				gotoxy(24, 30);
				cout << "It offers "<<Course::gettotalcourses()<<" No. of courses" << endl;
				gotoxy(3,0);
				cout << "Choose your Department" << endl;
				for (int i = 0; i < listofdepts1.getsize(); i++)
				{
					cout << listofdepts1[i]->getDeptname() << "  " << i << endl;
				}
				bool bad = false;
				do {
					cin >> index;
					bad = cin.fail();
					if (bad)
						cout << "Wrong value Enter again" << endl;
					cin.clear();
					cin.ignore(10, '\n');
				} while (bad);

				if (index == -1)
				{
					break;
				}
				if (index < listofdepts1.getsize())
				{
					listofdepts1[index]->Manual();
				}
				else
				{
					cout << "This department does not exist" << endl;
					holdtillakeypressed();
				}
			}
			else if(listofdepts1.getsize() ==0)
			{
				cout << "No Department assigned yet" << endl;
				flag = 1;
			}	
		}
	}
  //For Filing this Func is used
	void WriteData(ofstream&fout)
	{
		fout << Uniname << endl;
		fout << listofdepts1.getsize() <<endl;
		for (int i = 0; i < listofdepts1.getsize(); i++)
		{
			listofdepts1[i]->WriteData(fout);
		}
	}
	~University()
	{
		cout << "~University() called" << endl;
		delete [] Uniname;
		//Departments and its Pointers are Automatically deleted from ~List()
		//~List() Called which deletes the Departments objects;
	}
};
int Person::totalppl = 0; //Static Var in Person class
int Course::totalcourses = 0; //Static Var in Course class

//Polymorphic Aproach 
void Print(Person* obj)
{
	if (obj != 0)
	{
		obj->Print();
	}
}
void DeleteObject(Person* obj)
{
	if (obj != 0)
	{
		delete obj;
	}
}
//Friend Operator For Registration
ostream& operator<<(ostream& fout, const Registration& obj)
{
	fout << obj.course->getcourseid() << ',' << obj.student->getstudentid() << ',' << obj.grade << ',' << obj.Marks << ',' << obj.maxlecs << ',';
	for (int i = 0; i < obj.maxlecs; i++)
	{
		fout << obj.attendance[i];
		if (i + 1 != obj.maxlecs)
		{
			fout << ',';
		}
	}
	fout << endl;
	return fout;
}
