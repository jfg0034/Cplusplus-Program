#ifndef INVESTMENT_H
#define INVESTMENT_H
#include <string>

#include <vector>
#include "Balance.h"

class Investment {
	public:

		void SetInitialInv(double initInv);
		void SetMonthlyDep(double mDep);
		void SetInterest(double inter);
		void SetNumYears(int years);

		void PrintList(std::vector<Balance> listToPrint); //Helper function to reduce repeating code
		void PrintBalance(); //Invokes PrintList twice
		void ListBalance(double monthDep, std::vector<Balance>& list); //Helper function to create a list if montly deposits were made or not
		void CreateCharts(); //Invokes ListBalance twice to create two different vectors
		
		void GetUserInput(); //Ask user to input values for their projected investment
		void PrintOrderedInput(); //Reprints user's input orderly in case they enetered previous wrong input

		//User input verification functions:
		double VerifyInputDouble(); 
		int VerifyInputInt();
		
		std::string AddSymbol(char s, double x); //Helper function for better output, adds a symbol in front of a fixed double

		double GetInitialInv() const;
		double GetMonthlyDep() const;
		double GetInterest() const;
		int GetNumYears() const;	

	private:
		double initialInv = 0;
		double monthlyDep = 0;
		double interest = 0;
		int numYears = 0;
		std::string key;

		std::vector <Balance> investZeroDepList; //List containing balances if 0 monthly deposits were made
		std::vector <Balance> investList; //List containing monthly deposits
};


#endif
