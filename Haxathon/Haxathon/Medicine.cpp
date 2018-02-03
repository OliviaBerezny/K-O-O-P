#include <iostream>
#include <vector>
#include <string>

#include "Medicine.h"

using namespace std;

Medicine::Medicine()
{

};

Medicine::Medicine(string Name, int Amount, string Date)
{
	name = Name;
	Quantity = Amount;
	CurrentQ = Amount;
	Expiration = Date;
	flag = 1;
}

void Medicine::ListDetails()
{
	cout << name << ", " << CurrentQ << " mg, " << Expiration;
}

void Medicine::ShowHistory()
{
	int tempint;
	for (int i = 0; i < HistoryN.size(); i++)
	{
		cout << HistoryN[i];
		if(HistoryQ[i] < 0)
		{
			cout << " used ";
			tempint = -(HistoryQ[i]);
			cout << tempint << " mg";
		}
		else
		{
			cout << " restocked with " << HistoryQ[i] << endl;
		}
	}
}

void Medicine::Restock()
{
	int tempint;
	tempint = Quantity - CurrentQ;
	HistoryQ.push_back(tempint);
}