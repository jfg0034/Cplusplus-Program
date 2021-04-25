#include "Balance.h"

//Mutators
void Balance::SetYearBeginBalance(double beginBal) {
	yearBeginBal = beginBal;
}
void Balance::SetYearEndBalance(double endBal) {
	yearEndBal = endBal;
}
void Balance::SetYearEndInterest(double endInt) {
	yearEndInterest = endInt;
}

//Accesors
double Balance::GetYearBeginBalance() const {
	return yearBeginBal;
}
double Balance::GetYearEndBalance() const {
	return yearEndBal;
}
double Balance::GetYearEndInterest() const {
	return yearEndInterest;
}
