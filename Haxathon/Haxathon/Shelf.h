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
	void RemoveMed(int position, string Name);
	bool ReturnMed(int position, int amount);
	void MedHistory(int position);
	void RestockMed(int position, string Name);
private:

};
#endif