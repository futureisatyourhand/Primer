
//12.2
#ifndef STRBLOBUPDATE_H
#define STRBLOBUPDATE_H
#include<iostream>
//#include<algorithm>

//#include<utility>

#include<vector>
//vector

#include <stdexcept>
//out_of_range

#include<memory>
//shared_ptr,make_shared
class StrBlobPtr;//12.19

class StrBlob{
    friend class StrBlobPtr;//12.19
    friend std::ostream &print(std::ostream &,const StrBlob &);
    public:
        typedef std::vector<std::string>::size_type size_type;
        StrBlob();
        
        StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){};
        //StrBlob str({"beijing","hangzhou","shanghai"});

        size_type size()const{return data->size();}
        bool empty()const{return data->empty();}

        void push_back(const std::string &t){data->push_back(t);}

        void pop_back();

        const std::string &front();
        const std::string &back();
    private:
        std::shared_ptr<std::vector<std::string>> data;
        void check(size_type i,const std::string &msg)const;

    public:
        //We can't define begin() or end() until we have defined StrBlobPtr
        StrBlobPtr begin(); //12.19
        StrBlobPtr end();//12.19
};

std::ostream &print(std::ostream &,const StrBlob &);

StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>>()){}

//StrBlob::StrBlob(std::initilizer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){}

void StrBlob::check(size_type i,const std::string &msg)const{
    if(i>=data->size())
        throw std::out_of_range(msg);
}

const std::string &StrBlob::front(){
    check(0,"front on empty StrBlob");
    return data->front();
}

const std::string &StrBlob::back(){
    check(0,"back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back(){
    check(0,"pop back on empty StrBlob");
    data->pop_back();
}

#endif
