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
	Expiration = Date;
	flag = 1;
}

void Medicine::ListDetails()
{
	cout << name << ", " << Quantity << " mg, " << Expiration << endl;
}