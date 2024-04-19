#pragma once
#include"Student.h"
#include"Course.h"

class Registration
{
	Student* student;
	Course* course;
	int* attendance; int maxlecs;
	int lecshappened;
	int Marks; char grade;
public:
	Registration(int lec=30)
	{
		student = 0; course = 0;
		cout << "Registration()"<<endl;
		attendance = new int[lec];
		for (int i = 0; i < lec; i++)
		{
			attendance[i] = -1;
		}
		maxlecs=30;
		lecshappened = 0;
		Marks = -1; grade = '-';
	}
	Registration(Student*std,Course* course1, int lec = 30)
	{
		student = std;
		course = course1;
		attendance = new int[lec];
		for (int i = 0; i < lec; i++)
		{
			attendance[i] = -1;
		}
		maxlecs = 30;
		lecshappened = 0;
		Marks = -1; grade = '-';
	}
	Registration(Student* std, int lec = 30)
	{
		student = std;
		course = 0;
		attendance = new int[lec];
		for (int i = 0; i < lec; i++)
		{
			attendance[i] = -1;
		}
		maxlecs = lec;
		lecshappened = 0;
		Marks = -1; grade = '-';
	}
	Registration(char Grad,int Marks1,int mlecs,int*arr)
	{
		grade = Grad; Marks = Marks1; maxlecs = mlecs;
		attendance = arr;
		lecshappened=0;
		for (int i = 0; i < maxlecs; i++)
		{
			if (arr[i] != -1)
				lecshappened++;
		}
		student = 0; course = 0;
	}
	//Binary Operator
	Registration& operator =(const Registration& obj)
	{
		if (this != &obj) {
			course = obj.course;
			student = obj.student;
			lecshappened = obj.lecshappened;
			maxlecs = obj.maxlecs;
			if (attendance != 0)
			{
				delete[] attendance;
			}
			attendance = new int[maxlecs];
			for (int i = 0; i < maxlecs; i++)
			{
				attendance[i] = obj.attendance[i];
			}
			Marks = obj.Marks;
			grade = obj.grade;
			return *this;
		}
		return *this;
	}
	int getmaclecs()
	{
		return maxlecs;
	}
	void assignGrade(char g)
	{
		grade = g;
	}
	void assignMarks(int M)
	{
		Marks = M;
	}
	void assigncourse(Course*obj)
	{
		course = obj;
	}
	void assignstudent(Student* obj)
	{
		student = obj;
	}
	int getstudentid()
	{
		return student->getstudentid();
	}
	char* getstudentname()
	{
		return student->getname();
	}
	char* getcoursename()
	{
		return course->getcoursename();
	}
	char* getcourseid()
	{
		return course->getcourseid();
	}
	int getMarks()
	{
		return Marks;
	}
	char getGrade()
	{
		return grade;
	}
	void Print()
	{
		student->Print();
		course->Print();
	}
	void Markattendance(int lecno,int a)
	{
		if (lecno < maxlecs &&lecno>0)
		{
			attendance[lecno-1] = a;
			lecshappened++;
		}
		else
		{
			cout << "This lecture no. does not exist in " << course->getcoursename() << endl;
			holdtillakeypressed();
		}
	}
	void Showdetailattendance()
	{
		if (maxlecs != 0)
		{
			system("cls"); gotoxy(5, 15);
			cout << "The Attendance Status of " << student->getname()<<" is";
			gotoxy(8, 20);
			cout << "Lecture No " ;
			gotoxy(8, 35);
			cout << "Status ";
			for (int i = 0; i < maxlecs; i++)
			{
				gotoxy(12 + i, 20); cout << i + 1;
				gotoxy(12 + i, 35);
				if (attendance[i] == 1)
				{
					cout << " Present  " ;
				}
				else if (attendance[i] == 0)
				{
					cout << " Absent ";
				}
				else
				{
					cout << "Not assigned" ;
				}
				
			}
		}
		else
		{
			cout << "No attendance Record for " << student->getname() << " exists in " << course->getcoursename()<<endl;
		}
		holdtillakeypressed();
	}
	float Attendancepercentage()
	{
		float num=0;
		for (int i = 0; i < lecshappened; i++)
		{
			if (attendance[i] == 1)
			{
				num++;
			}
		}
		if (lecshappened == 0)
			return 0;
		return (num / lecshappened)*100;
	}
	//For Teacher to Edit Student's Record
	void RegistrationManual()
	{
		int flag = 0;
		while (flag == 0)
		{
			system("cls");
			cout << "Enter -1 to Exit " << endl;
			cout << "Enter 0 to Mark the attendance of " <<student->getname()<< endl;
			cout << "Enter 1 to view the attendance of " <<student->getname()<< endl;
			cout << "Enter 2 to Enter the marks of " <<student->getname()<< endl;
			cout << "Enter 3 to Enter the Grade of " <<student->getname()<< endl;
			cout << "Enter 4 to view the Evaluation of " <<student->getname()<< endl;
			int a;
			bool bad = false;
			do {
				cout << "Enter number: ";
				cin >> a;
				bad = cin.fail();
				if (bad)
					cout << "Error message" << endl;
				cin.clear();
				cin.ignore(10, '\n');
			} while (bad);
			if (a == -1)
			{
				break;
			}
			if (a == 0)
			{
				int num;
				cout << "Enter the lecture no" << endl;
				bool bad = false;
				do {
					cin >> num;
					bad = cin.fail();
					if (bad)
						cout << "Only integer Input allowed" << endl;
					cin.clear();
					cin.ignore(10, '\n');
				} while (bad);
				if (num < 30)
				{
					cout << "Enter 1 for present and 0 for absent" << endl;
					int status;
					bool bad1 = false;
					bool bad2 = false;
					do {
						cin >> status;
						bad1 = cin.fail();
						bad2 = ifAttendanceright(status);
						if (bad1)
							cout << "Only integer Input allowed" << endl;
						if (bad2)
							cout << "Enter 1 for Present 0 for absent" << endl;
						cin.clear();
						cin.ignore(10, '\n');
					} while (bad1 || bad2);
					Markattendance(num, status);
				}
				else
				{
					cout << "Lec no" << num << "Does not exist in "<<course->getcoursename() << endl;
				}
			}
			if (a == 1)
			{
				cout << "The attendance of " << student->getname() << " in course " << course->getcoursename() << " is  "
					<< Attendancepercentage() << " Percent";
				holdtillakeypressed();
			}
			if (a == 2)
			{
				int marks;
				cout << "Enter the Marks of " << student->getname()<<endl;
				bool bad = false;
				do {
					cin >> marks;
					bad = cin.fail();
					if (bad)
						cout << "Enter again Only integer Input allowed" << endl;
					cin.clear();
					cin.ignore(10, '\n');
				} while (bad);
				Marks = marks;
			}
			if (a == 3)
			{
				char g='-';
				system("cls");
				cout << "Enter Z/z to Go back" << endl;
				cout << "Enter the grade for "<<student->getname()<<" in course "<<course->getcoursename() << endl;
				bool bad = false;
				do {
					cin >>g;
					if (g == 'z' || g == 'Z')
					{
						break;
					}
					bad = ifGraderight(g);
					if (bad)
					{
						cout << "Only A,B,C,D or F Grade allowed" << endl;
					}
					if (bad == false)
					{
						grade = g;
					}
					
					cin.clear();
					cin.ignore(10, '\n');
				} while (bad);
				
			}
			if (a == 4)
			{
				cout << "The student " << student->getname() << " got ";
				if (Marks == -1)
				{
					cout << " not assigned yet";
				}
				else
				{
					cout << Marks << " marks" ;
				}
				cout << "   and his Grade is " ;
				if (grade == '-')
				{
					cout << " not assigned yet " << endl;
				}
				else
				{
					cout << grade<<endl;
				}
				holdtillakeypressed();
			}
		}
		
	}
	//For Student to view His Record
	void StudentManualinRegistration()
	{
		int flag = 0;
		while (flag == 0)
		{
			int n; system("cls");
			cout << "Enter -1 to go Back " << endl;
			cout << "Enter 0 to view your attendance Percentage in " <<course->getcoursename()<< endl;
			cout << "Enter 1 to view your Marks/Grade in " <<course->getcoursename()<< endl;
			cout << "Enter 2 to view your Detailed Attendance in " <<course->getcoursename()<< endl;
			bool bad = false;
			do {
				cout << "Enter Instruction :  ";
				cin >> n;
				bad = cin.fail();
				if (bad)
					cout << "Only Integer Instuction Allowed" << endl;
				cin.clear();
				cin.ignore(10, '\n');
			} while (bad);
			if (n == -1)
			{
				break;
			}
			
			if (n == 0)
			{
				cout << "Your attendance is " << Attendancepercentage() << " Percent" << endl;
			}
			if (n == 1)
			{
				cout << "Your Marks are ";
				if (Marks != -1)
					cout << Marks << endl;
				else
					cout << "Not Assigned" << endl;
				cout << "Your Grade is";
				if (grade != '-')
					cout << grade << endl;
				else
					cout << " Not Assigned" << endl;
			}
			if (n == 2)
			{
				Showdetailattendance();
			}
			holdtillakeypressed();
		}
	}
	void WriteData(ofstream& fout)
	{
		fout << course->getcourseid() << ',' << student->getstudentid()<<','<<grade<<','<<Marks<<','<<maxlecs<<',';
		for (int i = 0; i < maxlecs; i++)
		{
			fout <<attendance[i] ;
			if (i + 1 != maxlecs)
			{
				fout << ',';
			}
		}
		fout << endl;
	}
	
