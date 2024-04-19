#pragma once
#include"TA.h"
class Registration;
class Course
{
	TA* Ta;
	Registration** listofRegistrations;
	char* CourseID;
	char* Coursename;
	int currentRegs;
	int maxregs;
	static int totalcourses; //Static Variable
public:
	Course(int=10);//Default Constructor
	Course(const char*ID,const char* name, int = 10);//Parameterized Constructor
	//To Set a TA in Course
	void SetTA(TA* obj);
	//To Unset a TA and Change it back to Student
	TA* UnSetTA();
	//To return the Course ID
	char* getcourseid();
	//To return the Course Name
	char* getcoursename();
	//To add a Registration in the Course
	void addregistration(Registration* obj);
	//Below two Funcs are to check if a Student is Registered in the Course
	int checkifstudentregistered(char* Sname);
	int checkifstudentregisteredbyid(int S);
	//To check if the Course has same TA
	bool checkifTAsame(int id);
	//To check if a Course is assigned a TA
	bool checkifTAexists();
	//To return the total Number of Courses offered in University
	static int gettotalcourses(); //Static Function
	//For the TA to Perform his Evaluation
	void TAmanualinCourse();
	//To Un-register a Course for a Student
	void removeregfromcourse(int ind);
	//To Show the Students Enrolled in a course
	void Showregstocourse();
	//For a Teacher To perform his Duties and Evaluations (Called From Teacher Class)
	void CourseManual();
	void Print();
	//To extend the Students Enrolled in Course
	void extendlistofRegistrations();
	//To see the Marks,Grades of Students in Course
	void viewAcademicStatus();
	//Returns the number of Students Enrolled in Course
	int getnoofRegs();
	//Two Functions are for Filing
	void WriteData1(ofstream& fout);
	void WriteData2(ofstream & fout);
	~Course();
};