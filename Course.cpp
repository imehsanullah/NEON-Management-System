#include"Course.h"
#include"Registration.h"
Course::Course(int cap)//Course::
{
	Ta = 0;
	listofRegistrations = new Registration * [cap];
	cout << "Course() called" << endl;
	CourseID = 0;
	Coursename = 0;
	currentRegs = 0;
	maxregs = cap;
	totalcourses++;
}
Course::Course(const char* ID, const char* name,int cap)
{
	maxregs = cap;
	currentRegs = 0;
	Ta = 0;
	listofRegistrations = new Registration*[cap];
	cout << "Course() called" << endl;
	if (ID != 0)
	{
		CourseID = new char[strlen(ID) + 1];
		for (int i = 0; ID[i] != '\0'; i++)
		{
			CourseID[i] = ID[i];
		}
		CourseID[strlen(ID)] = '\0';
	}
	else
	{
		cout << "Appropriate courseID not Entered"<<endl;
		CourseID = 0;
	}
	if (name != 0)
	{
		Coursename = new char[strlen(name) + 1];
		for (int i = 0; name[i] != '\0'; i++)
		{
			Coursename[i] = name[i];
		}
		Coursename[strlen(name)] = '\0';
	}
	else
	{
		cout << "Appropriate course Name not Entered" << endl;
		Coursename = 0;
	}
	totalcourses++;
}
void Course::SetTA(TA* obj)
{
	Ta = obj;
}
TA* Course::UnSetTA()
{
	if (Ta != 0) 
	{
		TA* temp = Ta;
		Ta = 0;
		return temp;
	}
	return 0;
}
void Course::Print()
{
	cout << CourseID<<" "<<Coursename;
}
void Course::extendlistofRegistrations()
{
	Registration** temp = new Registration * [currentRegs];
	for (int i = 0; i < currentRegs; i++)
	{
		temp[i] = listofRegistrations[i];
	}
	delete[]listofRegistrations;
	listofRegistrations = new Registration * [maxregs +10];
	maxregs=maxregs +10;
	for (int i = 0; i < currentRegs; i++)
	{
		 listofRegistrations[i]= temp[i] ;
	}
	delete[]temp;
}
//Shows the Marks and Grades of all Students
void Course::viewAcademicStatus()
{
	system("cls");
	if (currentRegs != 0)
	{
		gotoxy(5, 8);
		cout << "The Academic Status OF " << Coursename << '(' << CourseID << ')' << " is as Follows" << endl;
		gotoxy(8, 10);
		cout << "Student Name/s";
		gotoxy(8, 40); cout << "Marks";
		gotoxy(8, 55); cout << "Grades";
		for (int i = 0; i < currentRegs; i++)
		{
			int m; char g;
			gotoxy(10+i, 10);
			cout << listofRegistrations[i]->getstudentname() << "( "
				<< listofRegistrations[i]->getstudentid() << " )";
			gotoxy(10+i, 40);
			m = listofRegistrations[i]->getMarks();
			g = listofRegistrations[i]->getGrade();
			if (m == -1)
			{
				cout << "Not Assigned";
			}
			else
			{
				cout << m;
			}
			gotoxy(10+i, 55);
			if (g != '-')
			{
				cout << g;
			}
			else
			{
				cout << "Not Assigned";
			}
		}
	}
	else
	{
		gotoxy(5,8);
		cout <<"No students are Enrolled in "<<Coursename<<endl ;
	}
	gotoxy(15 + currentRegs, 20);
	 cout << endl;
}

