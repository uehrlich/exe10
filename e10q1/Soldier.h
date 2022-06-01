/********************************
Uri Ehrlich 208967976
Programming in C++
Exercise 10 question 1
The program runs  a class of soldiers
*********************************/


#pragma once
#include <iostream>
using namespace std;
class Soldier
{
public:
	Soldier() { id = 0; operations = 0; }
	Soldier(int i, int o, string f, string l) :id(i), operations(o), firstName(f), lastName(l) {};
	virtual ~Soldier() {};
	virtual bool medal() = 0;
	virtual bool isCombat() = 0;
	virtual void print() = 0;
	virtual string soldierType() = 0;
	virtual int getSoc() { return NULL; }
	virtual string getFname() = 0;
	virtual string getName() = 0;
	int oper() { return operations; }
protected:
	int id;
	int operations;
	string firstName;
	string lastName;

private:

};