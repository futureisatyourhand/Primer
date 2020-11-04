#include<iostream>
extern const int a;
int main(int argv,char **argc){
    std::cout<<a<<std::endl;
    double yuan=42.12;
    const double &pi=yuan;
    const double *const change=&pi;
    std::cout<<yuan<<" "<<pi<<" "<<*change<<std::endl;
    
    yuan=1001.111;
    std::cout<<yuan<<" "<<pi<<" "<<*change<<std::endl;
    
    return 0;
}
