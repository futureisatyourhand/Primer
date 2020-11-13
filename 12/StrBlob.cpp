#include<iostream>
#include "StrBlob.h"
std::ostream &print(std::ostream &os,const StrBlob &str){
    for(auto c:*(str.data))
        os<<c<<" ";
    os<<std::endl;
    return os;
}
int main(int argv,char **argc){
    StrBlob str({"beijing","chongqing","shanghai","hangzhou"});
    print(std::cout,str);

    str.push_back("taiwan");
    print(std::cout,str);
    
    std::cout<<str.front()<<std::endl;
    std::cout<<str.back()<<std::endl;
    std::cout<<str.size()<<std::endl;
    return 0;
}

