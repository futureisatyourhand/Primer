#ifndef SALES_DATA_H
#include<iostream>
#include<string>
using std::string;
using std::ostream;
using std::istream;
struct Sales_data{
	Sales_data()=default;
    
	string isbn() const{return bookNo;}
	
    Sales_data(const string &book):bookNo(book){}

    Sales_data(const string &book,unsigned units,double revenue):bookNo(book),units_sold(units),revenue(revenue){}
	
	Sales_data(istream &is);    
	Sales_data & combine(const Sales_data &);
    
	double avg_price()const;
    
	
    	string bookNo;
    	unsigned units_sold=0;
    	double revenue=0.0;
};
Sales_data add(const Sales_data&,const Sales_data &);
ostream &print(ostream &,const Sales_data &);
istream &read(istream&,Sales_data&);
#endif
