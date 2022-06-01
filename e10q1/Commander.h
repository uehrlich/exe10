/********************************
Uri Ehrlich 208967976
Programming in C++
Exercise 10 question 1
The program runs  a class of soldiers
*********************************/


#pragma once
#include <iostream>
#include "PrivateSoldier.h"
#include<vector>
using namespace std;
class Commander : public PrivateSoldier
{
public:
	Commander(int i, int o, string f, string l, vector<int> n, bool c) : PrivateSoldier(i, o, f, l, n), combat(c) {}
	~Commander() {}
	bool medal();
	void print();
	string soldierType() { return "Commander"; }
	int getSoc() { throw "ERROR: this function is just for officer soldier"; }
	bool isCombat() { return combat; }
private:
	bool combat;
};