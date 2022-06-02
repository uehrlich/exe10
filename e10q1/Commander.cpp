/********************************
Uri Ehrlich 208967976
Programming in C++
Exercise 10 question 1
The program runs  a class of soldiers
*********************************/

//**********************************************************************************************************//
#include"Commander.h"

bool Commander::medal()
{
	if (operations >= 7 && isCombat() == true)
	{
		float sum = 0;
		for (int i = 0; i < operations; i++)
		{
			sum += grades[i];
		}
		if ((float)sum / operations > 90)
			return true;
		else
			return false;
	}
	else
		return false;
}
void Commander::print()
{
	vector<int>::iterator it2 = PrivateSoldier::grades.begin();
	cout << "commander" << endl;
	cout << "ID: " << id << endl;
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	cout << "num operations: " << operations << endl;
	cout << "grades: ";
	while (it2 != grades.end())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
	cout << "combat : ";
	this->combat == true ? cout << "yes" : cout << "no";
	cout << endl;
}
