#include <iostream>
#include <iomanip>
#include <sstream>
#include "Investment.h"
#include <stdlib.h>

using namespace std;

void Investment::SetInitialInv(double initInv) {
	initialInv = initInv;
}
void Investment::SetMonthlyDep(double mDep) {
	monthlyDep = mDep;
}
void Investment::SetInterest(double inter) {
	interest = inter;
}
void Investment::SetNumYears(int years) {
	numYears = years;
}

//This function modifies the list added as a parameter and includes balance objects
void Investment::ListBalance(double monthDep, vector<Balance>& list) {
	Balance currBal;
	double tempBeginInv;
	double tempEndBal;
	double tempEndInt;
	double totalYearEndInt = 0;
	unsigned int i;
	unsigned int j;

	tempBeginInv = initialInv;

	//Interest is calculated and the values for each year are modified and stored
	for (i = 0; i < numYears; ++i) {
		currBal.SetYearBeginBalance(tempBeginInv);
		for (j = 0; j < 12; ++j) {
			tempEndInt = (tempBeginInv + monthDep)* ((interest / 100) / 12);
			totalYearEndInt = totalYearEndInt + tempEndInt;
			tempEndBal = tempBeginInv + monthDep + tempEndInt;
			tempBeginInv = tempEndBal;
		}
		currBal.SetYearEndInterest(totalYearEndInt);
		currBal.SetYearEndBalance(tempEndBal);
		list.push_back(currBal);
		totalYearEndInt = 0;
	}
}

//Simple function that creates two lists containing all data required for the final output
void Investment::CreateCharts() {
	ListBalance(monthlyDep, investList);
	ListBalance(0, investZeroDepList);
}

//Helper function, combines double data and $ symbol for better output only
string Investment::AddSymbol(char s, double x) {
	ostringstream ss;
	ss << " " << s << fixed << setprecision(2) << x;
	return ss.str();
}



void Investment::PrintList(vector<Balance> listToPrint) {
	unsigned int i;

	cout << setfill('=') << setw(68) << "" << endl;
	cout << setfill(' ') << "|" << setw(3) << "" << "Year" << setw(8) << "" << "Year end balance" << setw(8) << "" << "Year End Earned Interest" << setw(4) << "|" << endl;
	cout << setfill('-') << setw(68) << "" << setfill(' ') << endl;
	for (i = 0; i < listToPrint.size(); ++i) {
		cout << "|" << setw(6) << i + 1 << setw(20) << AddSymbol('$', listToPrint.at(i).GetYearEndBalance()) << setw(28) << AddSymbol('$', listToPrint.at(i).GetYearEndInterest()) << setw(13) << "|" << endl;
	}
	cout << setfill('-') << setw(68) << "" << setfill(' ') << endl;
}



void Investment::PrintBalance() {

	cout << setfill('-') << setw(68) << "" << setfill(' ') << endl;
	cout << "|" << setw(5) << "" << "Balance and Interest Without Additional Monthly Deposits" << setw(6) << "|" << endl;
	PrintList(investZeroDepList);
	cout << endl;
	cout << setfill('-') << setw(68) << "" << setfill(' ') << endl;
	cout << "|" << setw(6) << "" << "Balance and Interest With Additional Monthly Deposits " << setw(7) << "|" << endl;
	PrintList(investList);
}

//Both functions verify user input, the input is stracted as a string
//after validation of each element the program either returns a value or ask for new input
double Investment::VerifyInputDouble() {

	string s;
	unsigned i;
	int numDots;
	bool valid = false;
	while (!valid) {
		numDots = 0;
		getline(cin, s);
		for (i = 0; i < s.length(); ++i) {
			if (!isdigit(s.at(i)) && s.at(i) != '.') {
				cout << "Wrong input. Please enter a positive number:" << endl;
				valid = false;
				break;
			}
			else {
				valid = true;
			}
			if (s.at(i) == '.') { //Count number of dots, allowing only 1 decimal point
				++numDots;
				if (numDots > 1) {
					valid = false;
					cout << "Wrong input, please try again:" << endl;
					break;
				}
				else {
					valid = true;
				}
			}
		}
	}
	return atof(s.c_str());
}

int Investment::VerifyInputInt() {

	string s;
	unsigned i;
	bool valid = false;
	while (!valid) {
		getline(cin, s);
		for (i = 0; i < s.length(); ++i) {
			if (!isdigit(s.at(i))) {
				cout << "Wrong input. Please enter a positive number of years:" << endl;
				valid = false;
				break;
			}
			else {
				valid = true;
			}
		}

	}
	string::size_type st;
	return stoi(s,&st);
}


//This function asks user input and calls validation input functions 
void Investment::GetUserInput() {
	cout << setfill('-') << setw(40) << "" << endl;
	cout << setw(14) << "" << " Data Input " << setw(14) << "" << endl;
	cout << setw(40) << "" << endl;
	cout << "Initial Investment amount: $";
	initialInv = VerifyInputDouble();
	cout << "Monthly Deposit: $";
	monthlyDep = VerifyInputDouble();
	cout <<  "Annual Interest: %";
	interest = VerifyInputDouble();
	cout << "Number of Years: ";
	numYears = VerifyInputInt();
	cout << setw(40) << "" << endl;
	cout << setfill(' ') << endl; //Returns default empty space
	cout << "Press any key to continue..." << endl;
	cin >> key;
}


//Only for display purposes, this function reorganizes user input and displays it
void Investment::PrintOrderedInput() {
	cout << setfill('-') << setw(44) << "" << endl;
	cout << setw(16) << "" << " Data Input " << setw(16) << "" << endl;
	cout << setw(44) << "" << endl;
	cout << setw(27) << left << "Initial Investment amount: " << setw(17) << right << AddSymbol('$', initialInv) << endl;
	cout << setw(27) << left << "Monthly Deposit: " << setw(17) << right << AddSymbol('$', monthlyDep) << endl;
	cout << setw(27) << left << "Annual Interest: " << setw(17) << right << AddSymbol('$', interest) << endl;
	cout << setw(27) << left << "Number of Years: " << setw(17) << right << " " + to_string(numYears) << endl;
	cout << setw(44) << "" << endl;
	cout << setfill(' ') << endl; //Returns default empty space
}



double Investment::GetInitialInv() const {
	return initialInv;
}
double Investment::GetMonthlyDep() const {
	return monthlyDep;
}
double Investment::GetInterest() const {
	return interest;
}
int Investment::GetNumYears() const {
	return numYears;
}




