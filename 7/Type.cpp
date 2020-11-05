#include<iostream>
typedef std::string Type;
Type initVal();
class Exerices{
	public:
		typedef double Type;
		Type setVal(Type);
		Type initVal();
	private:
		int val;
};

Exerices::Type Exerices::setVal(Type param){
	val=param+initVal();
	return val;
}

Exerices::Type Exerices::initVal(){
	Type strs=567;
	return strs;
}
int main(int argv, char**argc){
	Exerices ex;
	std::cout<<ex.setVal(123)<<std::endl;
	return 0;
}
