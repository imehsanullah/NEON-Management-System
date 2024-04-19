#pragma once
#include"Student.h"
#include"Teacher.h"
#include"ITManager.h"
#include"Course.h"

class Department
{
	char* Deptname;
	Teacher* HOD;
	Teacher** listofTeachers;
	Student** listofStudents;
	ITManager* ITmanager;
	Course** listofCourses;
	int currentteachers;
	int currentstudents;
	int currentcourses;
	int maxteachers; int maxstudents; int maxcourses;
	bool registrationPeriod;
	bool WithdrawPeriod;
public:
	//Constructors
	Department(int  = 10);
	Department(Teacher* HOD1, int  = 10);
	Department(const char* name, int  = 10);
	Department(Teacher* HOD1, ITManager* man, int  = 10);
	
	//IMPORTANT:- The below 5 are the most Important Functions of Department Class
	//           and they are defined at the end of the file,These Functions Basically
	// are the code of the entire Interface Users have in this NeON System 


	//The main Function which is called from University,Which asks you to choose your Profession 
	void  Manual();
	//Every thing A HOD can Do is in this Function
	void  HODmanual();
	//Everything an IT-Manager can do is in this Function
	void ITmanagerManual();
	//Takes the Teacher to Teacher class to manage his duties and Evaluations
	void TeacherManual(int ind);
	//The function for a Student to manage/View  his things
	void StudentManualinDepartment();

	
	//To Set IT-Manager and HOD in Department
	void SetITManager(ITManager* obj);
	void SetHOD(Teacher* obj);
	
	//To Add A Course in the Department
	void addCourse(const char* ID, const char* name);
	
	//To Return the Department Name
	char* getDeptname();

	//To return the Index from listofStudents which matches the Students ID
	int FindIndexofStudentbyid(int id);
	
	//To return the Index from listofTeachers which matches the Teachers ID
	int FindIndexofTeacherbyid(int  id);
	
	//To return the Index from listofCourses which matches the Course ID
	int FindIndexofCoursebyid(char* name);
	
	//To return the Index from listofCourses which has the TA with Same ID
	int FindIndexofTAbyid(int id);
	
	//Return the Index of listofTeachers which the Course is assigned
	int FindwhichteacheraCourseisassigned(char* Cid);
	
	//To check the if the ID,the ITmanager is assigning is Unique
	//Matching ID with everyone Incase I want to Modify the Interface to Single Log-in
	bool checkuniqueStudentid(int id);
	
	//To check the if the ID,the ITmanager is assigning is Unique
	bool checkuniqueTeacherid(int id);
	
	//It is Called When IT-Manager Deletes a Students Account
	void unregisteraStudentfromallcourses(int id);
	
	
	//To Set Registration Period from Filing
	void SetRegistrationPeriod(int val);
	//To Set Course Withdraw Period from Filing
	void SetWithdrawPeriod(int val);
	
	

	//To Grow the 2-D arrays (Template Function void grow() can also be used for this)
	void extendlistofcourses();
	void extendlistofstudents();
	void extendlistofteachers();
	
	//To Add Teacher in Department
	void addTeacher(Teacher* T);

	//To Add Student in Department
	void addStudent(Student* S);
	
	void Print();
	
	//To get the Total Assigned Courses to Teachers in Department
	int getTotalAssignedcourses();
	
	//To get Total Registrations of Students in Departments
	int getTotalnoofRegs();
	
	//To Assign Courses from Filing
	void assigncoursetoteacher(int Tid, char* Courseid);
	
	// To Add Registration From Filing
	void addregistrationsfromfiling(char* Courseid, int Stdid, Registration* obj);
	
