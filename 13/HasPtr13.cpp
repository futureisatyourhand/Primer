#include<iostream>
#include<vector>
using std::vector;
#include<memory>
#include<algorithm>
//13.30
class HasPtr{
	friend std::ostream &print(std::ostream &os,const HasPtr &h);
	friend void swap(HasPtr &lhs,HasPtr &rhs);//13.30
	friend bool operator<(HasPtr &p1,HasPtr &p2);//13.31
	
	friend std::string &out(const HasPtr &p);
	public:
		HasPtr(const std::string &s=std::string()):ps(new std::string(s)),i(0){}

		HasPtr(const HasPtr &ptr);
		
		HasPtr &operator=(const HasPtr &pt);

		~HasPtr(){delete ps;}
			
	private:
		std::string *ps;
		int i;
};
std::ostream &print(std::ostream &os,const HasPtr &h);

inline void swap(HasPtr &lhs,HasPtr &rhs);

HasPtr::HasPtr(const HasPtr &ptr):ps(new std::string(*(ptr.ps))),i(ptr.i){}

bool operator<(HasPtr &p1,HasPtr &p2);

std::string &out(const HasPtr &p){
	return *p.ps;
}

HasPtr &HasPtr::operator=(const HasPtr &pt){
	ps=new std::string(*pt.ps);
	i=pt.i;
	return *this;
}

std::ostream &print(std::ostream &os,const HasPtr &h){
	os<<*h.ps<<" "<<h.i<<std::endl;
	return os;
}
inline void swap(HasPtr &lhs,HasPtr &rhs){
	std::swap(lhs.ps,rhs.ps);
	std::cout<<"ps already copy"<<std::endl;
	std::swap(lhs.i,rhs.i);
	std::cout<<"i already copy"<<std::endl;
}

bool operator <(HasPtr &p1,HasPtr &p2){
	return (*p1.ps).size()<(*p2.ps).size();
}


int main(int argv,char **argc){
	HasPtr has("beijing");
	HasPtr have=has;
	print(std::cout,have);
	HasPtr p("hello world");
	swap(have,p);//13.30
	print(std::cout,have);
	print(std::cout,p);

	
	vector<HasPtr> vec;
	std::string str;
	while(getline(std::cin,str)){
		if(str=="")
			break;
		vec.push_back(*new HasPtr(str));
	}
	
	//13.31
	std::sort(vec.begin(),vec.end());

	for(auto i:vec)
		std::cout<<out(i)<<std::endl;
	return 0;
}
