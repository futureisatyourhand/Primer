#ifndef STRBLOBPTR_H

#define STRBLOBPTR_H

#include<iostream>
#include<memory>
//std::shared_ptr;
//std::weak_ptr;
#include"StrBlobUpdate.h"
#include<vector>
//std::vector;

#include<stdexcept>
//std::out_of_range;
//std::runtime_error;
//class StrBlobPtr;//for friend 
//class StrBlob{
//    friend class StrBlobPtr;

//};

class StrBlobPtr{
    friend bool eq(const StrBlobPtr &lth,const StrBlobPtr &rth);
    public:
        StrBlobPtr():curr(0){}

        StrBlobPtr(StrBlob &a,size_t sz=0):wptr(a.data),curr(sz){}

        std::string &deref()const;

        StrBlobPtr &incr();
    private:
        std::shared_ptr<std::vector<std::string>> check(size_t,const std::string &)const;
        
        std::weak_ptr<std::vector<std::string>> wptr;//
        
        size_t curr;//current position
};
bool eq(const StrBlobPtr &lth,const StrBlobPtr &rth);
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i,const std::string &msg) const{
    auto ret=wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound strBlobPtr");
    if(i>=ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string &StrBlobPtr::deref()const{
    auto p=check(curr,"str blob ptr dereference past end");
    
    return (*p)[curr];//(*p) is the vector
}
StrBlobPtr &StrBlobPtr::incr(){
    check(curr,"increment past end of str blob ptr");
    ++curr;
    return *this;
}

//12.19
//define StrBlob::begin() and end()
inline StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}
inline StrBlobPtr StrBlob::end(){
    auto ret=StrBlobPtr(*this,data->size());
    return ret;
}
#endif
