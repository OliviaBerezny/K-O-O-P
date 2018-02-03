#include <iostream>
#include <vector>
#include <string>

using namespace std;
int Hash(int);

int main()
{
	vector<int> Hashed = { 16450, 23269, 20919, 4723 };
	vector<string> Names = { "Dr Pepper", "Dr Whom'st've", "Dr Patel", "Dr Slav" };
	int ID;
	bool PassFlag = 0;
	int Pass;
	string Signed;
	int UserSwitch = 1;

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

	cout << "Login Successful." << endl;
	Signed = Names[ID];
	cout << "Logged in as : " << Signed << endl;
	
	while (UserSwitch != 0) /*infinite loop, must break to stop*/
	{
		printf("Select option:\n"); 	/*switch statement for menu*/
		printf("1 - Show History\n");	/*print menu*/
		printf("2 - Put Medicine\n");	/*print menu*/
		printf("3 - Take Medicine\n");	/*print menu*/
		printf("0 - Close\n");			/*print menu*/

		cin >> UserSwitch;				/*user's input for menu*/

		switch (UserSwitch)				/*switch statement*/
		{
		case 1: /*Show History*/
			cout << "" << endl;
			break;

		case 2: /*Put*/
			cout << "" << endl;
			break;

		case 3: /*Place*/
			cout << "" << endl;
			break;

		case 0: /*Close*/
			cout << "Logging Out..." << endl;
			break;
		}
	}

	return 0;
}



int Hash(int Password)
{
	int hashed;
	hashed = (Password ^ 17) % 25051;
	return hashed;
}
