#pragma once
#include"Employee.h"
class Course;
//Diamond Problem is already Solved by making Employee virtually inherited from Person
//No need to inherit Teacher Virtually
class Teacher : public Employee   
{
	Course** listofcourses;
	int currentcourses;
	int coursecap;
public:
	Teacher();//Default Constructor
	Teacher(int Empnum, const char* name);//Parameterized Constructor
	//Overriding of Virtual Function from Person Class 
	void Print();
	//To Display the Courses a Teacher is Assigned
	void DisplayCoursesAssigned();
	//To return the index of Courses which is Assigned to Teacher
	int FindIndexofCourse(char*name);
	int FindIndexofCoursebyid(char*name);
	//To Assign a Course to Teacher
	void assigncoursetoteaacher(Course*obj);
	//For a Teacher to Perform His Evaluations /Duties
	void TeacherManual();
	//To view the Courses Assigned to a Teacher
	void viewcoursestoteacher();
	//To grow the array of Courses assigned to Teacher
	void extendlistofcourses();
	//To check if the course is Assigned to teacher 
	bool checkifCourseAssigned(char*ID);
	//The Below Two Functions are used for Filing
	void WriteData1(ofstream&fout);
	void WriteData2(ofstream&fout);
	//Return the no. of Courses a Teacher is Assigned 
	int getAssignedcourses();
	//To UN-assign a Course from Teacher
	void unassignacoursefromteacher(char* Cid);
	//To Return the type of Entity (Teacher in this case)
	const char* Purpose() const throw();
	virtual ~Teacher();
};