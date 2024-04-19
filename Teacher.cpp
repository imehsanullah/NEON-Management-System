#include"Teacher.h"
#include"Course.h"
Teacher::Teacher()
{
	cout << "Teacher() Called" << endl;
	listofcourses = new Course*[10];
	coursecap = 10;
	currentcourses = 0;
}
Teacher::Teacher(int Empnum, const char* name) :Employee(Empnum, name), Person(name)
{
	cout << "Teacher() Called" << endl;
	listofcourses = new Course * [10];
	currentcourses = 0;
	coursecap = 10;
}
void Teacher::Print()
{
	Employee::Print();
}
void Teacher::DisplayCoursesAssigned()
{
	if (currentcourses != 0)
	{
		cout << "The courses assigned to  " << getname() << " are " << endl;
		for (int i = 0; i < currentcourses; i++)
		{
			cout << listofcourses[i]->getcoursename() <<"  "<<listofcourses[i]->getcourseid()<< endl;
		}
	}
	else
	{
		cout << "No courses have been assigned to "<<getname()<<endl;
	}
}
int Teacher::FindIndexofCourse(char* name)
{
	for (int i = 0; i < currentcourses; i++)
	{
		if (strcmp(name, listofcourses[i]->getcoursename()) == 0)
		{
			return i;
		}
	}
	return -1;
}

int Teacher::FindIndexofCoursebyid(char* name)
{
	for (int i = 0; i < currentcourses; i++)
	{
		if (strcmp(name, listofcourses[i]->getcourseid()) == 0)
		{
			return i;
		}
	}
	return -1;
}

void Teacher::assigncoursetoteaacher(Course* obj)
{
	if (currentcourses == coursecap - 1)
	{
		extendlistofcourses();
	}
	listofcourses[currentcourses++] = obj;
}
//Takes the Teacher to the Course which Evaluations he wants to do
void Teacher::TeacherManual()
{
	int flag = 0;
	while (flag == 0) 
	{
		system("cls");
		int flag1 = 0; int num=-99;
		cout << "Enter -1 to go back" << endl;
		if (isPasswordNone() == true)
		{
			cout << "WARNING:- Please Set your Password for Security Purposes" << endl<<endl;
		}
		cout << "Welcome   " << getname() << endl;
		cout << "Enter 0 To perform your duties/Evaluation "<<endl;
		cout << "Enter 1 To view the courses assigned to you " << endl;
		cout << "Enter 2 To Set/Change Your Password " << endl;
		bool bad = false;
		do {
			cin >> num;
			bad = cin.fail();
			if (bad)
				cout << "Error message" << endl;
			cin.clear();
			cin.ignore(10, '\n');
		} while (bad);
		if (num == -1)
		{
			break;
		}
		if (num == 0)
		{
			system("cls");
			cout << "Enter -1 to Go back OR" << endl;
			char* cname = entersinglename2("Enter the ID of the Course for Evaluation ");
			if (strcmp(cname, "-1") != 0)
			{
				int Cindex = FindIndexofCoursebyid(cname);
				if (Cindex == -1)
				{
					cout << "This course " << cname << " has not been assigned to you" << endl;
					holdtillakeypressed();
				}
				if (Cindex != -1 && Cindex < currentcourses)
				{
					listofcourses[Cindex]->CourseManual();
				}
			}
			delete[] cname;
		}
	    if (num == 1)
		{
			system("cls");
			DisplayCoursesAssigned();
			holdtillakeypressed();
		}
		if (num == 2)
		{
			cout << "Please Enter your New Password" << endl;
			char* Pass = new char[20];
			cin.getline(Pass, 20);
			if (strcmp(Pass, "-1") != 0)
			{
				SetPassword(Pass);
				cout << "Your Password has been changed" << endl;
				holdtillakeypressed();
			}
			delete[]Pass;
		}
		
	}
}
void Teacher::viewcoursestoteacher()
{
	if (currentcourses > 0) 
	{
		cout << "The courses assigned to " << getname() << " are" << endl;
		for (int i = 0; i < currentcourses; i++)
		{
			cout << listofcourses[i]->getcoursename()<<"  "<<listofcourses[i]->getcourseid() << endl;
		}
	}
	else
	{
		cout << "No courses have been assigned to " << getname() << endl;
	}
	holdtillakeypressed();
}
void Teacher::extendlistofcourses()
{
	Course** temp = new Course * [currentcourses];
	for (int i = 0; i < currentcourses; i++)
	{
		temp[i] = listofcourses[i];
	}
	delete[]listofcourses;
	listofcourses = new Course * [coursecap * 2];
	coursecap = coursecap * 2;
	for (int i = 0; i < currentcourses; i++)
	{
		listofcourses[i] = temp[i];
	}
	delete[]temp;
}
bool Teacher::checkifCourseAssigned(char* ID)
{
	for (int i = 0; i < currentcourses; i++)
	{
		if (strcmp(ID, listofcourses[i]->getcourseid()) == 0)
		{
			return true;
		}
	}
	return false;
}

void Teacher::WriteData1(ofstream& fout)
{
	fout << getemployeeid() << ',' << getname()<<','<<getPassword()<<endl;
}
void Teacher::WriteData2(ofstream& fout)
{
	for (int i = 0; i < currentcourses; i++)
	{
		fout << getemployeeid() << ',' << listofcourses[i]->getcourseid() << endl;
	}
}
int Teacher::getAssignedcourses()
{
	return currentcourses;
}
void Teacher::unassignacoursefromteacher(char* Cid)
{
	int Cind = FindIndexofCoursebyid(Cid);
	if (Cind != -1)
	{
		listofcourses[Cind] = 0;
		for (int i = Cind; i < currentcourses-1; i++)
		{
			listofcourses[i] = listofcourses[i + 1];
		}
		currentcourses--;
	}
}
const char* Teacher::Purpose() const throw()
{
	return "Teacher";
}
Teacher::~Teacher()
{
	cout << "Teacher() Called" << endl;
	delete[] listofcourses;
}