	//Function For Filing
	void WriteData(ofstream& fout);
	~Department();  //Destructor
	
};
//Constructors
Department::Department(int cap )
{
	WithdrawPeriod = false;
	HOD = 0; registrationPeriod = false;
	listofStudents = new Student * [cap];
	listofTeachers = new Teacher * [cap];
	listofCourses = new Course * [cap];
	ITmanager = 0;
	currentteachers = 0;
	currentstudents = 0;
	currentcourses = 0;
	Deptname = 0;
	maxteachers = cap; maxcourses = cap; maxstudents = cap;
}
Department :: Department(Teacher* HOD1, int cap )
{
	WithdrawPeriod = false;
	Deptname = 0; registrationPeriod = false;
	cout << "Department() called" << endl;
	HOD = HOD1;
	currentcourses = 0;
	listofStudents = new Student * [cap];
	ITmanager = 0;
	currentteachers = 0;
	currentstudents = 0;
	listofTeachers = new Teacher * [cap];
	listofCourses = new Course * [cap];
	listofTeachers[currentteachers++] = HOD1;
	maxteachers = cap; maxcourses = cap; maxstudents = cap;
}
Department :: Department(const char* name, int cap )
{
	WithdrawPeriod = false;
	HOD = 0; registrationPeriod = false;
	listofStudents = new Student * [cap];
	listofTeachers = new Teacher * [cap];
	ITmanager = 0;
	currentteachers = 0;
	currentstudents = 0;
	listofCourses = new Course * [cap];
	currentcourses = 0;
	if (name != 0) {
		Deptname = new char[strlen(name) + 1];
		for (int i = 0; name[i] != '\0'; i++)
		{
			Deptname[i] = name[i];
		}
		Deptname[strlen(name)] = '\0';
	}
	else
	{
		cout << "appropriate Name not entered of Department" << endl;
		Deptname = 0;
	}
	maxteachers = cap; maxcourses = cap; maxstudents = cap;
}
Department:: Department(Teacher* HOD1, ITManager* man, int cap )
{
	Deptname = 0; registrationPeriod = false; WithdrawPeriod = false;
	cout << "Department() called" << endl;
	HOD = HOD1;
	ITmanager = man;
	currentteachers = 0;
	currentstudents = 0;
	listofStudents = new Student * [cap];
	listofTeachers = new Teacher * [cap];
	listofCourses = new Course * [cap];
	listofTeachers[currentteachers++] = HOD1;
	currentcourses = 0;
	maxteachers = cap; maxcourses = cap; maxstudents = cap;
}
//Destructor
Department:: ~Department()  //Destructor
{
	cout << "~Department() called" << endl;
	delete[]Deptname;
	for (int i = 0; i < currentcourses; i++)
	{
		delete listofCourses[i];
	}
	delete[]listofCourses;
	delete[]listofTeachers;
	delete[]listofStudents;

}
//To SetITmanager
void Department::SetITManager(ITManager* obj)
{
	ITmanager = obj;
}
//To Set HOD
void Department::SetHOD(Teacher* obj)
{
	if (obj != 0)
	{
		HOD = obj;
		listofTeachers[currentteachers++] = obj;
	}
}
//To add a course in the Department
void Department::addCourse(const char* ID, const char* name)
{
	Course* temp = new Course(ID, name);
	if (currentcourses == maxcourses)
	{
		extendlistofcourses();
	}
	listofCourses[currentcourses++] = temp;
}
//To get the DEpartment Name
char* Department:: getDeptname()
{
	return Deptname;
}
//To return the Index from listofStudents which matches the Students ID
int Department::FindIndexofStudentbyid(int id)
{
	for (int i = 0; i < currentstudents; i++)
	{
		if (listofStudents[i]->getstudentid() == id)
		{
			return i;
		}
	}
	return -1;
}
//To return the Index from listofTeachers which matches the Teachers ID
int Department::FindIndexofTeacherbyid(int  id)
{
	for (int i = 0; i < currentteachers; i++)
	{
		if (listofTeachers[i]->getemployeeid() == id)
		{
			return i;
		}
	}
	return -1;
}
//To return the Index from listofCourses which matches the Course ID
int Department::FindIndexofCoursebyid(char* name)
{
	for (int i = 0; i < currentcourses; i++)
	{
		if (strcmp(name, listofCourses[i]->getcourseid()) == 0)
		{
			return i;
		}
	}
	return -1;
}
//To return the Index from listofCourses which has the TA with Same ID
int Department::FindIndexofTAbyid(int id)
{
	for (int i = 0; i < currentcourses; i++)
	{
		//See If the Course has same TA
		if (listofCourses[i]->checkifTAsame(id) == true)
		{
			return i;
		}
	}
	return -1;
}
//Return the Index of listofTeachers which the Course is assigned
int Department::FindwhichteacheraCourseisassigned(char* Cid)
{
	for (int i = 0; i < currentteachers; i++)
	{
		if (listofTeachers[i]->checkifCourseAssigned(Cid) == true)
		{
			/*listofTeachers[i]->unassignacoursefromteacher(Cid);*/
			return i;
		}
	}
	return -1;
}
//To check the if the ID,the ITmanager is assigning is Unique
bool Department::checkuniqueStudentid(int id)
{
	for (int i = 0; i < currentstudents; i++)
	{
		if (listofStudents[i]->getstudentid() == id)
		{
			return true;
		}
	}
	for (int i = 0; i < currentteachers; i++)
	{
		if (listofTeachers[i]->getemployeeid() == id)
		{
			return true;
		}
	}
	if (HOD->getemployeeid() == id || ITmanager->getemployeeid() == id)
	{
		return true;
	}
	if (FindIndexofTAbyid(id) != -1)
	{
		return true;
	}

	return false;
}
//To check the if the ID,the ITmanager is assigning is Unique
bool Department::checkuniqueTeacherid(int id)
{
	for (int i = 0; i < currentteachers; i++)
	{
		if (listofTeachers[i]->getemployeeid() == id)
		{
			return true;
		}
	}
	if (HOD->getemployeeid() == id || ITmanager->getemployeeid() == id)
	{
		return true;
	}
	if (FindIndexofTAbyid(id) != -1)
	{
		return true;
	}
	for (int i = 0; i < currentstudents; i++)
	{
		if (listofStudents[i]->getstudentid() == id)
		{
			return true;
		}
	}
	return false;
}
//It is Called When IT-Manager Deletes a Students Account
void Department:: unregisteraStudentfromallcourses(int id)
{
	int Sind = FindIndexofStudentbyid(id);
	if (Sind != -1)
	{
		for (int i = 0; i < currentcourses; i++)
		{
			int Rind = listofCourses[i]->checkifstudentregisteredbyid(id);
			if (Rind != -1)
			{
				listofCourses[i]->removeregfromcourse(Rind);
			}
		}
	}
}
void Department::SetRegistrationPeriod(int val)
{
	registrationPeriod = val;
}
void Department::SetWithdrawPeriod(int val)
{
	WithdrawPeriod = val;
}

void Department::extendlistofcourses()
{
	Course** temp = new Course * [currentcourses];
	for (int i = 0; i < currentcourses; i++)
	{
		temp[i] = listofCourses[i];
	}
	delete[]listofCourses;
	listofCourses = new Course * [maxcourses * 2];
	maxcourses = maxcourses * 2;
	for (int i = 0; i < currentcourses; i++)
	{
		listofCourses[i] = temp[i];
	}
	delete[]temp;
}
void Department::extendlistofstudents()
{
	Student** temp = new Student * [currentstudents];
	for (int i = 0; i < currentstudents; i++)
	{
		temp[i] = listofStudents[i];
	}
	delete[]listofStudents;
	listofStudents = new Student * [maxstudents * 2];
	maxstudents = maxstudents * 2;
	for (int i = 0; i < currentstudents; i++)
	{
		listofStudents[i] = temp[i];
	}
	delete[]temp;
}
void Department:: extendlistofteachers()
{
	Teacher** temp = new Teacher * [currentteachers];
	for (int i = 0; i < currentteachers; i++)
	{
		temp[i] = listofTeachers[i];
	}
	delete[]listofTeachers;
	listofTeachers = new Teacher * [maxteachers * 2];
	maxteachers = maxteachers * 2;
	for (int i = 0; i < currentteachers; i++)
	{
		listofTeachers[i] = temp[i];
	}
	delete[] temp;
}

void Department::addTeacher(Teacher* T)
{
	if (currentteachers == maxteachers - 1)
	{
		extendlistofteachers();
	}
	listofTeachers[currentteachers++] = T;
}
void Department::Print()
{
	for (int i = 0; i < currentteachers; i++)
	{
		listofTeachers[i]->Print();
	}
	holdtillakeypressed();
}
void Department::addStudent(Student* S)
{
	if (currentstudents == maxstudents - 1)
	{
		extendlistofstudents();
	}
	listofStudents[currentstudents++] = S;
}
int Department::getTotalAssignedcourses()
{
	int a = 0;
	for (int i = 0; i < currentteachers; i++)
	{
		a = a + listofTeachers[i]->getAssignedcourses();
	}
	return a;
}
int Department::getTotalnoofRegs()
{
	int a = 0;
	for (int i = 0; i < currentcourses; i++)
	{
		a = a + listofCourses[i]->getnoofRegs();
	}
	return a;
}
void Department::assigncoursetoteacher(int Tid, char* Courseid)
{
	int Teachind = FindIndexofTeacherbyid(Tid);
	int Cindex = FindIndexofCoursebyid(Courseid);
	if (Teachind != -1 && Cindex != -1)
	{
		listofTeachers[Teachind]->assigncoursetoteaacher(listofCourses[Cindex]);
	}
}
void Department:: addregistrationsfromfiling(char* Courseid, int Stdid, Registration* obj)
{
	int Sindex = FindIndexofStudentbyid(Stdid);
	int Cindex = FindIndexofCoursebyid(Courseid);
	if (Sindex != -1 && Cindex != -1)
	{
		obj->assigncourse(listofCourses[Cindex]);
		obj->assignstudent(listofStudents[Sindex]);
		listofCourses[Cindex]->addregistration(obj);
		listofStudents[Sindex]->addregistration(obj);
	}
}
void Department::WriteData(ofstream& fout)
{
	fout << Deptname << endl;
	fout << currentcourses << endl;
	for (int i = 0; i < currentcourses; i++)
	{
		listofCourses[i]->WriteData1(fout);
	}
	fout << currentteachers << endl;
	for (int i = 0; i < currentteachers; i++)
	{
		listofTeachers[i]->WriteData1(fout);
	}
	ITmanager->WriteData(fout);
	fout << currentstudents << endl;
	for (int i = 0; i < currentstudents; i++)
	{
		listofStudents[i]->WriteData1(fout);
	}
	fout << getTotalAssignedcourses() << endl;
	for (int i = 0; i < currentteachers; i++)//Course Assignment code
	{
		listofTeachers[i]->WriteData2(fout);
	}
	fout << getTotalnoofRegs() << endl;//Registration code
	for (int i = 0; i < currentcourses; i++)
	{
		listofCourses[i]->WriteData2(fout);
	}
	fout << registrationPeriod << ',' << WithdrawPeriod << endl;
}

