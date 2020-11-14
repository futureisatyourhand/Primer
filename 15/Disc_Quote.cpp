#include<iostream>

//15.3
class Quote{
	private:
		std::string bookNo;
	protected:
		double price=0.0;
	public:
		Quote()=default;
		Quote(const std::string &bookNo,double sales_price):bookNo(bookNo),price(sales_price){}

		std::string isbn()const{return bookNo;}

		virtual double net_price(std::size_t n)const{return n*price;}////
		
		virtual ~Quote()=default;

		virtual void debug(){std::cout<<"Quote debug bookNo:"<<bookNo<<" #price "<<price<<std::endl;}//15.11
};
//15.3
double print_total(std::ostream &os,const Quote &item,size_t n){
	double ret=item.net_price(n);
	os<<"ISBN: "<<item.isbn()<<" # sold: "<<n<<" total due: "<<ret<<std::endl;
	return ret;
}

//15.5
class Bulk_quote:public Quote{
	private:
		std::size_t min_qty=0;
		double discount=0.0;
	public:
		Bulk_quote()=default;
		
		Bulk_quote(const std::string & book,double p,std::size_t qty,double disc):Quote(book,p),min_qty(qty),discount(disc){}
		
		double net_price(std::size_t) const override;/////
		
		//15.11
		void debug()override{Quote::debug();std::cout<<" bulk_quote minqty: "<<min_qty<<" discount "<<discount<<std::endl;}
};

double Bulk_quote::net_price(std::size_t n)const{
	if(n>=min_qty)
		return n*(1-discount)*price;
	else
		return n*price;
}


////////////15.15
class Disc_quote:public Quote{
	protected:
		std::size_t quantity=0;
		double discount=0.0;
	public:
		Disc_quote()=default;
		
		Disc_quote(const std::string &book,double price,std::size_t qty,double disc):Quote(book,price),quantity(qty),discount(disc){}

		double net_price(std::size_t)const=0;
};
////15.15
class Bulk:public Disc_quote{
	public:
		Bulk()=default;

		Bulk(const std::string &book,double price,std::size_t qty,double disc):Disc_quote(book,price,qty,disc){}

		double net_price(std::size_t n)const override{
			if(n>=quantity)
				return n*(1-discount)*price;
			else
				return n*price;
		}
};
int main(int argv,char **argc){
	Quote item("c++ primer",128.5);
	std::cout<<print_total(std::cout,item,10)<<std::endl;
	
	//15.6
	Bulk_quote bulk("effective",40,10,0.1);
	std::cout<<print_total(std::cout,bulk,20)<<std::endl;
	//15.6
	Quote &r=bulk;
	std::cout<<print_total(std::cout,r,100)<<std::endl;

	bulk.debug();//
	r.debug();//	
	item.debug();

	//15.15
	Bulk b("c++ primer 14.15",128,10,0.4);
	std::cout<<print_total(std::cout,b,1000)<<std::endl;
	return 0;
}
