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

bool Shelf::RemoveMed(int Position, string Name)
{
	if (Contents.size() == 0)
	{
		return 0;
	}
	if (Contents.size() < Position)
	{
		return 0;
	}
	if (Contents[Position].flag)
	{
		Contents[Position].flag = 0;
		Contents[Position].HistoryN.push_back(Name);
		return 1;
	}
	return 0;
}

bool Shelf::ReturnMed(int Position, int Quant)
{
	if (Contents.size() == 0)
	{
		return 0;
	}
	if (Contents.size() < Position)
	{
		return 0;
	}
	if (Contents[Position].flag)
	{
		if(Quant > Contents[Position].CurrentQ)
		{
			cout << "Error, Returning more quanity than taken out" << endl;
			return 0;
		}
		else
		{
			Contents[Position].flag = 1;
			Contents[Position].HistoryQ.push_back((Quant - Contents[Position].CurrentQ));
			Contents[Position].CurrentQ = Quant;
			return 1;
		}
	}
	else
	{
		cout << "Position not empty" << endl;
		return 0;
	}
}

bool Shelf::MedHistory(int Position)
{
	if (Contents.size() == 0)
	{
		return 0;
	}
	if (Contents.size() < Position)
	{
		return 0;
	}
	Contents[Position].ShowHistory();
	return 1;
}

bool Shelf::RestockMed(int Position, string name)
{
	if (Contents.size() == 0)
	{
		return 0;
	}
	if (Contents.size() < Position)
	{
		return 0;
	}
	if (Contents[Position].CurrentQ == Contents[Position].Quantity)
	{
		cout << "No need to restock" << endl;
		return 1;
	}
	else
	{
		Contents[Position].HistoryN.push_back(name);
		Contents[Position].Restock();
		return 1;
	}
}