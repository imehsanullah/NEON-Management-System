#ifndef HELPER_H
#define HELPER_H
#include<iostream>
#include<windows.h>
#include<fstream>
#include<conio.h>
#include <sstream>
using namespace std;

//To move on Console
inline void gotoxy(int x, int y)
{
	COORD c;         /* Using column number as x-coordinate and row number as y-coordinate*/
	c.X = y;
	c.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//To Stop the Execution till a key is pressed
inline void holdtillakeypressed()
{
	cout << "Press any key to move forward"<<endl;
	_getch();
	system("cls");
}
//The below two Functions are to Take input in array
inline char* entersinglename(const char* name)
{
	cout << "Enter full name of  " << name << endl;
	char* temp = new char[30];
	cin.getline(temp, 30);
	return temp;
}
inline char* entersinglename2(const char* name)
{
	cout  << name << endl;
	char* temp = new char[30];
	cin.getline(temp, 30);
	return temp;
}

//The Below two Functions are to take Integer Inputs from user Ensuring the 
//Execution of Program does not Stop If the USer Enters character in Integer Variable
inline int enterint(const char* name)
{
	if(name!=0)
	cout << name<<endl;
	
	bool bad = false;
	int a;
	do {
		cin >> a;
		bad = cin.fail();
		if (bad)
			cout << "Only Integer Input allowed" << endl;
		cin.clear();
		cin.ignore(10, '\n');
	} while (bad);
	return a;
}
inline int enterint2(const char* name,const char* n)
{
	if (name != 0)
		cout << name << endl;

	bool bad = false;
	int a;
	do {
		cin >> a;
		bad = cin.fail();
		if (bad)
		{
			if (n != 0)
				cout << n<<endl;
			else
			    cout << "Only Integer Input allowed" << endl;
		}
		cin.clear();
		cin.ignore(10, '\n');
	} while (bad);
	return a;
}

//Some Functions too Help me Department class
inline bool ifAttendanceright(int num)
{
	if (num == 0 || num == 1)
		return false;
	return true;
}
inline bool ifGraderight(char atd)
{
	if (atd == 'A' || atd == 'B' || atd == 'C' || atd == 'D' || atd == 'F')
		return false;
	return true;
}

//Template Funtion and 2-D Growing of Array
template<class Type>
inline void grow(Type** &arr, int size,int& Maxsize)
{
	try 
	{
		if (arr != 0)
		{
			cout << "GROW called";
			Type** temp = new Type * [size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}
			delete [] arr;
			Maxsize = size +10;
			arr = new Type * [Maxsize];
			
			for (int i = 0; i < size; i++)
			{
				arr[i] = temp[i];
			}
			delete[]temp;
		}
		else
		{
			throw "Passed Array In Grow function is pointed towards NULL";
		}
	}
	catch (const char* t)
	{
		cout << t << endl;;
	}
	catch (...)
	{
	
	}
}
//Template Funtion and 2-D Shrinking of Array
template<class Type>
inline void shrink(Type**& arr, int size, int newsize)
{
	try
	{
		if (newsize > size)
			throw "The New size is more than Previos Size";
		if (newsize < 0)
			throw "The New Size is Negative So ";
		Type** temp = new Type*[newsize];
		for (int i = 0; i < newsize; i++)
		{
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = new Type * [newsize];
		for (int i = 0; i < newsize; i++)
		{
			 arr[i]= temp[i] ;
		}
		delete[]temp;
		delete temp;
	}
	catch (const char* t)
	{
		cout << t;
	}
}

//Template class like the vector class
template <class Type>
class List {
	Type** arr;
	int size; int Maxsize;
public:
	List(int Max=5)
	{
		arr = new Type * [Max];
		size = 0;
		Maxsize = Max;
	}
	void extendarr()
	{
		Type** temp = new Type*[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = new Type * [size * 2];
		Maxsize = size * 2;
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
		delete[]temp;
	}
	void Pushback(Type*obj)
	{
		if (size == Maxsize)
		{
			/*extendarr();*/
			grow(arr, size, Maxsize);
		}
		arr[size++] = obj;
	}
	int getsize()
	{
		return size;
	}
	Type* operator [](int ind)
	{
		if (ind >= size ||ind < 0)
		{
			return 0;
		}
		else
		{
			return arr[ind];
		}
	}
	bool operator !()
	{
		return (size < 5);
	}
	~List()
	{
		    cout << "~List() Called" << endl;
			for (int i = 0; i < size; i++)
			{
					delete arr[i];
			}
			delete[]arr;
	}
};

//Exception Classes
class PasswordMatched :public exception
{
public:
	PasswordMatched()
	{

	}
	const char* what() const throw () {
		return " Password is Matched ";
	}
};
class GoBack :public exception
{
public:
	GoBack()
	{

	}
	const char* what() const throw () 
	{
		return "Going Back" ;
	}
};




#endif