#include <iostream>
#include <string>
#include "Patient.h"

using namespace std;


Patient::Patient()
{

}

Patient::Patient(int Pid, string Pname)
{
	id = Pid;
	name = Pname;
}

void Patient::AddDose()
{
	cout << "Input Medication: ";
	cin >> medication;
	cout << "Input Dose: ";
	cin >> dose;
	cout << "Input when last taken: ";
	cin >> lasttaken;
	
}