int Course::getnoofRegs()
{
	return currentRegs;
}
void Course::WriteData1(ofstream& fout)
{
	fout << CourseID << ',' << Coursename<<endl;
}
void Course::WriteData2(ofstream& fout)
{
	for (int i = 0; i < currentRegs; i++)
	{
		listofRegistrations[i]->WriteData(fout);
	}
}
void Course::addregistration(Registration* obj)
{
	if (currentRegs == maxregs - 1)
	{
		extendlistofRegistrations();
	}
	listofRegistrations[currentRegs++] = obj;
}
Course::~Course()
{
	delete[] listofRegistrations;
	delete[] CourseID;
	delete[] Coursename;
	cout << "~Course() called" << endl;
}
char* Course::getcourseid()
{
	return CourseID;
}
char* Course::getcoursename()
{
	return Coursename;
}
//To check if a student is Registered 
int Course::checkifstudentregistered(char* Sname)
{
	for (int i = 0; i < currentRegs; i++)
	{
		if (strcmp(listofRegistrations[i]->getstudentname(), Sname) == 0)
		{
			return i;
		}
	}
	return -1;
}
//To check if a student is Registered by his id
int Course::checkifstudentregisteredbyid(int S)
{
	for (int i = 0; i < currentRegs; i++)
	{
		if ( listofRegistrations[i]->getstudentid()==S)
		{
			return i;
		}
	}
	return -1;
}
//To check if the same TA exists in the course
bool Course::checkifTAsame(int id)
{
	if (Ta != 0) 
	{
		if (Ta->getemployeeid() == id)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool Course::checkifTAexists()
{
	if (Ta != 0)
	{
		return true;
	}
	return false;
}

int Course::gettotalcourses()
{
	return totalcourses;
}
//For the TA to Perform his Evaluations (Given HIM almost the same Authority as the Teacher)
void Course::TAmanualinCourse()
{
	
	if (Ta != 0)//Ta
	{
		try
		{
			bool  var2 = false;
			cout << "Enter -1 to go Back" << endl;
			if (Ta->isPasswordNone() == false) {
				cout << "PLease Enter Your Password " << Ta->getname() << endl;
			}
			do {
				if (Ta->isPasswordNone() == true)
					throw PasswordMatched();
				char* Pass = new char[20];
				cin.getline(Pass, 20);
				if (strcmp(Pass, "-1") == 0)
				{
					delete[]Pass;
					throw 0;
				}
				var2 = Ta->CheckPassword(Pass);
				if (var2)
					cout << "Wrong Password Please Enter again" << endl;

				if (var2 == false || strcmp(Pass, "pass") == 0)
				{
					delete[]Pass;
					throw PasswordMatched();
				}
				delete[]Pass;
			} while (var2);

		}
		catch (PasswordMatched)
		{
			int flag = 0;
			while (flag == 0)
			{
				int a; system("cls");
				cout << "Enter -1 to Exit" << endl;
				cout << "Enter 0 to manage the Evaluation/Attendance of Students Individually" << endl;
				cout << "Enter 1 to Enter the Grade of All Students in Course Collectively" << endl;
				cout << "Enter 2 to Enter the Marks of All Students in Course Collectively" << endl;
				cout << "Enter 3 to View the Marks/Grades of All Students in Course Collectively" << endl;
				a = enterint2("Enter Instruction", "Only Integer Instruction Allowd");
				if (a == -1)
				{
					break;
				}
				if (a == 0)
				{
					system("cls");
					int sname = enterint("Enter the id Student for his Personal evaluation");
					int n = checkifstudentregisteredbyid(sname);
					if (n == -1)
					{
						cout << sname << " is not registered in " << Coursename;
						holdtillakeypressed();
					}
					else
					{
						listofRegistrations[n]->RegistrationManual();
					}
				}
				if (a == 1)
				{
					if (currentRegs != 0)
					{
						try
						{
							system("cls");
							gotoxy(0, 25); cout << "Enter Z/z to go back";
							gotoxy(3, 5);
							cout << "To Mark Grade , Enter appropriate Input for Grade (A/B/C/D/F ) for Student  " << endl;
							gotoxy(5, 6); cout << "Student Name/s";
							gotoxy(5, 35); cout << "Grade's Status" << endl;
							for (int i = 0; i < currentRegs; i++)
							{
								char stat = '-';
								gotoxy(7 + i, 6);
								cout << listofRegistrations[i]->getstudentname() << "( "
									<< listofRegistrations[i]->getstudentid() << " )";
								gotoxy(7 + i, 35);
								bool var1 = false;
								do
								{
									cin >> stat;
									var1 = ifGraderight(stat);
									if (var1)
									{
										if (stat == 'z' || stat == 'Z' || stat == '-')
										{
											throw GoBack();
										}
										gotoxy(7 + i, 35);
										cout << "Only A/B/C/D/F grade Allowed";
										Sleep(700);
										gotoxy(7 + i, 35);
										cout << "                                 ";
										gotoxy(7 + i, 35);
									}
									if (var1 == false) { gotoxy(7 + i, 35); cout << "     "; }
								} while (var1);
								gotoxy(7 + i, 35);
								cout << stat;
								listofRegistrations[i]->assignGrade(stat);
							}
						}
						catch (GoBack)
						{
							cout << "Going Back" << endl;
						}
						catch (...)
						{

						}
					}
					else
					{
						cout << "No Students Enrolled in Course " << Coursename << "Yet" << endl;
					}
					cout << endl;
					holdtillakeypressed();
				}
				if (a == 2)
				{
					if (currentRegs != 0)
					{
						try
						{
							system("cls");
							gotoxy(0, 25); cout << "Enter -1 to go back";
							gotoxy(3, 5);
							cout << "To Assign Marks , Enter appropriate Input for attendance (1 for Present/0 for absent )  " << endl;
							gotoxy(5, 6); cout << "Student Name/s";
							gotoxy(5, 40); cout << "Mark's Status" << endl;
							for (int i = 0; i < currentRegs; i++)
							{
								int stat = -99;
								gotoxy(7 + i, 6);
								cout << listofRegistrations[i]->getstudentname() << "( "
									<< listofRegistrations[i]->getstudentid() << " )";

								bool var1 = false, var2 = false;
								do
								{
									gotoxy(7 + i, 40);
									cin >> stat;
									var1 = cin.fail();
									if (var1)
									{
										gotoxy(7 + i, 40);
										cout << "Only Integer Marks are Allowed";
										Sleep(700);
										gotoxy(7 + i, 40);
										cout << "                                 ";
										gotoxy(7 + i, 40);
									}
									if (var1 == false)
									{
										if (stat == -1)
										{
											throw GoBack();
										}
										if (stat < 0)
										{
											var2 = true;
										}
										else
										{
											var2 = false;
										}
									}
									if (var2)
									{
										gotoxy(7 + i, 40);
										cout << "Only O or Greater Marks can be assigned to Student        ";
										Sleep(700);
										gotoxy(7 + i, 40);
										cout << "                                                        ";
										gotoxy(7 + i, 40);
									}
									if (var2 == false) { gotoxy(7 + i, 40); cout << "         "; }
									cin.clear();
									cin.ignore(10, '\n');
								} while (var1 || var2);
								listofRegistrations[i]->assignMarks(stat);
								gotoxy(7 + i, 40);
								cout << stat;
							}
						}
						catch (GoBack)
						{
							cout << "Going Back" << endl;
						}
						catch (...)
						{

						}
					}
					else
					{
						cout << "No Students Enrolled in Course " << Coursename << "Yet" << endl;
					}
					cout << endl;
					holdtillakeypressed();
				}
				if (a == 3)
				{
					viewAcademicStatus();
				}
				
			}
		}
		catch (int)
		{
		
		}
	}
	else
	{
		cout << "No TA in the course " << Coursename << endl;
	}
	holdtillakeypressed();
}

void Course::removeregfromcourse( int ind)
{
	/*delete listofRegistrations[ind];*/
	for (int i = ind; i < currentRegs-1; i++)
	{
		listofRegistrations[i] = listofRegistrations[i + 1];
	}
	currentRegs--;
}
//To show the Students Enrolled in a Course
void Course::Showregstocourse()
{
	for (int i = 0; i < currentRegs; i++)
	{
		cout<<listofRegistrations[i]->getstudentname()<<"  "<< listofRegistrations[i]->getstudentid()<<endl;
	}
}
//For the Teacher to Perform his Evaluations
void Course::CourseManual()
{
	int flag = 0;
	while (flag == 0)
	{
		int a; system("cls");
		cout << "Enter -1 to Exit" << endl;
		cout << "Enter 0 to manage the Evaluation/Attendance of Students Individually" << endl;
		cout << "Enter 1 to manage the Attendance of All Students in Course Collectively" << endl;
		cout << "Enter 2 to View the Attendance of All Students in Course Collectively" << endl;
		cout << "Enter 3 to Enter the Marks of All Students in Course Collectively" << endl;
		cout << "Enter 4 to View the Marks/Grades of All Students in Course Collectively" << endl;
		cout << "Enter 5 to Enter the Grade of All Students in Course Collectively" << endl;
		
		cout << "Enter 7 to view  of all Students Enrolled in "<<Coursename <<" course" << endl;
		a = enterint2("Enter Instruction", "Only Integer Instruction Allowd");
		if (a == -1)
		{
			break;
		}
		if (a == 0)
		{
			system("cls");
			cout << "Enter -1 to Go back" << endl;
			int sname = enterint("Enter the id Student for his Personal evaluation");
			if (sname != -1)
			{
				int n = checkifstudentregisteredbyid(sname);
				if (n == -1)
				{
					cout << sname << " is not registered in " << Coursename;
					holdtillakeypressed();
				}
				else
				{
					listofRegistrations[n]->RegistrationManual();
				}
			}
		}
		if(a == 1)
		{
			if (currentRegs != 0)
			{
				try
				{
					system("cls");
					cout << "Enter -1 to go back" << endl;
					cout << "Enter the Lec Number" << endl;
					int lno;
					lno = enterint(0);
					if (lno>0 && lno < listofRegistrations[0]->getmaclecs())
					{
						system("cls");
						gotoxy(0, 25); cout << "Enter -1 to go back";
						gotoxy(3, 5);
						cout << "To Mark Attendance , Enter appropriate Input for attendance (1 for Present/0 for absent )  " << endl;

						gotoxy(5,6); cout << "Student Name/s";
						gotoxy(5, 35); cout << "Attendance Status" << endl;
						for (int i = 0; i < currentRegs; i++)
						{
							int stat = -99;
							gotoxy(7+i, 6);
							cout << listofRegistrations[i]->getstudentname() <<"( "
								<< listofRegistrations[i]->getstudentid() << " )";
							gotoxy(7 + i, 35); 
							bool var1 = false,var2=false;
							do
							{
								cin >> stat;
								var1 = cin.fail();
								if (var1)
								{
									gotoxy(7 + i, 35);
									cout << "Only Integer(1/0) Input Allowed";
									Sleep(700);
									gotoxy(7 + i, 35);
									cout << "                                 ";
									gotoxy(7 + i, 35);
								}
								if (var1 == false)
								{
								      if(stat==-1)
								      {
									throw GoBack();
							          }
									var2 = ifAttendanceright(stat);
								}
								if (var2)
								{
									gotoxy(7 + i, 35);
									cout << "Wrong Attendance(  Enter 1 for Present/0 for Absent  )";
									Sleep(700);
									gotoxy(7 + i, 35); 
									cout << "                                                        ";
									gotoxy(7 + i, 35);
								}
								if (var2 == false) { gotoxy(7 + i, 35); cout << "     "; }
								cin.clear();
								cin.ignore(10, '\n');
							} while (var1||var2);
							listofRegistrations[i]->Markattendance(lno, stat);
							gotoxy(7 + i, 35);
							if (stat == 1) { cout << "Present"; }
							else if (stat == 0) { cout << "Absent"; }
						}
						
					}
					else
					{
						cout << "Lecture NO "<<lno<<" Does not exist " << endl;
					}			    
				}
				catch (GoBack)
				{
					cout << "Going Back" << endl;
				}
				catch (...)
				{
				
				}
			}
			else
			{
				cout << "No Students Enrolled in Course "<<Coursename<<"Yet"<<endl;
			}
			cout << endl;
			holdtillakeypressed();
		}
		if (a == 2)
		{
			system("cls");
			if (currentRegs != 0)
			{
				gotoxy(5, 8);
				cout << "The Attendance of Student in  " << Coursename << '(' << CourseID << ')' << " is as Follows" << endl;
				gotoxy(8, 10);
				cout << "Student Name/s";
				gotoxy(8, 40); cout << "Attendance Percentage";

				for (int i = 0; i < currentRegs; i++)
				{
					float m;
					gotoxy(10 + i, 10);
					cout << listofRegistrations[i]->getstudentname() << "( "
						<< listofRegistrations[i]->getstudentid() << " )";
					gotoxy(10 + i, 40);
					m = listofRegistrations[i]->Attendancepercentage();
					cout << m;
					gotoxy(10 + i, 44); cout << " %";
				}
			}
			else
			{
				gotoxy(5, 8);
				cout << "No students are Enrolled in " << Coursename << endl;
			}
			gotoxy(15 + currentRegs, 20);
			holdtillakeypressed(); cout << endl;
		}
		
		if (a == 3)
		{
			if (currentRegs != 0)
			{
				try
				{	
						system("cls");
						gotoxy(0, 25); cout << "Enter -1 to go back";
						gotoxy(3, 5);
						cout << "To Assign Marks , Enter appropriate Input for MARKS   " << endl;
						gotoxy(5, 6); cout << "Student Name/s";
						gotoxy(5, 40); cout << "Mark's Status" << endl;
						for (int i = 0; i < currentRegs; i++)
						{
							int stat = -99;
							gotoxy(7 + i, 6);
							cout << listofRegistrations[i]->getstudentname() << "( "
								<< listofRegistrations[i]->getstudentid() << " )";
							
							bool var1 = false, var2 = false;
							do
							{
								gotoxy(7 + i, 40);
								cin >> stat;
								var1 = cin.fail();
								if (var1)
								{
									gotoxy(7 + i, 40);
									cout << "Only Integer Marks are Allowed";
									Sleep(700);
									gotoxy(7 + i, 40);
									cout << "                                 ";
									gotoxy(7 + i, 40);
								}
								if (var1 == false)
								{
									if (stat == -1)
									{
										throw GoBack();
									}
									if (stat < 0)
									{
										var2 = true;
									}
									else
									{
										var2 = false;
									}
								}
								if (var2)
								{
									gotoxy(7 + i, 40);
									cout << "Only O or Greater Marks can be assigned to Student        ";
									Sleep(700);
									gotoxy(7 + i, 40);
									cout << "                                                        ";
									gotoxy(7 + i, 40);
								}
								if (var2 == false) { gotoxy(7 + i, 40); cout << "         "; }
								cin.clear();
								cin.ignore(10, '\n');
							} while (var1 || var2);
							listofRegistrations[i]->assignMarks( stat);
							gotoxy(7 + i, 40);
							cout << stat;
						}
				}
				catch (GoBack)
				{
					cout << "Going Back" << endl;
				}
				catch (...)
				{

				}
			}
			else
			{
				cout << "No Students Enrolled in Course " << Coursename << "Yet" << endl;
			}
			cout << endl;
			holdtillakeypressed();
		}
		if (a == 4)
		{
			viewAcademicStatus();
			holdtillakeypressed();
		}
		if (a == 5)
		{
			if (currentRegs != 0)
			{
				try
				{
					system("cls");
					gotoxy(0, 25); cout << "Enter Z/z to go back";
					gotoxy(3, 5);
					cout << "To Mark Grade , Enter appropriate Input for Grade (A/B/C/D/F ) for Student  " << endl;
					gotoxy(5, 6); cout << "Student Name/s";
					gotoxy(5, 35); cout << "Grade's Status" << endl;
					for (int i = 0; i < currentRegs; i++)
					{
						char stat = '-';
						gotoxy(7 + i, 6);
						cout << listofRegistrations[i]->getstudentname() << "( "
							<< listofRegistrations[i]->getstudentid() << " )";
						gotoxy(7 + i, 35);
						bool var1 = false;
						do
						{
							cin >> stat;
							var1 = ifGraderight(stat);
							if (var1)
							{
								if (stat == 'z' || stat == 'Z' || stat == '-')
								{
									throw GoBack();
								}
								gotoxy(7 + i, 35);
								cout << "Only A/B/C/D/F grade Allowed";
								Sleep(700);
								gotoxy(7 + i, 35);
								cout << "                                 ";
								gotoxy(7 + i, 35);
							}
							if (var1 == false) { gotoxy(7 + i, 35); cout << "     "; }
						} while (var1);
						gotoxy(7 + i, 35);
						cout << stat;
						listofRegistrations[i]->assignGrade(stat);
					}
				}
				catch (GoBack)
				{
					cout << "Going Back" << endl;
				}
				catch (...)
				{

				}
			}
			else
			{
				cout << "No Students Enrolled in Course " << Coursename << "Yet" << endl;
			}
			cout << endl;
			holdtillakeypressed();
		}
		if (a == 7)
		{
			if (currentRegs != 0)
			{
				cout << "The students enrolled in the course " << Coursename << " are" << endl;
				Showregstocourse();
			}
			else
			{
				cout << "No students are enrolled in the course " << Coursename  << endl;
			}
			holdtillakeypressed();
		}
	}
}
