//IMPORTANT:- Kindly Look into the Helper.h file as well as it contains the Template functions
//, Template classes ,2D Growing and Shrinking of Arrays and Exception Handling Stuff as well 

#include"TA.h"
#include"Registration.h"
#include"Course.h"
#include"Student.h"
#include"Department.h"
#include"University.h"
#include<conio.h>

//For teacher's sample Data which just contains Basic Information
University* ReadDatafromfile1(const char* fname) //"basedata.txt"
{
	ifstream fin;
	fin.open(fname);
	if (fin.is_open())
	{
		char* Uniname = new char[30];
		 char junk;
		int deptnums; int coursenums;
		fin.getline(Uniname, 30);
		University *Uni =new University (Uniname);
		fin >> deptnums; fin.ignore();
		for (int l = 0; l < deptnums; l++)
		{
			char* deptname = new char[30];
			fin.getline(deptname, 30);
			Department* Dep = new Department(deptname);
			fin >> coursenums; fin.ignore();
			for (int i = 0; i < coursenums; i++)
			{
				char* CId = new char[6]; fin.getline(CId, 6, ',');
				char* Cname = new char[30]; fin.getline(Cname, 30);
				Dep->addCourse(CId, Cname);
				delete[]CId; delete[]Cname; 
			}
			int facnums;
			fin >> facnums; fin.ignore();
			int empnum; char* name = new char[30];
			fin >> empnum; fin >> junk; fin.getline(name, 30);
			Teacher* hod = new Teacher(empnum, name);
			Dep->SetHOD(hod);
			delete[]name; 
			for (int i = 0; i < facnums - 1; i++)//Add Teachers
			{
				 name = new char[30];
				fin >> empnum; fin >> junk; fin.getline(name, 30);
				Teacher* T = new Teacher(empnum,name);
				Dep->addTeacher(T); 
				delete[]name; 
			}
			int noofITm;fin >> noofITm; fin.ignore();
			for (int i = 0; i < noofITm; i++)//the loop makes no difference, it will be executed once only
			{
				 name = new char[30];
				fin >> empnum; fin >> junk; fin.getline(name, 30);
				ITManager* It = new ITManager(empnum,name);
				Dep->SetITManager(It);
				delete[]name; 
			}
			int noofstuds;
			fin >> noofstuds; fin.ignore();
			int stdID;
			for (int i = 0; i < noofstuds; i++)
			{
				char* name = new char[30];
				fin >> stdID; fin >> junk; fin.getline(name, 30);
				Student* S = new Student(stdID, name);
				Dep->addStudent(S);
				delete[]name; 
			}
			Uni->addDepartment(Dep);
			delete[]deptname;
		}
		delete[]Uniname;
		return Uni;
	}
	else
	{
		cout << "Data can not be read , you may not have included the file" << endl;
	}
	return 0;
}
//For Reading Own Data which includes Assign Courses,Registrations and Passwords etc
University* ReadDatafromfile2(const char* fname)//"UniversityDataBackup.txt"
{
	ifstream fin;
	fin.open(fname);
	if (fin.is_open())
	{
		char* Uniname = new char[30];
		char junk;
		int deptnums; int coursenums;
		fin.getline(Uniname, 30);
		University* Uni = new University(Uniname);
		fin >> deptnums; fin.ignore();
		for (int l = 0; l < deptnums; l++) {
			char* deptname = new char[30];
			fin.getline(deptname, 30);
			Department* Dep = new Department(deptname);
			fin >> coursenums; fin.ignore(); 
			for (int i = 0; i < coursenums; i++)
			{
				char* CId = new char[6]; fin.getline(CId, 6, ',');
				char* Cname = new char[30]; fin.getline(Cname, 30);
				Dep->addCourse(CId, Cname); 
				delete[]CId; delete[]Cname;
			}
			int facnums;
			fin >> facnums; fin.ignore(); cout << facnums;
			int empnum; char* name = new char[30]; char* pass = new char[20];
			fin >> empnum; fin >> junk; fin.getline(name, 30, ','); fin.getline(pass, 20);
			Teacher* hod = new Teacher(empnum, name);
			hod->SetPassword(pass);
			Dep->SetHOD(hod);
			delete[]name; delete[] pass;
			for (int i = 0; i < facnums - 1; i++)//Adding Teachers
			{
				name = new char[30]; pass = new char[20];
				fin >> empnum; fin >> junk; fin.getline(name, 30, ',');
				fin.getline(pass, 20);
				Teacher* T = new Teacher(empnum, name);
				T->SetPassword(pass);
				Dep->addTeacher(T); //Addteacher()  func
				cout << empnum << "," << name << "," << pass << endl;
				delete[]name; delete[] pass;
			}
			int noofITm; fin >> noofITm; fin.ignore();
			name = new char[30]; pass = new char[20];
			fin >> empnum; fin >> junk; fin.getline(name, 30, ','); fin.getline(pass, 20);
			ITManager* It = new ITManager(empnum, name);
			It->SetPassword(pass);
			Dep->SetITManager(It);  //Setting IT-MAnager
			cout << empnum << "," << name << "," << pass << endl;
			delete[]name; delete[]pass;

			int noofstuds;
			fin >> noofstuds; fin.ignore(); cout << noofstuds;
			int stdID;
			for (int i = 0; i < noofstuds; i++)//Adding Students
			{
				name = new char[30]; pass = new char[20];
				fin >> stdID; fin >> junk; fin.getline(name, 30, ',');
				fin.getline(pass, 20);
				Student* S = new Student(stdID, name);
				S->SetPassword(pass);
				Dep->addStudent(S);
				cout << stdID << "," << name << "," << pass << endl;
				delete[]name; delete[]pass;
			}
			//Assigning Courses to Teachers
			int CourseAss; fin >> CourseAss; fin.ignore();
			for (int i = 0; i < CourseAss; i++)
			{
				int Tid; char* Couid = new char[20];
				fin >> Tid; fin >> junk; fin.getline(Couid, 20);
				Dep->assigncoursetoteacher(Tid, Couid);
				delete[] Couid;
			}
			//Registring Student's
			int Totregs; fin >> Totregs; fin.ignore();
			for (int i = 0; i < Totregs; i++)
			{
				int* arr; int num;
				char* Couid = new char[10]; int stdid; char Grad; int mark, maxlecs;
				fin.getline(Couid, 10, ',');
				fin >> stdid; fin >> junk; fin >> Grad; fin >> junk; fin >> mark; fin >> junk; fin >> maxlecs; fin >> junk;
				arr = new int[maxlecs];
				for (int i = 0; i < maxlecs; i++)//for attendance
				{
					fin >> num;
					arr[i] = num;
					if (i + 1 != maxlecs)
					{
						fin >> junk;
					}
				}
				fin.ignore();//Registration(char Grad,int Marks1,int mlecs,int*arr)
				Registration* temp = new Registration(Grad, mark, maxlecs, arr);
				Dep->addregistrationsfromfiling(Couid, stdid, temp);
				delete[] Couid;
			}
			//Reading and Setting the Registration and WithDraw Period
			int val,val2;
			fin >> val; fin >> junk; fin >> val2; fin.ignore();
			Dep->SetRegistrationPeriod(val);
			Dep->SetWithdrawPeriod(val2);
			Uni->addDepartment(Dep);
			delete[] deptname;
		}
		return Uni;
	}
	else
	{
		cout << "Data can not be read , you may not have Saved the file" << endl;
	}
	return 0;
}
//To Save DATA in File which Includes Assigned Courses,Registrations and Passwords etc
void SaveDatainFile(University* Uni,const char* filename)//"UniversityDataBackup.txt"
{
	if (Uni != 0)
	{
		ofstream fout; fout.open(filename);
		if (fout.is_open())
		{
			Uni->WriteData(fout); 
			system("cls");
			cout << "Data Saved"<<endl;
		}
		else
		{
			cout << "There is No Data to Save" << endl;
		}
	}
	else
	{
		cout << "There is no data to Save(University ptr is pointed towards NULL)" << endl;
	}
	holdtillakeypressed();
}

