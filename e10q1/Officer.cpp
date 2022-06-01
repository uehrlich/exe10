/********************************
Uri Ehrlich 208967976
Programming in C++
Exercise 10 question 1
The program runs  a class of soldiers
*********************************/


#include"Officer.h"
bool Officer::medal()
{
	if (operations > 2 && sociometric >= 92)
		return true;
	return false;
}

void Officer::print()
{
	cout << "officer" << endl;
	cout << "ID: " << id << endl;
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	cout << "num operations: " << operations << endl;
	cout << "sociometric score: " << sociometric << endl;

}