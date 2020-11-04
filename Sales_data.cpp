#include<iostream>
#include"Sales_data.h"
using std::istream;
using std::ostream;
//7.2
Sales_data::Sales_data(istream &is){
	read(is,*this);
}
Sales_data &Sales_data::combine(const Sales_data &sales){
	units_sold+=sales.units_sold;
	revenue+=sales.revenue;
	return *this;
}

Sales_data add(const Sales_data &sales1,const Sales_data &sales2){
	Sales_data sum=sales1;
	sum.combine(sales2);
	return sum;
}

istream &read(istream &is,Sales_data &sd){
	double price=0;
	is>>sd.bookNo>>sd.units_sold>>price;
	sd.revenue=price*sd.units_sold;	
	return is;
}

ostream &print(ostream &os,const Sales_data &items){
	os<<items.bookNo<<" "<<items.units_sold<<" "<<items.revenue;
	return os;
}

double Sales_data::avg_price() const{
	if(units_sold)
		return revenue/units_sold;
	return 0;
}

//7.4
class Person{
	private:
		string name;
		string address;
	public:
		Person(const string &name,const string &addr):name(name),address(addr){}
    	string getName()const{return name;}
		string getAddress()const{return address;}
};
int main(int argv,char **argc){
	Sales_data s1;
	print(std::cout,s1)<<std::endl;

	Sales_data s2("china 2020");
	print(std::cout,s2)<<std::endl;

	Sales_data s3("beijing",10,5.5);
	print(std::cout,s3)<<std::endl;

	Sales_data s4(std::cin);
	print(std::cout,s4)<<std::endl;

	return 0;
}
