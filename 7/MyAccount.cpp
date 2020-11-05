#include<iostream>
#include"MyAccount.h"

int main(int argv,char **argc){
	Account myaccount;
    std::cout<<myaccount.rate()<<std::endl;

	myaccount.rate(1000.12);
	std::cout<<myaccount.rate()<<std::endl;


	Account account2;
	std::cout<<"account2:"<<account2.rate()<<std::endl;
}
