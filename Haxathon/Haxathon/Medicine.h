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
	vector<string> History;
	string Expiration;
	void ListDetails();
	bool flag;
	private:

};
#endif