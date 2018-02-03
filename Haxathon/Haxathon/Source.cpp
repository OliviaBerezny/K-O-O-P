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
	int TempInt;
	int TempInt2;
	int TempInt3;
	int ID;
	bool PassFlag;
	bool RetFlag;
	int Pass;
	string Signed;
	int UserSwitch;
	int HSwitch;
	int SeeIDH;
	bool error;
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
					do {
						cout << "Enter ID \n";

						cin >> ID;
						if (cin.fail())
						{
							ID = 000;
							error = 1;
							cin.clear();
							cin.ignore(80, '\n');
						}
						else
						{
							error = 0;
						};
						cout << "Enter Password \n";
						cin >> Pass;
						if (cin.fail())
						{
							Pass = 000;
							error = 1;
							cin.clear();
							cin.ignore(80, '\n');
						}
						else
						{
							error = 0;
						};
						if (error == 1)
						{
							cout << "Error with details, try again \n";
						}
					} while (error == 1);


					Pass = Hash(Pass);
					if (ID > Hashed.size() - 1)
					{
						cout << "Error with details, try again \n" << endl;
						break;
					}

					if (Hashed[ID] != Pass)
					{
						cout << "Error with details, try again \n" << endl;
					}

					else
					{
						PassFlag = 1;
						break;
					}
					break;
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
			if (ID != 0)
			{
				printf("\nSelect option:\n"); 	/*switch statement for menu*/
				printf("1 - Show History\n");	/*print menu*/
				printf("2 - Put Medicine\n");	/*print menu*/
				printf("3 - Take Medicine\n");
				printf("4 - View contents of shelf\n");/*print menu*/
				printf("0 - Close\n");
			}
			else
			{
				printf("\n Admin \nSelect option:\n"); 	/*switch statement for menu*/
				printf("1 - Show History\n");	/*print menu*/
				printf("2 - Put Medicine\n");	/*print menu*/
				printf("3 - Take Medicine\n");
				printf("4 - View contents of shelf\n");/*print menu*/
				printf("5 - View Medicine History\n");
				printf("6 - Restock Medicine\n");
				printf("0 - Close\n");
			}
			/*print menu*/

			cin >> UserSwitch;				/*user's input for menu*/

			switch (UserSwitch)				/*switch statement*/
			{
			case 1: /*Show History*/
			{
				if (ID == 0)
				{
					printf("\nSelect option:\n");		/*switch statement for menu*/
					printf("1 - Show All History\n");	/*print menu*/
					printf("2 - Show Own History\n");	/*print menu*/

					cin >> HSwitch;		/*user's input for menu*/

					switch (HSwitch)	/*switch statement*/
					{
					case 1:
					{
						cout << "Displaying All History\n" << endl;

						cout << "Enter ID to view History: " << endl;
						cin >> SeeIDH;

						cout << "Displaying " << Names[SeeIDH] << "'s History" << endl;

						for (int i = 0; i < History[SeeIDH].size(); i++)
						{
							cout << History[SeeIDH][i] << " at: ";
							TempTime = HTimes[SeeIDH][i];
							printf("%s", ctime(&TempTime));
							cout << endl;
						}

						time(&TempTime);
						HTimes[ID].push_back(TempTime);
						History[ID].push_back("Checked Users History");
						break;
					}

					case 2:
					{
						cout << "Displaying Own History\n" << endl;

						for (int i = 0; i < History[ID].size(); i++)
						{
							cout << History[ID][i] << " at: ";
							TempTime = HTimes[ID][i];
							printf("%s", ctime(&TempTime));
							cout << endl;
						}
						time(&TempTime);
						HTimes[ID].push_back(TempTime);
						History[ID].push_back("Checked own History");
						break;
					}
					}
				}

				else
				{
					cout << "Displaying Own History" << endl;

					for (int i = 0; i < History[ID].size(); i++)
					{
						cout << History[ID][i] << " at: ";
						TempTime = HTimes[ID][i];
						printf("%s", ctime(&TempTime));
						cout << endl;
					}

					time(&TempTime);
					HTimes[ID].push_back(TempTime);
					History[ID].push_back("Checked own History");

				}

				break;
			}
			case 2: /*Put*/
			{
				cout << "Press 1 for returning, 2 for new" << endl;
				cin >> TempInt;
				switch (TempInt)
				{
				case 1:
				{
					cout << "Enter Shelf ID" << endl;
					cin >> TempInt;
					cout << "Enter Medicine Position" << endl;
					cin >> TempInt2;
					cout << "Enter New Quantity" << endl;
					cin >> TempInt3;
					switch (TempInt)
					{
					case 01:
						RetFlag = S1.ReturnMed(TempInt2, TempInt3);
						History[ID].push_back("Returned contents to shelf 01");
						break;
					case 02:
						RetFlag = S2.ReturnMed(TempInt2, TempInt3);
						History[ID].push_back("Returned contents to shelf 02");
						break;
					case 11:
						RetFlag = S3.ReturnMed(TempInt2, TempInt3);
						History[ID].push_back("Returned contents to shelf 11");
						break;
					case 12:
						RetFlag = S4.ReturnMed(TempInt2, TempInt3);
						History[ID].push_back("Returned contents to shelf 12");
						break;
					default:
						break;
					}
					time(&TempTime);
					HTimes[ID].push_back(TempTime);
					break;
				}
				case 2:
				{
					cout << "Enter Shelf ID" << endl;
					cin >> TempInt;
					cout << "Enter Name, Amount (mg) and Expiration date (DD/MM/YYYY)" << endl;
					cin >> MedName >> TempInt2 >> MedDate;
					Medicines.push_back(Medicine(MedName, TempInt2, MedDate));


					switch (TempInt)
					{
					case 01:
						S1.AddMedicine(Medicines[(Medicines.size() - 1)]);
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
				}
			}
			break;
			}
			case 3: /*Take*/
			{
				cout << "Enter Shelf ID" << endl;
				cin >> TempInt;
				cout << "Enter Medicine Position" << endl;
				cin >> TempInt2;
				switch (TempInt)
				{
				case 01:
					S1.RemoveMed(TempInt2, Names[ID]);
					History[ID].push_back("Removed contents of shelf 01");
					break;
				case 02:
					S2.RemoveMed(TempInt2, Names[ID]);
					History[ID].push_back("Removed contents of shelf 02");
					break;
				case 11:
					S3.RemoveMed(TempInt2, Names[ID]);
					History[ID].push_back("Removed contents of shelf 11");
					break;
				case 12:
					S4.RemoveMed(TempInt2, Names[ID]);
					History[ID].push_back("Removed contents of shelf 12");
					break;
				default:
					break;
				}
				time(&TempTime);
				HTimes[ID].push_back(TempTime);
				break;
			}	                   
			case 4: // View contents
			{
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
				time(&TempTime);
				HTimes[ID].push_back(TempTime);
				break;
			}

			case 5: // Medicine History
			{
				if(ID != 0)
				{
					break;
				}
				cout << "Enter Shelf ID" << endl;
				cin >> TempInt;
				cout << "Enter Medicine Position" << endl;
				cin >> TempInt2;
				switch (TempInt)
				{
				case 01:
					S1.MedHistory(TempInt2);
					break;
				case 02:
					S2.MedHistory(TempInt2);
					break;
				case 11:
					S3.MedHistory(TempInt2);
					break;
				case 12:
					S4.MedHistory(TempInt2);
					break;
				default:
					break;
				}
				break;
			}
			
			case 6: // Restock
			{
				if (ID != 0)
				{
					break;
				} 
				cout << "Enter Shelf ID" << endl;
				cin >> TempInt;
				cout << "Enter Medicine Position" << endl;
				cin >> TempInt2;
				switch (TempInt)
				{
				case 01:
					S1.RestockMed(TempInt2, Names[ID]);
					break;
				case 02:
					S2.RestockMed(TempInt2, Names[ID]);
					break;
				case 11:
					S3.RestockMed(TempInt2, Names[ID]);
					break;
				case 12:
					S4.RestockMed(TempInt2, Names[ID]);
					break;
				default:
					break;
				}
				break;
			}
			case 0: /*Close*/
			{
				time(&TempTime);
				HTimes[ID].push_back(TempTime);
				History[ID].push_back("Logged Out");
				cout << "Logging Out... \n \n \n" << endl;
				break;
			}
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
