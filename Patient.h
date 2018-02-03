#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Patient
{
public:
	//Constructors
	Patient();
	Patient(int, string);
	~Patient();

	//Public Attributes
	int id;
	string name;
	string medication; 
	float dose;
	float lasttaken;
	vector <string> PMed; /*for medication and dosage*/

	//Public Methods
	void AddDose();

protected:
};
