#include <iostream>
#include <vector>
#include <string>

#include "Shelf.h"

Shelf::Shelf(int Input)
{
	id = Input;
};

void Shelf::AddMedicine(Medicine name)
{
	Contents.push_back(name);
};

void Shelf::ListContents()
{
	for(int i =0; i < Contents.size(); i++)
	{
		cout << "Position " << i << ": ";
		Contents[i].ListDetails();
	}
}