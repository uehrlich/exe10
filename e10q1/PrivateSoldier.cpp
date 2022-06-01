/********************************
Uri Ehrlich 208967976
Programming in C++
Exercise 10 question 1
The program runs  a class of soldiers
*********************************/


#include"PrivateSoldier.h"

bool PrivateSoldier::medal()
{
	if (operations >= 10)
	{
		float sum = 0;
		for (int i = 0; i < operations; i++)
		{
			sum += grades[i];
		}
		if ((float)sum / operations > 95)
			return true;
		else
			return false;
	}
	return false;
}

void PrivateSoldier::print()
{
	cout << "private" << endl;
	cout << "ID: " << id << endl;
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	cout << "num operations: " << operations << endl;
	cout << "grades: ";
	vector<int>::iterator it2 = grades.begin();
	while (it2 != grades.end())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
}
PrivateSoldier::PrivateSoldier(const PrivateSoldier& p)
{
	for (int i = 0; i < p.grades.size(); i++)
	{
		grades[i] = p.grades[i];
	}
	this->id = p.id;
	this->operations = p.operations;
	this->firstName = p.firstName;
	this->lastName = p.lastName;
}