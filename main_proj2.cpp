
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Investment.h"
#include <cstdio>
using namespace std;

int main() {
	char k;
	do {
		cout << "Please enter your investment plan in the following screen: \n" << endl;
		Investment newInvestment;
		newInvestment.GetUserInput();
		system("CLS"); //Removes faulty data from screen
		newInvestment.PrintOrderedInput(); //Prints organized user input
		newInvestment.CreateCharts(); //Creates balances for both cases with and without monthly deposits
		newInvestment.PrintBalance();
		cout << "Press any key if you would like to try again, press \'q\' if you would like to exit" << endl;
		cin >> k;
		system("CLS");
	} 	
	while (k != 'q' && k != 'Q');
	cout << "Program finished" << endl;

	return 0;
}
