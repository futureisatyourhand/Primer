#include<iostream>
#include<vector>
#include<memory>
#include "Blob.h"

int main(int argv,char **argc){
	Blob<int> sq({0,1,2,3,4,5,6,7});
	sq.push_back(10000);
	for(size_t i=0;i!=sq.size();++i)
		std::cout<<sq[i]<<" ";
	std::cout<<std::endl;
	return 0;
}
