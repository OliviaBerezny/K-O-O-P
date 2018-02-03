#include <iostream>
#include <vector>
#include <string>


#include <time.h>
#include "Room.h"
#include "Shelf.h"
#include "Medicine.h"
using namespace std;
int Hash(int);

void main()
{
	vector<int> Hashed = { 16450, 23269, 20919, 4723 };
	vector<string> Names = { "Dr Pepper", "Dr Whom'st've", "Dr Patel", "Dr Slav" };
	vector<vector<string> > History(4);
	vector<vector<time_t> > HTimes(4);
	vector<Medicine> Medicines;
	time_t TempTime;
	string MedName;
	string MedDate;
	int MedCount = 0;
	int TempInt;
	int TempInt2;
	int ID;
	bool PassFlag;
	int Pass;
	string Signed;
	int UserSwitch;
	Shelf S1(01);
	Shelf S2(02);
	Shelf S3(11);
	Shelf S4(12);
	Room G1;
	Room G2;

	while (1)
	{
		PassFlag = 0;
		while (PassFlag == 0)
		{
			while (1)
			{
				cout << "Enter ID \n";
				cin >> ID;
				cout << "Enter Password \n";
				cin >> Pass;
				Pass = Hash(Pass);

				if (ID > Hashed.size())
				{
					cout << "ID Or Password Incorrect" << endl;
					break;
				}

				if (Hashed[ID] != Pass)
				{
					cout << "ID Or Password Incorrect" << endl;
				}

				else
				{
					PassFlag = 1;
					break;
				}
			}
		}

		cout << "\nLogin Successful." << endl;
		Signed = Names[ID];
		cout << "Logged in as : " << Signed << endl;
		UserSwitch = 1;
		time(&TempTime);
		HTimes[ID].push_back(TempTime);
		History[ID].push_back("Logged in");
		while (UserSwitch != 0) /*infinite loop, must break to stop*/
		{
			printf("\nSelect option:\n"); 	/*switch statement for menu*/
			printf("1 - Show History\n");	/*print menu*/
			printf("2 - Put Medicine\n");	/*print menu*/
			printf("3 - Take Medicine\n");
			printf("4 - View contents of shelf\n");/*print menu*/
			printf("0 - Close\n");			/*print menu*/

			cin >> UserSwitch;				/*user's input for menu*/

			switch (UserSwitch)				/*switch statement*/
			{
			case 1: /*Show History*/
				cout << "Displaying " << Signed << "'s History" << endl;
				for (int i = 0; i < History[ID].size(); i++)
				{
					cout << History[ID][i] << " at: ";
					TempTime = HTimes[ID][i];
					printf("%s", ctime(&TempTime));
					cout << endl;
				}
				time(&TempTime);
				HTimes[ID].push_back(TempTime);
				History[ID].push_back("Checked History");
				break;

			case 2: /*Put*/
				cout << "Enter Shelf ID" << endl;
				cin >> TempInt;
				cout << "Enter Name, Amount (mg) and Expiration date (DD/MM/YYYY)" << endl;
				cin >> MedName >> TempInt2 >> MedDate;
				Medicines.push_back(Medicine(MedName, TempInt2, MedDate));
				

				switch(TempInt)
				{case 01:
					S1.AddMedicine(Medicines[(Medicines.size() -1)]);
					History[ID].push_back("Added to shelf 01");
					break;
				case 02:
					S2.AddMedicine(Medicines[(Medicines.size() - 1)]);
					History[ID].push_back("Added to shelf 02");
					break;
				case 11:
					S3.AddMedicine(Medicines[(Medicines.size() - 1)]);
					History[ID].push_back("Added to shelf 11");
					break;
				case 12:
					S4.AddMedicine(Medicines[(Medicines.size() - 1)]);
					History[ID].push_back("Added to shelf 12");
					break;
				default:
					break;
				}
				time(&TempTime);
				HTimes[ID].push_back(TempTime);
				
				break;

			case 3: /*Take*/
				cout << "Enter Shelf ID" << endl;
				break;

			case 4: // View contents
				cout << "Enter Shelf ID" << endl;
				cin >> TempInt;
				switch (TempInt)
				{
				case 01:
					S1.ListContents();
					History[ID].push_back("Viewed contents of shelf 01");
					break;
				case 02:
					S2.ListContents();
					History[ID].push_back("Viewed contents of shelf 02");
					break;
				case 11:
					S3.ListContents();
					History[ID].push_back("Viewed contents of shelf 11");
					break;
				case 12:
					S4.ListContents();
					History[ID].push_back("Viewed contents of shelf 12");
					break;
				default:
					break;
				}
				break;

			case 0: /*Close*/
				time(&TempTime);
				HTimes[ID].push_back(TempTime);
				History[ID].push_back("Logged Out");
				cout << "Logging Out... \n \n \n" << endl;
				break;
			}
		}
	}
}



int Hash(int Password)
{
	int hashed;
	hashed = (Password ^ 17) % 25051;
	return hashed;
}
