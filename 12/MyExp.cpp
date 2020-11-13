#include<iostream>
//12.23
void concate(){
    std::string str1,str2;
    while(std::cin>>str1>>str2){
        std::string *strs=new std::string[50];
        *strs=str1+str2;
        std::cout<<*strs<<std::endl;
        delete [] strs;
    }
}

//12.24
void DynamicChar(){
    std::string strs;
    while(std::cin>>strs){
        char *p=new char[strs.size()];
        for(auto i=0;i<strs.size();++i)
            p[i]=strs[i];
        delete []p;
    }
}

//12.26
#include<memory>
//std::allocator;
void MyAllocate(){
    std::string str;
    std::allocator<std::string> allc;
    auto p=allc.allocate(15);
    auto q=p;
    while(std::cin>>str && q!=p+15)
        allc.construct(q++,str);
    const size_t size=q-p;
    for(auto i=0;i!=size;++i)
        std::cout<<p[i]<<std::endl;

    while(q!=p)
        allc.destroy(--q);
    allc.deallocate(p,15);
}
int main(int argv,char **argc){
    MyAllocate();   
    return 0;
}
