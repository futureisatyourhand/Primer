#include<iostream>

#include"StrBlobPtr.h"
//#include "StrBlob.h"
inline bool eq(const StrBlobPtr &lth,const StrBlobPtr &rth){
    auto l=lth.wptr.lock(),r=rth.wptr.lock();
    if(l==r)
        return (!r && lth.curr==rth.curr);
    else
        return false;
}
inline bool neq(const StrBlobPtr &lth,const StrBlobPtr &rth){
    return !eq(lth,rth);
}
int main(int argv,char **argc){
    StrBlob b({"beijing","chongqing","shanghai","beijing"});
    std::string str;
    for(auto i=b.begin();neq(i,b.end());i.incr())
        std::cout<<i.deref()<<std::endl;
    return 0;
}
