#ifndef Medicine_H
#define Medicine_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Medicine
{
public:
	Medicine();
	Medicine(string name, int quantity, string date);
	string name;
	int Quantity;
	int CurrentQ;
	vector<string> HistoryN;
	vector<int> HistoryQ;
	string Expiration;
	bool flag;
	void ShowHistory();
	void Restock();
	void ListDetails();
	private:

};
#endif