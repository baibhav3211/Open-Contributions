/*	Project Title: Prime Number Validation
*	Description: This program validates if a number is PRIME or not.
*	Programmer(s): OmiCreativeDev - Salome Shunamon
*	Date: October 25, 2022
*/

#include <iostream>

using namespace std;

int main()
{


		int userInput;
		int check;
		int div = 0;
		int prime = 0;

		cout << "Enter a postive whole number: ";
		cin >> userInput;


		while (!cin || userInput <= 0 || userInput != (int)userInput) {
			cout << "Invalid Input. Enter ONLY a positive whole number!\n";
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "Enter a postive whole number: ";
			cin >> userInput;
		}

		if (userInput == 1) {
			cout << "Number is not Prime.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Press Enter to re-reun the program.\n";
			cin.get();
			main();
		}

		div = userInput / 2;

		for (check = 2; check <= div; check++)
		{
			if (userInput % check == 0)
			{
				cout << "Number is not Prime.\n";
				prime = 1;

				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Press Enter to re-reun the program.\n";
				cin.get();
				main();

			}
		}

		if (userInput == 2 || prime == 0)
			cout << "Number is Prime.\n";

			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Press Enter to re-reun the program.\n";
			cin.get();
			main();

	}

// w00t w00t!!! 