	void WithDraw()
	{
		grade = 'W';
	}
	//1-D Growing of the Array
	void increaseLectures(int inc = 1)
	{
		int* temp = new int[maxlecs];
		for (int i = 0; i < maxlecs; i++)
		{
			temp[i] = attendance[i];
		}
		delete[] attendance;
		attendance = new int[maxlecs + inc];
		for (int i = 0; i < maxlecs; i++)
		{
			attendance[i] = temp[i];
		}
		for (int i = maxlecs; i < maxlecs + inc; i++)
		{
			attendance[i] = -1;
		}
		maxlecs = maxlecs + inc;;
		delete[]temp;
	}
	//1-D Shrinking of the Array
	void decreaseLectures(int dec = 1)
	{
		try 
		{
			if (maxlecs - dec > 0)
			{
				int* temp = new int[maxlecs];
				for (int i = 0; i < maxlecs; i++)
				{
					temp[i] = attendance[i];
				}
				delete[] attendance;
				attendance = new int[maxlecs - dec];
				for (int i = 0; i < maxlecs - dec; i++)
				{
					attendance[i] = temp[i];
				}
				delete[]temp;
			}
			else
			{
				throw "You can not Shrink the Array beyond 0"; 
			}
		}
		catch (const char* t)
		{
			cout << t << endl;
		}
		catch (...) {}
	}
	
	
	friend ostream& operator <<(ostream& fout, const Registration& obj);
	~Registration()
	{
		cout << "~Registration()" << endl;
			delete[] attendance;
			course = 0;
			student = 0;
	}
};
