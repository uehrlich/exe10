#include "Soldier.h"
#include <iostream>
using namespace std;
 

void Soldier::print()
{
	cout << "ID: " << ID << endl
		<< "first name: " << fname << endl
		<< "last name: " << lname << endl
		<< "num operation: " << numOfOp << endl;
}

int Soldier::getID()
{
	return ID;
}
string Soldier::getfname()
{
	return fname;
}
string Soldier::getlname()
{
	return lname;
}
int Soldier::getNumOfOp()
{
	return numOfOp;
}