//The main Function which is called from University,Which asks you to choose your Profession 
void Department::Manual()
{
	int a; int flag = 0;
	while (flag == 0)
	{
		a = -99;
		system("cls");
		cout << "Enter -1 to go back" << endl;
		cout << "Please choose your Profession at University to go to Respective account" << endl;
		cout << "Enter 0 For HOD" << endl;
		cout << "Enter 1 For ITmanager" << endl;
		cout << "Enter 2 For Teacher" << endl;
		cout << "Enter 3 For Student" << endl;
		cout << "Enter 4 For TA" << endl;

		bool bad = false;
		do {
			gotoxy(7, 0);
			cin >> a;
			bad = cin.fail();
			if (bad)
				cout << "Wrong value Enter again" << endl;
			cin.clear();
			cin.ignore(10, '\n');
		} while (bad);
		if (a == -1)
		{
			break;
		}
		if (a == 0)
		{
			HODmanual();

		}
		if (a == 1)
		{
			ITmanagerManual();
		}
		if (a == 2)
		{
			system("cls");
			cout << "Enter -1 to go back" << endl;
			cout << " To Perform your duty,First Sign in your account" << endl;
			int Tname = enterint("Enter the ID of the Teacher to sign in");
			if (Tname != -1)
			{
				int Tindex = FindIndexofTeacherbyid(Tname);
				if (Tindex != -1)
				{
					try
					{
						bool  var2 = false;
						if (listofTeachers[Tindex]->isPasswordNone() == false) {
							cout << "Enter -1 to go Back" << endl;
							cout << "PLease Enter Your Password Mr/Miss " << listofTeachers[Tindex]->getname() << endl;
						}
						do {
							if (listofTeachers[Tindex]->isPasswordNone() == true)
								throw PasswordMatched();
							char* Pass = new char[20];
							cin.getline(Pass, 20);
							if (strcmp(Pass, "-1") == 0)
							{
								delete[]Pass;
								throw 0;
							}
							var2 = listofTeachers[Tindex]->CheckPassword(Pass);
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
						listofTeachers[Tindex]->TeacherManual();
					}
					catch (int)
					{
						cout << "Going Back Please Wait" << endl; Sleep(700);
					}
				}
				else
				{
					cout << "You have entered wrong ID " << Tname << endl;
					holdtillakeypressed();
				}
			}
		}
		if (a == 3)
		{
			StudentManualinDepartment();
		}
		if (a == 4)
		{
			int taid; system("cls");
			taid = enterint2("Enter the id of the TA", "TA only have integer id");
			if (taid != -1)
			{
				int TAind = FindIndexofTAbyid(taid);
				if (TAind != -1)
				{
					listofCourses[TAind]->TAmanualinCourse();
				}
				else
				{
					cout << "TA with ID " << taid << " does not exist" << endl;
				}
				holdtillakeypressed();
			}
		}
	}
}
//Every thing A HOD can Do is in this Function
void Department::HODmanual()
{
	int flag = 0;
	if (HOD != 0)
	{
		system("cls");
		cout << "Enter -1 to go Back" << endl;
		int n = enterint("Please Enter your ID(HOD) ");
		//I have 0 as my Passkey to Facilitate my Testing 
		if (HOD->getemployeeid() == n || n == 0)
		{
			try
			{
				bool  var2 = false;
				/*cout << "Enter -1 to go Back" << endl;*/
				if (HOD->isPasswordNone() == false)
				{
					cout << "PLease Enter Your Password Mr/Miss " << HOD->getname() << endl;
				}
				do {
					if (HOD->isPasswordNone() == true)
						throw PasswordMatched();
					char* Pass = new char[20];
					cin.getline(Pass, 20);
					if (strcmp(Pass, "-1") == 0)
					{
						delete[]Pass;
						throw 0;
					}
					var2 = HOD->CheckPassword(Pass);
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
				while (flag == 0) {
					int a = -11;
					system("cls");
					cout << "Enter -1 to Go back" << endl;
					if (HOD->isPasswordNone() == true)
					{
						cout << "WARNING :- Please Set your Password For Security Purposes" << endl << endl;
					}
					cout << "Welcome Mr. " << HOD->getname() << " Enter Instructions to perform duties" << endl;
					cout << "Enter the Instructions to perform duties" << endl;
					cout << "Enter 0 to assign Course to a Teaher " << endl;
					cout << "Enter 1 to Register Course for a Student" << endl;
					cout << "Enter 2 to UN-Register Course for a Student" << endl;
					cout << "Enter 3 to view GRADES /Academic Status of Course" << endl;
					
					
					cout << "Enter 4 to Set/Change your Password" << endl;
					cout << "Enter 5 to view all the Courses Name in Department" << endl;
					cout << "Enter 6 to Create a Course " << endl;
					cout << "Enter 7 to view the Courses of Teachers" << endl;
					cout << "Enter 8 to view the Courses assigned to Students" << endl;
					cout << "Enter 9 to Change the status of registration Period";
					if (registrationPeriod == false)
						cout << " (it is Not-Active now)" << endl;
					else
						cout << " (it is Active now)" << endl;
					cout << "Enter 10 to Unassign a Course From Any Teacher" << endl;
					cout << "Enter 11 to ";
					if (WithdrawPeriod == false) { cout << " allow "; }
					else { cout << " not Allow "; }
					cout << "Students To Drop from a Course" << endl;
					bool bad = false;
					do {
						cout << "Enter Instruction " << endl;
						cin >> a;
						bad = cin.fail();
						if (bad)
							cout << "Error message:Wrong Input , Enter Integer only" << endl;
						cin.clear();
						cin.ignore(10, '\n');
					} while (bad);

					if (a == -1)
					{
						break;
					}
					if (a == 0)
					{
						if (currentcourses > 0)
						{
							system("cls");
							cout << "Enter -1 to Go back" << endl;
							cout << "To assign course Enter the Name of teacher and Course" << endl;
							int Tname = enterint("Enter the ID of Teacher");
							if (Tname != -1)
							{
								char* Cname = new char[30];
								cout << "Enter the ID of the course " << endl;
								cin.getline(Cname, 30);
								if (strcmp(Cname, "-1") != 0)
								{
									int Tindex = FindIndexofTeacherbyid(Tname);
									int Cindex = FindIndexofCoursebyid(Cname);
									if (Cindex != -1 && Tindex != -1)
									{
										//To check if the course is already not assigned to some other teacher
										if (FindwhichteacheraCourseisassigned(listofCourses[Cindex]->getcourseid()) == -1)
										{
											listofTeachers[Tindex]->assigncoursetoteaacher(listofCourses[Cindex]);
											cout << listofCourses[Cindex]->getcoursename() << " (" << listofCourses[Cindex]->getcourseid() << ") has been assigned to " << listofTeachers[Tindex]->getname() << endl;
										}
										else
										{
											cout << "The course  " << listofCourses[Cindex]->getcoursename() << " (" << listofCourses[Cindex]->getcourseid() << " )  is already be assigned to some other teacher" << endl;
										}

									}
									else if (Cindex == -1)
									{
										cout << "The course name is wrong or it does not exist" << endl;
									}
									else if (Tindex == -1)
									{
										cout << "The Teacher name is wrong or it does not exist" << endl;
									}

								}
								delete[]Cname;
								holdtillakeypressed();
							}
						}
						else
						{
							cout << "No courses exist to assign to any teacher" << endl;
							holdtillakeypressed();
						}
					}
					if (a == 1)
					{
						
						if (registrationPeriod == true) {
							system("cls");
							cout << "Enter -1 to Go back" << endl;
							cout << "To register course for the student" << endl;
							int Sname = enterint("Enter the ID of Student");
							if (Sname != -1)
							{
								char* Cname = new char[20];
								cout << "Enter the ID of the course" << endl;
								cin.getline(Cname, 20);
								if (strcmp(Cname, "-1") != 0)
								{
									int Cindex = FindIndexofCoursebyid(Cname);
									int Sindex = FindIndexofStudentbyid(Sname);
									delete[]Cname;
									if (Cindex != -1 && Sindex != -1)
									{
										if (listofCourses[Cindex]->checkifstudentregisteredbyid(listofStudents[Sindex]->getstudentid()) == -1)
										{
											if (listofStudents[Sindex]->getcurrentregs() < 5)
											{
												Registration* temp = new Registration(listofStudents[Sindex], listofCourses[Cindex]);
												listofStudents[Sindex]->addregistration(temp);
												listofCourses[Cindex]->addregistration(temp);
												cout << listofCourses[Cindex]->getcoursename() << " has been REGISTERED to ( " << listofStudents[Sindex]->getstudentid() << " ) " << listofStudents[Sindex]->getname() << endl;
											}
											else
											{
												cout << listofStudents[Sindex]->getname() << " is already registered in Maximum Courses,He/She cant take anymore Workload  " << endl;
											}
										}
										else
										{
											cout << "The Student already may be Registered in the Course" << endl;
										}
									}
									else if (Cindex == -1)
									{
										cout << "The course ID is wrong or it does not exist" << endl;
									}
									else if (Sindex == -1)
									{
										cout << "The Student ID is wrong or it does not exist" << endl;
									}

									holdtillakeypressed();
								}
							}
						}
						else
						{
							cout << "Registration Period is not Active " << endl;
							holdtillakeypressed();
						}
					}
					if (a == 2)
					{
						
							system("cls");
							cout << "Enter -1 to Go back" << endl;
							cout << "To Un-register a course for the student" << endl;
							int Sname = enterint("Enter the ID of the Student");
							if (Sname != -1)
							{
								char* Cname = new char[20];
								cout << "Enter the ID of the course" << endl;
								cin.getline(Cname, 20);
								if (strcmp(Cname, "-1") != 0)
								{
									int Cindex = FindIndexofCoursebyid(Cname);
									int Sindex = FindIndexofStudentbyid(Sname);
									if (Sindex != -1 && Cindex != -1)
									{
										int Sregindex = listofStudents[Sindex]->checkifcourseregisteredbyid(Cname);
										int Cregindex = listofCourses[Cindex]->checkifstudentregisteredbyid(listofStudents[Sindex]->getstudentid());
										if (Sregindex != -1 && Cregindex != -1)
										{
											listofCourses[Cindex]->removeregfromcourse(Cregindex);
											listofStudents[Sindex]->removeregfromstuedent(Sregindex);
											cout << listofStudents[Sindex]->getname() << " (" << listofStudents[Sindex]->getstudentid() << " ) has been UN-Registered from" << listofCourses[Cindex]->getcoursename() << "  " << listofCourses[Cindex]->getcourseid() << endl;
										}
										else
										{
											cout << "The student is not registered in this Course" << endl;
										}
									}
									else if (Cindex == -1)
									{
										cout << "The course does not exist or Name is wrong to Unregister for a Student" << endl;
									}
									else if (Sindex == -1)
									{
										cout << "The Student does not exist or Name is wrong to Unregister for a Course" << endl;
									}
								}
								delete[]Cname;
								holdtillakeypressed();
							}

					}
					if (a == 3)
					{
						char* Cname = entersinglename2("Enter the ID of the Course");
						int Cind = FindIndexofCoursebyid(Cname);
						if (Cind != -1)
						{
							listofCourses[Cind]->viewAcademicStatus();
						}
						else
						{
							cout << "Course with ID " << Cname << " does not exist in Department " << Deptname;
						}
						delete[]Cname;
						cout << endl << endl;
						holdtillakeypressed();
					}
					
					if (a == 4)
					{
						cout << "Please Enter your New Password" << endl;
						char* Pass = new char[20];
						cin.getline(Pass, 20);
						if (strcmp(Pass, "-1") != 0)
						{
							HOD->SetPassword(Pass);
							cout << "Your Password Has been changed" << endl;
							holdtillakeypressed();
						}
						delete[]Pass;
					}
					if (a == 5)
					{
						if (currentcourses != 0)
						{
							cout << "The courses in The Department are" << endl;
							for (int i = 0; i < currentcourses; i++)
							{
								listofCourses[i]->Print(); cout << endl;
							}
							holdtillakeypressed();
						}
						else
						{
							cout << "No courses exist in The Department" << endl;
						}
					}
					if (a == 6) //To create a course
					{
						char* Cname = entersinglename("Course");
						if (strcmp(Cname, "-1") != 0) {
							cout << "Enter the ID of the Course" << endl;
							char* ID = new char[20];
							cin.getline(ID, 20);
							if (strcmp(ID, "-1") != 0)
							{
								addCourse(ID, Cname);
								cout << "Course with ID " << ID << " and Name " << Cname << " has been Created" << endl;
								holdtillakeypressed();
							}
							delete[]ID;
						}
						delete[]Cname;

					}
					if (a == 7)
					{
						cout << "Enter the ID of teacher to see the Courses assigned to it" << endl;
						int Tname = enterint("Enter the ID of the Teacher");
						int index = FindIndexofTeacherbyid(Tname);
						if (index != -1)
						{
							listofTeachers[index]->viewcoursestoteacher();
						}
						else
						{
							cout << "No teacher with such ID exists" << endl;
						}
						holdtillakeypressed();

					}
					if (a == 8)
					{
						cout << "To see the courses Registered for a Student" << endl;
						int Sname = enterint("Enter the Id of the Student");
						if (Sname != -1)
						{
							int Sindex = FindIndexofStudentbyid(Sname);
							if (Sindex != -1)
							{
								listofStudents[Sindex]->ShowRegstoStudent();
							}
							else
							{
								cout << "The ID for Student is wrong or it does not exist" << endl;
							}
							holdtillakeypressed();
						}

					}
					if (a == 9)
					{
						if (registrationPeriod == false)
						{
							registrationPeriod = true;
							cout << "The registration Period has changed from Non-Active to Active";
						}
						else
						{
							registrationPeriod = false;
							cout << "The registration Period has changed from  Active to Non-Active ";
						}
						holdtillakeypressed();
					}
					if (a == 10)
					{
						char* Cid = entersinglename2("Enter the ID of the Course You want Unassign the teacher from");
						if (strcmp(Cid, "-1") != 0)
						{
							if (FindIndexofCoursebyid(Cid) != -1)
							{
								int Tind = FindwhichteacheraCourseisassigned(Cid);
								if (Tind != -1)
								{
									listofTeachers[Tind]->unassignacoursefromteacher(Cid);
									cout << "The Course with Id  " << Cid << " has been Unassigned from " << listofTeachers[Tind]->getname() << " (" << listofTeachers[Tind]->getemployeeid() << " )" << endl;
								}
								else
								{
									cout << "This Course is not Assigned to Any Teacher" << endl;
								}
							}
							else
							{
								cout << "The Course does not Exist in Department" << endl;
							}
							holdtillakeypressed();
						}
						delete[]Cid;
					}
					if (a == 11)
					{
						if (WithdrawPeriod == true)
						{
							cout << "Students will no Further be allowed to Withdraw from Courses" << endl;
							WithdrawPeriod = false;
						}
						else
						{
							cout << "Students will now be allowed to Withdraw from Courses" << endl;
							WithdrawPeriod = true;
						}
						holdtillakeypressed();
					}
				}
			}
			catch (int)
			{
				cout << "Going Back Please wait" << endl; Sleep(500);
			}
		}
		else//here
		{
			if (n == -1)
			{

			}
			else
			{
				cout << "You Entered Wrong ID" << endl;
				cout << "Going back " << endl;
				holdtillakeypressed();
			}

		}//here

	}
	else
	{
		cout << "HOD is not assigned in " << Deptname << " yet" << endl;
		holdtillakeypressed();
	}
}
//Everything an IT-Manager can do is in this Function
void Department::ITmanagerManual()
{
	int flag = 0, a = -3;

	if (ITmanager != 0)
	{
		system("cls");
		cout << "Enter -1 to go Back" << endl;
		int n = enterint("Please Enter your ID (IT-Manager)");
		if (ITmanager->getemployeeid() == n || n == 0) {
			try
			{
				bool  var2 = false;
				/*cout << "Enter -1 to go Back" << endl;*/
				if (ITmanager->isPasswordNone() == false)
				{
					cout << "PLease Enter Your Password Mr/Miss " << ITmanager->getname() << endl;
				}
				do {
					if (ITmanager->isPasswordNone() == true)
						throw PasswordMatched();
					char* Pass = new char[20];
					cin.getline(Pass, 20);
					if (strcmp(Pass, "-1") == 0)
					{
						delete[]Pass;
						throw 0;
					}
					var2 = ITmanager->CheckPassword(Pass);
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
				while (flag == 0)
				{
					system("cls");
					cout << "Enter -1 to exit" << endl;
					if (ITmanager->isPasswordNone() == true)
					{
						cout << "WARNING:- Please Set Your Password For Security Purposes" << endl << endl;
					}
					cout << "Welcome " << ITmanager->getname() << "  to perform your duties" << endl;
					cout << "Enter 0 to Create Acc. of Teacher" << endl;
					cout << "Enter 1 to Delete Acc. of Teacher" << endl;
					cout << "Enter 2 to Create Acc. of Student" << endl;
					cout << "Enter 3 to Delete Acc. of Student" << endl;
					cout << "Enter 4 to Change the Username of People" << endl;
					cout << "Enter 5 to Change the Password of other People" << endl;
					cout << "Enter 6 to View all the Students" << endl;
					cout << "Enter 7 to Set/Change your Password" << endl;
					cout << "Enter 8 to View all the teachers" << endl;
					
					
					cout << "Enter 9 to Make a Student TA" << endl;
					cout << "Enter 10 to remove a TA from course" << endl;
					bool bad = false;
					do {
						cin >> a;
						bad = cin.fail();
						if (bad)
							cout << "Wrong value Enter again" << endl;
						cin.clear();
						cin.ignore(10, '\n');
					} while (bad);
					if (a == -1)
					{
						break;
					}
					if (a == 0)
					{
						int ID;
						cout << "Enter ID for teacher" << endl;
						bool fag1 = false; bool fag2 = false;
						do
						{
							cin >> ID;
							fag1 = cin.fail();
							if (fag1 == false)
							{
								fag2 = checkuniqueTeacherid(ID);
							}
							if (fag1)
								cout << "Only Integers are allowed for ID" << endl;
							if (fag2)
								cout << "This ID exists for Someother Employee ,Please Enter Again" << endl;
							cin.clear();
							cin.ignore(10, '\n');
						} while (fag1 || fag2);
						if (ID != -1)
						{
							char* temp = entersinglename("Teacher");
							if (strcmp(temp, "-1") != 0)
							{
								Teacher* obj = new Teacher(ID, temp);
								if (currentteachers == maxteachers - 1)
								{
									extendlistofteachers();
								}
								listofTeachers[currentteachers++] = obj;
								cout << "Teacher account with Name " << temp << " and ID " << ID << " is created" << endl;
								holdtillakeypressed();
							}
							delete[]temp;
						}
					}
					if (a == 1)
					{
						cout << "Enter -1 to go back" << endl;
						cout << "To delete the account" << endl;
						int temp = enterint("Enter the ID of Teacher");
						if (temp != -1)
						{
							int index = FindIndexofTeacherbyid(temp);
							if (index != -1)
							{
								cout << "Teacher account with Name:- " << listofTeachers[index]->getname() << " and ID " << temp << " is deleted" << endl;
								holdtillakeypressed();
								delete listofTeachers[index];
								listofTeachers[index] = 0;
								for (int i = index; i < currentteachers - 1; i++)
								{
									listofTeachers[i] = listofTeachers[i + 1];
								}
								currentteachers--;
							}
							else
							{
								cout << "No techer with this ID" << temp << "exists" << endl;
							}
						}
					}
					if (a == 2)
					{
						int ID;
						cout << "Enter ID for the Student" << endl;
						bool fag1 = false; bool fag2 = false;
						do
						{
							cin >> ID;
							fag1 = cin.fail();
							if (fag1 == false)
							{
								fag2 = checkuniqueStudentid(ID);
							}
							if (fag1)
								cout << "Only Integers are allowed for ID" << endl;
							if (fag2)
								cout << "This ID exists for someother Student,Please Enter Again" << endl;
							cin.clear();
							cin.ignore(10, '\n');
						} while (fag1 || fag2);
						if (ID != -1) {
							char* name = entersinglename("Student");
							if (strcmp(name, "-1") != 0)
							{
								Student* temp = new Student(ID, name);
								if (currentstudents == maxstudents - 1)
								{
									extendlistofstudents();
								}
								cout << "Student account with Name:- " << name << " and ID " << ID << " is created" << endl;
								holdtillakeypressed();
								listofStudents[currentstudents++] = temp;
							}
							delete[]name;
						}
					}
					if (a == 3)
					{
						cout << "Enter -1 to go back" << endl;
						cout << "To delete the account" << endl;
						int temp = enterint("Enter the ID of Student");
						if (temp != -1)
						{
							int index = FindIndexofStudentbyid(temp);
							if (index != -1)
							{
								unregisteraStudentfromallcourses(listofStudents[index]->getstudentid());
								cout << "Student account with Name:- " << listofStudents[index]->getname() << " and ID " << temp << " is deleted" << endl;
								holdtillakeypressed();
								delete listofStudents[index];
								listofStudents[index] = 0;
								for (int i = index; i < currentstudents - 1; i++)
								{
									listofStudents[i] = listofStudents[i + 1];

								}
								currentstudents--;
							}
						}
					}
					if (a == 4)
					{
						int z;
						cout << "Whose Name do you want to change" << endl;
						cout << "Enter 1 for Student" << endl;
						cout << "Enter 2 for Teacher" << endl;
						cout << "Enter 3 for HOD" << endl;
						bool bad3 = false;
						do {
							cin >> z;
							bad3 = cin.fail();
							if (bad3)
								cout << "Enter Integer Instruction" << endl;
							cin.clear();
							cin.ignore(10, '\n');
						} while (bad3);
						if (z == 1)
						{
							cout << "Enter -1 to go back" << endl;
							int S = enterint("Enter the ID of Student to change his Name");
							if (S != -1)
							{
								int I1 = FindIndexofStudentbyid(S);
								if (I1 != -1)
								{
									char* S1 = entersinglename2("Enter the new Username ");
									if (strcmp(S1, "-1") != 0)
									{
										cout << "Student Name has changed from " << listofStudents[I1]->getname() << " to " << S1 << endl;
										listofStudents[I1]->changename(S1);
									}
									delete[]S1;
								}
								else
								{
									cout << "Wrong ID,No student with the ID exist" << endl;
								}
								holdtillakeypressed();
							}
						}
						if (z == 2)
						{
							int T = enterint("Enter the ID of Teacher whose Username you want to change");
							if (T != -1)
							{
								int T1 = FindIndexofTeacherbyid(T);
								if (T1 != -1)
								{
									char* nname = entersinglename2("Enter the new name of Teacher");
									if (strcmp(nname, "-1") != 0)
									{
										cout << "Teacher Name has changed from  " << listofTeachers[T1]->getname() << " to " << nname << endl;
										listofTeachers[T1]->changename(nname);
									}
									delete[]nname;
								}
								else
								{
									cout << "Wrong ID, No teacher  exists with this ID" << endl;
								}
								holdtillakeypressed();
							}
						}
						if (z == 3)
						{
							if (HOD != 0)
							{
								char* hodname = entersinglename2("Enter the new name of HOD");
								if (strcmp(hodname, "-1") != 0)
								{
									cout << "The HOD name has changed from " << HOD->getname() << " to " << hodname << endl;

									HOD->changename(hodname);
								}
								delete[] hodname;
							}
							else
							{
								cout << "No HOD exists in " << Deptname;
							}
							holdtillakeypressed();
						}
					}
					if (a == 5)
					{
						int z;
						cout << "Whose PassWord do you want to change" << endl;
						cout << "Enter 1 for Student" << endl;
						cout << "Enter 2 for Teacher" << endl;
						cout << "Enter 3 for HOD" << endl;
						bool bad3 = false;
						do {
							cin >> z;
							bad3 = cin.fail();
							if (bad3)
								cout << "Enter Integer Input" << endl;
							cin.clear();
							cin.ignore(10, '\n');
						} while (bad3);
						if (z == 1)
						{
							cout << "Enter -1 to go back" << endl;
							int S1 = enterint("Enter the ID of Student to change his Password");
							if (S1 != -1)
							{
								int I1 = FindIndexofStudentbyid(S1);
								if (I1 != -1)
								{
									char* pass = new char[20];
									cout << "Enter the new Password of " << listofStudents[I1]->getname() << endl;
									cin.getline(pass, 20);
									if (strcmp(pass, "-1") != 0)
									{
										listofStudents[I1]->SetPassword(pass);
										cout << "Password of " << listofStudents[I1]->getname() << "(" << listofStudents[I1]->getstudentid() << ") has been changed" << endl;
									}
									delete[]pass;
								}
								else
								{
									cout << "Wrong ID, No student  exists with the ID " << S1 << endl;
								}
								holdtillakeypressed();
							}

						}
						if (z == 2)
						{
							cout << "Enter -1 to go back" << endl;
							int T1 = enterint("Enter the ID of Teacher to change his Password");
							if (T1 != -1)
							{
								int I2 = FindIndexofTeacherbyid(T1);
								if (I2 != -1)
								{
									char* pass1 = new char[20];
									cout << "Enter the new Password of " << listofTeachers[I2]->getname() << endl;
									cin.getline(pass1, 20);
									if (strcmp(pass1, "-1") != 0)
									{
										listofTeachers[I2]->SetPassword(pass1);
										cout << "Password of " << listofTeachers[I2]->getname() << " has been changed" << endl;
									}
									delete[] pass1;
								}
								else
								{
									cout << "Wrong ID ,NO Teacher exists with ID" << T1 << endl;
								}
								holdtillakeypressed();
							}

						}
						if (z == 3)
						{
							if (HOD != 0)
							{
								char* pass3 = new char[20];
								cout << "Enter the New password of" << HOD->getname() << endl;
								cin.getline(pass3, 20);
								if (strcmp(pass3, "-1") != 0)
								{
									HOD->SetPassword(pass3);
									cout << "Password of HOD has been changed" << endl;
								}
								delete[]pass3;
							}
							else
							{
								cout << "No HOD exists in Department" << Deptname;
							}
							holdtillakeypressed();
						}
					}
					if (a == 6)
					{
						if (currentstudents != 0)
						{
							cout << "The Students in " << Deptname << " are" << endl;
							for (int i = 0; i < currentstudents; i++)
							{
								listofStudents[i]->Print();
							}
						}
						else
						{
							cout << "No Student in " << Deptname << " exists" << endl;
						}
						holdtillakeypressed();
					}
					if (a == 7)
					{
						cout << "Please Enter your New Password" << endl;
						char* Pass = new char[20];
						cin.getline(Pass, 20);
						if (strcmp(Pass, "-1") != 0)
						{
							ITmanager->SetPassword(Pass);
						}
						delete[]Pass;
					}
					if (a == 8)
					{
						if (currentteachers != 0)
						{
							cout << "The Teachers in " << Deptname << " are " << endl;
							for (int i = 0; i < currentteachers; i++)
							{
								listofTeachers[i]->Print();
							}
						}
						else
						{
							cout << "No teacher in " << Deptname << " exists" << endl;
						}
						holdtillakeypressed();
					}
					
					
					if (a == 9)
					{
						system("cls");
						int Sid = enterint2("Enter the id of Student You Want to Make TA", "Only Integer IDs are allowed");
						if (Sid != -1)
						{
							int Sindex = FindIndexofStudentbyid(Sid);
							if (Sindex != -1)
							{
								if (strcmp(listofStudents[Sindex]->Purpose(), "Student") == 0)//To check that the Entity is a Student
								{
									char* Cname = entersinglename2("Enter the ID of the Course to Assign TA");
									if (strcmp(Cname, "-1") != 0)
									{
										int Cind = FindIndexofCoursebyid(Cname);
										if (Cind != -1)
										{
											if (listofCourses[Cind]->checkifstudentregisteredbyid(Sid) == -1) //To check if student is enrolled in class
											{
												if (listofCourses[Cind]->checkifTAexists() == false) //To check if there is already a TA in Course
												{
													int TAid; bool fag1 = false, fag2 = false;
													cout << "Enter the ID for the TA" << endl;
													do
													{
														cin >> TAid;
														fag1 = cin.fail();
														if (fag1 == false)
														{
															fag2 = checkuniqueStudentid(TAid);
														}
														if (fag1)
															cout << "Only Integers are allowed for ID" << endl;
														if (fag2)
															cout << "This ID exists for someother Person,Please Enter Again" << endl;
														cin.clear();
														cin.ignore(10, '\n');
													} while (fag1 || fag2);
													if (TAid != -1)
													{
														//TA(int ID, int EmpID, const char* name,Registration** list,int Sregs)									
														TA* temp = new TA(listofStudents[Sindex]->getstudentid(), TAid, listofStudents[Sindex]->getname(), listofStudents[Sindex]->getlistofRegistrations(), listofStudents[Sindex]->getcurrentregs());
														temp->SetPassword(listofStudents[Sindex]->getPassword());
														listofCourses[Cind]->SetTA(temp);
														/*delete listofStudents[Sindex];*/
														listofStudents[Sindex] = 0;
														listofStudents[Sindex] = temp;
													}
												}
												else
												{
													cout << "The Course Already has a TA" << endl;
												}
											}
											else
											{
												cout << "Student is already Enrolled in this Course" << listofCourses[Cind]->getcoursename() << " , So he is not allowed to become the TA" << endl;
											}
										}
										else
										{
											cout << "Course with ID " << Cname << " does not exist" << endl;
										}
									}
									delete[]Cname;
								}
								else
								{
									cout << "This Student is Already a TA in some course" << endl;
								}
							}
							else
							{
								cout << "No Student with id" << Sid << " exists" << endl;
							}
						}
						holdtillakeypressed();
					}
					if (a == 10)
					{
						int taid = enterint2("Enter the ID of the TA to remove him", "TA ID is only in ID");
						if (taid != -1)
						{
							if (FindIndexofTAbyid(taid) != -1) //Returns the Index of Course Which has the TA
							{
								char* Cname = entersinglename2("Enter the ID of the Course you want to remove TA from");
								if (strcmp(Cname, "-1") != 0)
								{
									int Cind = FindIndexofCoursebyid(Cname);
									if (Cind != -1)
									{
										if (listofCourses[Cind]->checkifTAexists() == true)//To check if there is a TA in the course
										{
											if (listofCourses[Cind]->checkifTAsame(taid))
											{
												TA* obj;
												obj = listofCourses[Cind]->UnSetTA();
												if (obj != 0)
												{
													int Sindex = FindIndexofStudentbyid(obj->getstudentid());
													if (Sindex != -1)
													{
														Student* temp = new Student(obj->getstudentid(), obj->getname(), obj->getlistofRegistrations(), obj->getcurrentregs());
														delete listofStudents[Sindex];
														listofStudents[Sindex] = temp;
													}
												}
											}
											else
											{
												cout << "This TA with ID" << taid << "is not assigned in this course" << endl;
											}

										}
										else
										{
											cout << "No TA is Assigned in this course" << endl;
										}
									}
									else
									{
										cout << "No course with this ID exists" << endl;
									}
								}
								delete[]Cname;
							}
							else
							{
								cout << "No TA exists with this ID" << endl;
							}
							holdtillakeypressed();
						}
					}
				}
			}
			catch (int)
			{
				cout << "Going Back please wait" << endl; Sleep(700);
			}
		}
		else//Here
		{
			if (n == -1)
			{

			}
			else
			{
				cout << "You Entered Wrong ID" << endl; Sleep(700);
			}
		}//Here

	}
	else
	{
		cout << " ITmanager not assigned to Department" << Deptname << endl;
		holdtillakeypressed();
	}

}
//Takes the Teacher to Teacher class to Perform HIS Evaluation/Duties
void Department::TeacherManual(int ind)
{
	if (listofTeachers[ind] != 0)
	{
		listofTeachers[ind]->TeacherManual();
	}
}
//The function for a Student to manage/View his things
void Department::StudentManualinDepartment()
{
	system("cls");
	cout << "Enter -1 to go back" << endl;
	cout << "To see your evaluation/Performance or for Registration Please sign in your account" << endl;
	int Sname = enterint("Enter the ID of Student to sign in");
	if (Sname != -1)
	{
		int Sindex = FindIndexofStudentbyid(Sname);
		if (Sindex != -1)
		{
			try
			{
				bool  var2 = false;
				if (listofStudents[Sindex]->isPasswordNone() == false)
				{
					/*cout << "Enter -1 to go Back" << endl;*/
					cout << "PLease Enter Your Password  " << listofStudents[Sindex]->getname() << endl;
				}
				do {
					if (listofStudents[Sindex]->isPasswordNone() == true)
						throw PasswordMatched();
					char* Pass = new char[20];
					cin.getline(Pass, 20);
					if (strcmp(Pass, "-1") == 0)
					{
						delete[]Pass;
						throw 0;
					}
					var2 = listofStudents[Sindex]->CheckPassword(Pass);
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
				int flag1 = 0;
				while (flag1 == 0)
				{
					int n; system("cls");
					cout << "Enter -1 to go back" << endl;
					if (listofStudents[Sindex]->isPasswordNone() == true)
					{
						cout << "WARNING :- Please Set Your Password for Security Purposes" << endl << endl;
					}
					cout << "Enter 0 to check the Record of your courses" << endl;
					cout << "Enter 1 to Set/Change your Password" << endl;
					if (registrationPeriod == true)
					{
						cout << "Enter 2 to Register/Unregister in a course as the registration Period is active " << endl;
					}
					else {
						cout << "The registration period is not active yet,Please Consult your HOD to Register / UN-Register " << endl;
					}
					cout << "Enter 3 to WithDraw from a course ";
					if (WithdrawPeriod == true) { cout << " ( Allowed right now )" << endl; }
					else { cout << " ( Not Allowed right now )" << endl; }
					cout << "Enter 4 to View Your Marksheet" << endl;
					cout << "Enter 5 to View Your Attendance in All Courses" << endl;
					bool bad = false;
					do {
						cout << "Enter number: ";
						cin >> n;
						bad = cin.fail();
						if (bad)
							cout << "Enter Integer Input" << endl;
						cin.clear();
						cin.ignore(10, '\n');
					} while (bad);
					if (n == -1)
						break;
					if (n == 0)
					{
						listofStudents[Sindex]->StudentManual();
					}
					if (n == 1)
					{
						cout << "Please Enter your New Password" << endl;
						char* Pass = new char[20];
						cin.getline(Pass, 20);
						if (strcmp(Pass, "-1") != 0)
						{
							listofStudents[Sindex]->SetPassword(Pass);
							cout << "Your Password has been reset" << endl;
						}
						delete[]Pass;
					}
					else if (n == 2 && registrationPeriod == true)
					{
						int z; system("cls"); cout << "Enter -1 to go Back" << endl;
						cout << "Enter 1 if you want to Register in a Course" << endl;
						cout << "Enter 2 if you want to Un-Register from a Course" << endl;
						bool bad = false;
						do {
							cin >> z;
							bad = cin.fail();
							if (bad)
								cout << "Only Integer Input allowed" << endl;
							cin.clear();
							cin.ignore(10, '\n');
						} while (bad);
						if (z == -1) {}
						if (z == 1) {
							char* Cname = entersinglename2("Enter the ID of Course for Registration");
							if (strcmp(Cname, "-1") != 0)
							{
								int Cindex = FindIndexofCoursebyid(Cname);
								if (Cindex != -1)
								{
									//To check if the Student is registered in less than 5 Courses
									if (listofStudents[Sindex]->getcurrentregs() < 5)
									{
										//To check that the Student is already not Registered in the same Course
										if (listofStudents[Sindex]->checkifcourseregisteredbyid(Cname) == -1)
										{
											Registration* temp = new Registration(listofStudents[Sindex], listofCourses[Cindex]);
											//Sending The Registration To both
											listofStudents[Sindex]->addregistration(temp);
											listofCourses[Cindex]->addregistration(temp);
											cout << "You have Successfully registererd in " << listofCourses[Cindex]->getcoursename() << " (" << listofCourses[Cindex]->getcourseid() << " )" << endl;
										}
										else
										{
											cout << " The Student  " << listofStudents[Sindex]->getname() << "( " << listofStudents[Sindex]->getstudentid() << " ) May already be registered in Course " << Cname << endl;
										}
									}
									else
									{
										cout << "You have already registered in Maximum courses " << endl;
									}
								}
								else
								{
									cout << "The Course " << Cname << "Does not exist to register";
								}
								holdtillakeypressed();
							}
							delete[]Cname;
						}
						if (z == 2)
						{
							char* Cname = entersinglename2("Enter the ID of the Course you want to Un-register from");
							if (strcmp(Cname, "-1") != 0)
							{
								int Cin = FindIndexofCoursebyid(Cname);
								if (Cin != -1)
								{
									//To check if the Student is Registered in the course
									int Stdind = listofStudents[Sindex]->checkifcourseregisteredbyid(Cname);
									int Cind = listofCourses[Cin]->checkifstudentregisteredbyid(listofStudents[Sindex]->getstudentid());
									if (Stdind != -1 && Cind != -1)
									{
										listofStudents[Sindex]->removeregfromstuedent(Stdind);
										listofCourses[Cin]->removeregfromcourse(Cind);
										cout << "You have Successfully been Un-Registered from " << listofCourses[Cin]->getcoursename() << "(" << listofCourses[Cin]->getcourseid() << ")" << endl;
									}
									else
									{
										cout << listofStudents[Sindex]->getname() << " is not registered in the Course" << Cname << endl;
									}
								}
								else
								{
									cout << "The course doesnot exist in" << Deptname << endl;
								}
								holdtillakeypressed();
							}
							delete[] Cname;
						}
					}
					else if (n == 3)
					{
						if (WithdrawPeriod == true)
						{
							char* Cname = entersinglename2("Enter the ID of the Course you want to Withdraw from");
							if (strcmp(Cname, "-1") != 0)
							{
								int Cin = FindIndexofCoursebyid(Cname);
								if (Cin != -1)
								{
									int Stdind = listofStudents[Sindex]->checkifcourseregisteredbyid(Cname);
									int Cind = listofCourses[Cin]->checkifstudentregisteredbyid(listofStudents[Sindex]->getstudentid());
									if (Stdind != -1 && Cind != -1)
									{
										/*listofStudents[Sindex]->removeregfromstuedent(Stdind);*/
										listofCourses[Cin]->removeregfromcourse(Cind);
										listofStudents[Sindex]->withdrawfromCourse(Stdind);
										cout << listofStudents[Sindex]->getname() << " (" << listofStudents[Sindex]->getstudentid() << " ) has Successfully withdrawed from " << listofCourses[Cin]->getcoursename() << " (" << listofCourses[Cin]->getcourseid() << " )" << endl;
										holdtillakeypressed();
									}
									else
									{
										cout << "You are not registered in this course" << endl;
										holdtillakeypressed();
									}
								}
								else
								{
									cout << "The course does not exist in" << Deptname << endl;
								}
							}
							delete[] Cname;
						}
						else
						{
							cout << "You are not allowed To with-Draw from any Course Right now " << endl;
							holdtillakeypressed();
						}
					}
					else if (n == 4)
					{
						listofStudents[Sindex]->seeAcademicstatus();
					}
					else if (n == 5)
					{
						listofStudents[Sindex]->viewentireAttendance();
					}

				}
			}
			catch (int)
			{
				cout << "Going Back PLease wait" << endl; Sleep(700);
			}
		}
		else
		{
			cout << "The student " << Sname << " does not exist in " << Deptname << endl;
		}
	}
}