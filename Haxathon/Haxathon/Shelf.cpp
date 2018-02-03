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
	for(int i = 0; i < Contents.size(); i++)
	{
		cout << "Position " << i << ": ";
		Contents[i].ListDetails();
		if (Contents[i].flag == 0)
		{
			cout << " Currently out";
		}
		cout << endl;
	}
}

void Shelf::RemoveMed(int Position, string Name)
{
	Contents[Position].flag = 0;
	Contents[Position].HistoryN.push_back(Name);
}

void Shelf::ReturnMed(int Position, int Quant)
{
	Contents[Position].flag = 1;
	Contents[Position].HistoryQ.push_back((Quant - Contents[Position].CurrentQ));
	Contents[Position].CurrentQ = Quant;
	
}

void Shelf::MedHistory(int Position)
{
	Contents[Position].ShowHistory();
}

void Shelf::RestockMed(int Position, string name)
{
	Contents[Position].HistoryN.push_back(name);
	Contents[Position].Restock();
}