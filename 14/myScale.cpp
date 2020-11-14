#include<iostream>
//14.2
class Sale{
	friend std::istream &operator>>(std::istream &is,Sale &s);
	friend std::ostream &operator <<(std::ostream &os,const Sale &s);

	public:
		Sale():bookNo(""){}
		
		Sale(const std::string &s,unsigned units_sold,double units_price):bookNo(s),units_sold(units_sold),units_price(units_price){}

		Sale operator+(const Sale &s);
		
		Sale &operator+=(const Sale &s);
	private:
		std::string bookNo;
		unsigned units_sold=0;
		double units_price=0;
};
std::istream &operator>>(std::istream &is,Sale &s);
std::ostream &operator<<(std::ostream &os,const Sale &s);

std::istream &operator>>(std::istream &is,Sale &s){
	is>>s.bookNo>>s.units_sold>>s.units_price;
	if(is)//14.9
		return is;
	else
		s=Sale();
}

std::ostream &operator<<(std::ostream &os,const Sale &s){
	os<<s.bookNo<<" "<<s.units_sold<<" "<<s.units_price<<std::endl;
	return os;
}

Sale Sale::operator+(const Sale &s){
	if(bookNo==s.bookNo){
		Sale ss;
		ss.bookNo=bookNo;
		ss.units_price=s.units_price;
		ss.units_sold=units_sold+s.units_sold;
		return ss;
	}else{
		std::cout<<"error"<<std::endl;
		return *this;
	}
}

Sale &Sale::operator+=(const Sale &s){
	if(bookNo==s.bookNo){
		units_sold+=s.units_sold;
		return *this;
	}else{
		std::cout<<"not add"<<std::endl;
		return *this;
	}
}

int main(int argv,char **argc){
	Sale s1;
	Sale s2("primer",10,128.5);
	std::cout<<s2<<std::endl;//ostream &operator<<(ostream &os,const Sale &);
	
	s1=s2;
	std::cout<<s1<<std::endl;
	
	std::cout<<s1+s2<<std::endl;//Sale operator+(const Sale &)
	
	s1+=s2;//Sale &operator+=(const Sale &)
	std::cout<<s1<<std::endl;

	std::cin>>s1;//istream &operator>>(istream &s,Sale &)
	std::cout<<s1;
	
	std::cout<<s1+s2<<std::endl;
	return 0;
}

