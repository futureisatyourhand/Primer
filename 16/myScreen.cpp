#include<iostream>
#include<utility>
#include<memory>
#include<vector>
#include<list>
using namespace std;

template<typename T>class Screen{
	friend istream &operator>> (istream &is,Screen<T> &s);
	friend ostream &operator <<(ostream &os,const Screen <T> &s);
public:
	Screen()=default;
private:
	T height;
	T width;
};


//template<typename T>
//istream &operator>>(istream &is,Screen<T> &s);
//template<typename T>
//ostream &operator<<(ostream &os,const Screen<T> &s);

template<typename T>
istream &operator>>(istream &is,Screen<T> &s){
	is>>s.height>>s.width;
	if(!is)
		s=Screen<T>();
	
	return is;
}

template<typename T>
ostream &operator<<(ostream &os,const Screen<T> &s){
	os<<s.height<<" "<<s.width<<" ";
	return os;
}

int main(int argv, char **argc){
	Screen<double>s1;
	cin>>s1;
	cout<<s1;
	return 0;
}
