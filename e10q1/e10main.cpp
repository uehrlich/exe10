/********************************
Uri Ehrlich 208967976
Programming in C++
Exercise 10 question 1
The program runs  a class of soldiers
*********************************/

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include "Soldier.h"
#include "PrivateSoldier.h"
#include "Commander.h"
#include "Officer.h"
using namespace std;

enum option {
	EXIT,	//	סיום התוכנית
	ADD_NEW_SOLDIER,	//	הוספת חייל חדש
	DESERVES_MEDAL,	//	הדפסת פרטי כל החיילים הזכאים לצל"ש
	HIGHEST_SOCIOMETRIC,	//הדפסת שם (משפחה ופרטי) של  החייל בעל ציון סוציומטרי מקסימלי 
	PRIVATE_MEDAL_COUNT,	//	הדפסת מספר החיילים הטירוניים הזכאים לצל"ש
	NONCOMBAT_COMMANDER,	//	הדפסת שמות (משפחה ופרטי) של המפקדים שאינם בקרבי
	SUPER_SOLDIER,   //הדפסת הודעה מתאימה, האם קיים חייל שהשתתף ביותר מ- 15  מבצעים צבאיים
	REMOVE_OFFICER,	//	מחיקת כל החיילים הקצינים שלא השתתפו כלל במבצע צבאי
};



void add(vector<Soldier*>& s) {

	cout << "choose a soldier\n";
	cout << "enter 1 to add a private\n";
	cout << "enter 2 to add a commander\n";
	cout << "enter 3 to add an officer\n";

	int num;
	cin >> num;
	while (num < 1 || num > 3)
	{ 
		cout << "choose a soldier\n";
		cout << "enter 1 to add a private\n";
		cout << "enter 2 to add a commander\n";
		cout << "enter 3 to add an officer\n";
		cin >> num;
	}
	cout << "enter id, first name, last name and number of operations\n";
	int id, ope;
	string first, last;
	cin >> id >> first >> last >> ope;
	int temp;
	if (ope)
		cout << "enter " << ope << " grades\n";
	vector<int> oper;
	for (int i = 0; i < ope; i++)
	{
		cin >> temp;
		oper.push_back(temp);
	}
	int combat = 2;
	if (num == 2)
	{
		cout << "enter 1 if the soldier is combat and 0 if not\n";
		cin >> combat;

		while (combat > 1 || combat < 0)
		{
			cout << "enter 1 if the soldier is combat and 0 if not\n";
			cin >> combat;
		}
	}
	int soc =0;
	if (num == 3)
	{
		cout << "enter the sociometric score\n";
		cin >> soc;
	}
	if (num == 1)
	{
		s.push_back(new PrivateSoldier(id, ope, first, last, oper));
		return;
	}
	if (num == 2)
	{
		s.push_back(new Commander(id, ope, first, last, oper, combat));
		return;
	}
	if (num == 3)
	{
		s.push_back(new Officer(id, ope, first, last, soc));
		return;
	}

}
void medal(vector<Soldier*> s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]->medal())
			s[i]->print();
	}

}
Soldier* mostSociometricScore(vector<Soldier*> s)
{
	vector<Soldier*>::iterator it = s.begin();
	int max = -1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]->soldierType() == "Officer")
		{
			((Officer*)s[i])->getSoc();
			if (s[i]->getSoc() > max)
			{
				max = s[i]->getSoc();
				it = s.begin() + i;
			}
		}
	}
	if (it == s.begin())
	{
		if (s[0]->soldierType() == "Officer")
		{
			return *it;
		}
		else
		{
			return NULL;
		}
	}
	return *it;
}

int main()
{
	vector<Soldier*> sol;
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER:add(sol);
			break;//הוספת חייל חדש						break;
		case DESERVES_MEDAL:medal(sol);  //הדפסת פרטי הזכאים לצל"ש
			break;
		case HIGHEST_SOCIOMETRIC: {   //הדפסת שם הקצין בעל ציון סוציומטרי גבוה ביותר 
			Soldier* s = mostSociometricScore(sol);
			cout << "Officer with the highest sociometric score: ";
			cout << s->getFname() << ' ' << s->getName() << endl;

			break;
		}
		case PRIVATE_MEDAL_COUNT: {  cout << "number of privates that received medals: "; ;
			int num = 0;
			for (int i = 0; i < sol.size(); i++)
			{
				if (sol[i]->medal() && sol[i]->soldierType() == "Private")
					num++;
			}
			cout << num << endl;//הדפסת מספר הזכאים לצל"ש בטירונים
			break;
		}
		case NONCOMBAT_COMMANDER: {cout << "list of noncombat commanders: "<<endl;
			//הדפסת רשימת(שם משפחה ופרטי) החיילים המפקדים שאינם בקרבי
			for (int i = 0; i < sol.size(); i++)
			{
				if (!sol[i]->isCombat() && sol[i]->soldierType() == "Commander")
					cout << sol[i]->getFname() << " " << sol[i]->getName() << endl;
			}
			break;
		}
		case SUPER_SOLDIER: {
			bool super = false;
			for (int i = 0; i < sol.size(); i++)
				if (sol[i]->oper() >= 15)
					super = true;
			//if (mostSociometricScore(sol)->oper() >= 15) // קיים חייל שהשתתף יובתר מ- 15 מבצעים צבאיים
			if(super)
				   cout << "there is at least one soldier that did more than 15 operations\n";

			else
				cout << "no soldier did more than 15 operations\n";

			break;
		}
		case REMOVE_OFFICER: {
			//מחיקה מהווקטור/רשימה של כל החיילם קצינים שאינם השתתפו כלל במבצעים צבאיים
			int size = sol.size();
			for (int i = 0; i < size; i++)
			{
				if (sol[i]->soldierType() == "Officer" && sol[i]->oper() == 0)
				{
					sol.erase(sol.begin() + i);
				}
			}
			size = sol.size();
			for (int i = 0; i < size; i++)
			{
				sol[i]->print();
				cout << endl;
			}
			//הדפסת כל הרשימה לאחר מחיקת האיברים
			break;
		}
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}


/**************************************************
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
1
enter id, first name, last name and number Of operations
111 aaa aaa 10
enter 10 grades
100 100 90 95 98 100 100 100 98 99
ID 111
first name: aaa
last name aaa
num operations: 10
grades: 100 100 90 95 98 100 100 100 98 99
enter 0-7
2
ID 111
first name: aaa
last name aaa
num operations: 10
grades: 100 100 90 95 98 100 100 100 98 99
enter 0-7
0
**************************************************/