int main()
{
	University* U=0;
	int flag = 0;
	while (flag == 0)
	{
		system("cls");
	    cout << "Enter -1 to exit to Exit the system " << endl;
		 cout << "Welcome to NeON Management System" << endl;
		cout << "Enter 0 to Read University Data From File (with Teachers Format) which Contains Only basic Information" << endl;
		cout << "Enter 1 to Read University Data with Own Format " << endl;
		cout << "Enter 2 to save University Data " << endl;
		int n = enterint("Enter Instruction");
		if (n == -1)
		{
			if (U != 0)
			{
				int a = enterint("Do you want to Save DATA , Enter 1 for Yes ");
				if (a == 1)
				{
					SaveDatainFile(U,"UniversityDataBackup.txt" );
				}
				delete U;
			}
			break;
		}
		
		if (n == 0)
		{
			U = ReadDatafromfile1("basedata.txt");
			if (U != 0)
			{
				U->Manual();
			}
			else
			{
				cout << "Data is Not readed successfully from File(with Teachers Format)" << endl;
			}
		}
		if (n == 1)
		{
			U = ReadDatafromfile2("UniversityDataBackup.txt");
			if (U != 0)
			{
				U->Manual();
			}
			else
			{
				cout << "Data is Not readed successfully from File(with Own Format)" << endl;
			}
		}
		if (n == 2)
		{
			SaveDatainFile(U, "UniversityDataBackup.txt");
		}
		
	}
}








