#ifndef MYACCOUNT_H

#define MYACCOUNT_H
#include<iostream>

class Account{
	public:
		void calculdate(){amount+=amount*initerestRate;}
		static double rate(){return initerestRate;}
		static void rate(double);

	private:
		static double initerestRate;
		static double initRate(){return 0.25;}
		std::string owner;
		double amount;
};

double Account::initerestRate=initRate();
void Account::rate(double newRate){
	initerestRate=newRate;
}
#endif
