#include<iostream>
#include<vector>
using std::vector;

#include<algorithm>

class Foo{
	friend void print(const Foo &);
	public:
		Foo();
		Foo(vector<int> &a);
		Foo(const Foo&);

		Foo& operator=(const Foo &);

		Foo(Foo &&) noexcept;
	
		Foo &operator=(Foo &&) noexcept;

		Foo sorted()const &;

		Foo sorted() &&;
	private:
		vector<int>data;
};
void print(const Foo &);

Foo::Foo(){
	vector<int>data1(10,0);
	data=data1;
}
Foo::Foo(vector<int> &a){
	data=a;
}

Foo::Foo(const Foo &f){
	data=f.data;
}
Foo &Foo::operator=(const Foo &f){
	data=f.data;
	return *this;
}

Foo::Foo(Foo &&f)noexcept{
	data=std::move(f.data);
}

Foo &Foo::operator=(Foo &&f)noexcept{
	data=std::move(f.data);
	return *this;
}
Foo Foo::sorted()const &{
	Foo ret(*this);
	std::cout<<&ret<<std::endl;
	std::sort(ret.data.begin(),ret.data.end(),[](const int &a,const int &b){return a<b;});//
	print(ret);
	//return ret.sorted();//
	return ret;
}

Foo Foo::sorted()&&{
	std::sort(data.begin(),data.end(),[](int &a,int &b){return a<b;});
	std::cout<<"0"<<std::endl;
	return *this;
}
void print(const Foo &f){
	for(auto c:f.data)
		std::cout<<c<<" ";
	std::cout<<std::endl;
}

int main(int argv,char **argc){
	vector<int> vec{1,3,4,2,6,3,7,4,0};
	Foo f1;
	Foo f2(vec);
	print(f1);
	print(f2);
	f1=std::move(f2);
	print(f1);
	print(f2);
	Foo f3(vec);
	print(f2.sorted());
	print(f3);
	return 0;
}
