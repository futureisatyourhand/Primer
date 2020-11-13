#include<iostream>
#include "HasPtr.h"

#include<memory>

#include<vector>

int main(int argv,char **argc){
    HasPtr *p=new HasPtr;
    
    std::shared_ptr<HasPtr> p2=std::make_shared<HasPtr>();

    HasPtr item(*p);
    
    std::vector<HasPtr>vec;
    vec.push_back(*p2);

    delete p;
    
    HasPtr has("hello word");
    HasPtr have=has;
    print(std::cout,have);
    return 0;
}
