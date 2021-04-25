#ifndef BALANCE_H
#define BALANCE_H

class Balance {
	public:
		void SetYearBeginBalance(double beginBal);
		void SetYearEndBalance(double endBal);
		void SetYearEndInterest(double endInt);

		double GetYearBeginBalance() const;
		double GetYearEndBalance() const;
		double GetYearEndInterest() const;

	private:
		double yearBeginBal = 0;
		double yearEndBal = 0;
		double yearEndInterest = 0;

};



#endif

