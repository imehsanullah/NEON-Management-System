#include"Student.h"
#include"Registration.h"

Student::Student()
{
	cout << "Student() Called" << endl;
	ID = -1;
	listofRegistrations = new Registration * [10];
	currentregs = 0;

}
Student::Student(int ID1, const char* name) :Person(name)
{
	cout << "Student() Called" << endl;
	ID = ID1;
	listofRegistrations = new Registration * [10];
	currentregs = 0;
}
Student::Student(int ID1, const char* name, Registration** list, int cRegs):Person(name)
{
	ID = ID1;
	listofRegistrations = list;
	currentregs = cRegs;
	
}
//Copy Constructor , Passed Argument Not constant by intent
Student::Student( Student& obj)
{
	Person::changename(obj.getname());
	SetPassword(obj.getPassword());
	ID = obj.ID;
	currentregs = obj.currentregs;
	//Shallow Copy of Registrations
	listofRegistrations = obj.getlistofRegistrations();
}




void Student::addregistration(Registration*obj)
{
	if (currentregs < 5) //This Check has been Placed when the Student Registers as well 
	{
		listofRegistrations[currentregs++] = obj;
	}
}
void Student::ShowRegstoStudent()
{
	if (currentregs > 0)
	{
		cout << "The courses Registered to  "<<getname()<<" are "<<endl;
		for (int i = 0; i < currentregs; i++)
		{
			cout << listofRegistrations[i]->getcoursename() << "  " << listofRegistrations[i]->getcourseid() << endl;;
		}
	}
	else
	{
		cout << "No courses are Registered to  " << getname()  << endl;
	}
}

int Student::checkifcourseregistered(char* Cname)
{
	for (int i = 0; i < currentregs; i++)
	{
		if (strcmp(listofRegistrations[i]->getcoursename(), Cname) == 0)
		{
			return i;
		}
	}
	return -1;
}
int Student::checkifcourseregisteredbyid(char* Cname)
{
	for (int i = 0; i < currentregs; i++)
	{
		if (strcmp(listofRegistrations[i]->getcourseid(), Cname) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Student::removeregfromstuedent(int ind)
{
	listofRegistrations[ind] = 0;
	for (int i = ind; i < currentregs-1; i++)
	{
		listofRegistrations[i] = listofRegistrations[i + 1];
	}
	currentregs--;
}
void Student::StudentManual()
{
	int flag = 0;
	while (flag == 0) {
		system("cls");
		cout << "Enter -1 to go back" << endl;
		if (currentregs != 0) 
		{
			int n;
			cout << " Welcome " << getname() << " select the course which record you want to chose" << endl;
			for (int i = 0; i < currentregs; i++)
			{
				cout << " For " << listofRegistrations[i]->getcoursename() << " Enter " << i << endl;
			}
			bool bad = false;
			do {
				cin >> n;
				bad = cin.fail();
				if (bad)
					cout << "Wrong Input Enter Integer" << endl;
				cin.clear();
				cin.ignore(10, '\n');
			} while (bad);
			if (n == -1)
				break;
			if (n < currentregs)
			{
				listofRegistrations[n]->StudentManualinRegistration();
			}
			else
			{
				cout << "Wrong Input ,Please Enter correct Instruction " << endl;
				holdtillakeypressed();
			}
		}
		else
		{
			cout << "You are not registered in any course,As you press any key you will move back ";
			holdtillakeypressed();
			break;
		}
	}
	}
int Student::getcurrentregs()
{
	return currentregs;
}
void Student::seeAcademicstatus()
{
	system("cls");
	if (currentregs != 0)
	{
		gotoxy(5, 5);
		cout << "The Academic Status of " << getname() << " (" << getstudentid() << ")  is" << endl;
		gotoxy(7, 5); cout << "Course Name ";
		gotoxy(7, 44); cout << "Marks ";
		gotoxy(7, 60); cout << "Grade ";
		for (int i = 0; i < currentregs; i++) 
		{
			gotoxy(9+i, 5);
			cout << listofRegistrations[i]->getcoursename() << " ("<< listofRegistrations[i]->getcourseid() << " ) " << endl;
			gotoxy(9 + i, 44);
			if (listofRegistrations[i]->getMarks() == -1)
			{
				cout << "Not Assigned";
			}
			else
			{
				cout << listofRegistrations[i]->getMarks();
			}
			gotoxy(9 + i, 60);
			if (listofRegistrations[i]->getGrade() == '-')
			{
				cout << "Not Assigned";
			}
			else
			{
				cout << listofRegistrations[i]->getGrade()<<endl;
			}

		}
		gotoxy(18 + currentregs, 5);
	}
	else
	{
		cout << "The Student " << getname() << " is not enrolled in any course" << endl;
	}
	cout << endl;
	holdtillakeypressed();

}
Registration** Student::getlistofRegistrations()
{
	Registration** list = new Registration*[5];
	for (int i = 0; i < currentregs; i++)
	{
		list[i] = listofRegistrations[i];
	}
	return list;
}
void Student::WriteData1(ofstream& fout)
{
	fout << getstudentid() << ','<<getname()<<','<<getPassword()<<endl;
}
int Student::getstudentid()
{
	return ID;
}
void Student::viewentireAttendance()
{
	system("cls");
	if (currentregs != 0)
	{
		gotoxy(5, 5);
		cout << "The Attendance of " << getname() << " (" << getstudentid() << ")  is" << endl;
		gotoxy(7, 5); cout << "Course Name ";
		gotoxy(7, 48); cout << "Attendance Percentage ";
		
		for (int i = 0; i < currentregs; i++)
		{
			gotoxy(9 + i, 5);
			cout << listofRegistrations[i]->getcoursename() << " (" << listofRegistrations[i]->getcourseid() << " ) " << endl;
			gotoxy(9 + i, 48);
			cout << listofRegistrations[i]->Attendancepercentage()<<"%";
			
		}
		gotoxy(18 + currentregs, 5);
	}
	else
	{
		cout << "The Student " << getname() << " is not enrolled in any course" << endl;
	}
	cout << endl;
	holdtillakeypressed();

}
const char* Student::Purpose() const throw()
{
	return "Student";
}
bool Student::operator!()
{
	return (currentregs<5);
}
bool Student::operator==(char* Cname)
{
	for (int i = 0; i < currentregs; i++)
	{
		if (strcmp(listofRegistrations[i]->getcourseid(), Cname) == 0)
		{
			return true;
		}
	}
	return false;
}
void Student::withdrawfromCourse(int ind)
{
	if (ind < currentregs)
	{
		listofRegistrations[ind]->WithDraw();
	}
}
 Student::~Student()
{
	cout << "~Student() Called" << endl;
	delete[] listofRegistrations;
 }
void Student::Print()
{
	 cout <<"The ID of Student is  "<< ID << " and his name is ";
	 Person::Print(); cout << endl;
}
