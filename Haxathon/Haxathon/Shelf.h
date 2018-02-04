#ifndef Shelf_H
#define Shelf_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "Medicine.h"

using namespace std;

class Shelf
{
public:
	Shelf();
	Shelf(int id);
	int id;
	vector <Medicine> Contents;
	float MaxStorage;
	void AddMedicine(Medicine);
	void ListContents();
	bool RemoveMed(int position, string Name);
	bool ReturnMed(int position, int amount);
	bool MedHistory(int position);
	bool RestockMed(int position, string Name);
private:

};
#endif