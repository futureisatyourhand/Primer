#include<iostream>
#include"MyScreen.h"
//7.27
int main(int argv,char **argc){
	MyScreen myscreen(5,5,'X');
	myscreen.move(4,0).set('#').display(std::cout);
	std::cout<<std::endl;

	myscreen.display(std::cout);
	std::cout<<std::endl;
	return 0;
}
