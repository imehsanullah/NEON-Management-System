#pragma once
#include"Person.h"
class Registration;
class Student :virtual public Person
{
protected:
	Registration** listofRegistrations; 
	int ID;
	int currentregs;
public:
	//Default Constructor
	Student(); 
	//Parameterized Constructor's
	Student(int ID1, const char* name);
	Student(int ID1, const char* name, Registration** list,int cRegs);
	Student(Student& obj); //Copy Consttructor , Passed Argument Not constant by intent
	
	//Overriding of Virtual Fuction in Person 
	void Print();
	//To Add the Registration to Student Class
	void addregistration(Registration*obj);
	//Show the Courses a Student is Registered in
	void ShowRegstoStudent();
	//To check if the Student is Registered in the Course  
	int checkifcourseregistered(char* Cname);
	int checkifcourseregisteredbyid(char* Cname);
	//When a Student is UN-Registered from a Course
	void removeregfromstuedent(int ind);
	//For a Student to view his Records
	void StudentManual();
	//Return current no. of Courses a Student is Registered in
	int getcurrentregs();
	//Shows the Grades and Marks of Entire Courses Student is enrolled in
	void seeAcademicstatus();
	//To Return the listofRegs of Student when Student and TA are converted into Eachother
	Registration** getlistofRegistrations();
	//Used for Filing
	void WriteData1(ofstream& fout );
	//Returns the Student ID
	int getstudentid();
	//To See the Entire Attendance
	void viewentireAttendance();
	//To Return the type of Entity (Student in this Case) 
	 const char* Purpose()const throw();
	//Unary Operator
	bool operator !();
	bool operator ==(char* Cname);
	void withdrawfromCourse(int ind);
	
	virtual ~Student();
};

