#include<iostream>
using namespace std;
#include<memory>
//13.13
struct X{
	public:
		X(){std::cout<<"X()"<<std::endl;}
		X(shared_ptr<int>q,int i):p(q),i(i){std::cout<<"gouzao"<<std::endl;}
		X(const X&){std::cout<<"X(const X&)"<<std::endl;}
		X &operator=(const X&x);
		~X(){std::cout<<"delete x"<<std::endl;}
	private:
		shared_ptr<int>p;
		int i;
};
X &X::operator=(const X&x){
	p=make_shared<int>(*(x.p));
	i=x.i;
	std::cout<<"operator="<<std::endl;
	return *this;
}


//13.14
class numbered{
	public:
		numbered(){mysn=num++;}
		int mysn=0;
		numbered(const numbered &x){mysn=num++;}
	private:
		static int num;
};
int numbered::num=0;
void f(numbered s){
	std::cout<<s.mysn<<std::endl;
}

//13.18
class Employee{
	friend void get_info(const Employee &);
	public:
		Employee():id(num++){}
		Employee(const Employee &e){
			name=e.name;
			id=num++;
		}
		Employee(const std::string &s):name(s),id(num++){}
		Employee &operator=(Employee &rhs){
			name=rhs.name;
			return *this;
		}
	private:
		std::string name;
		unsigned id;
		static unsigned num;
};
unsigned Employee::num=0;

void get_info(const Employee &e){
	std::cout<<e.name<<" "<<e.id<<std::endl;
}

int main(int argv,char **argc){
	X x1;
	auto q=make_shared<int>(42);
	X x2(q,3);
	x1=x2;
	X x3(x2);

	numbered a,b=a,c=b;
	f(a);
	f(b);
	f(c);

	Employee e1("beijing");//0
	Employee e2=e1;//1
	Employee e3;//2
	e3=e1;//4
	get_info(e1);
	get_info(e2);
	get_info(e3);
	return 0;
}
