#include<iostream>

#include<vector>
using std::vector;

#include<list>
using std::list;

#include<deque>
using std::deque;

#include<forward_list>
using std::forward_list;
//9.27
void del_even(){
    forward_list<int> lst={1,2,3,4,5,6,7,8,9};
    auto prev=lst.before_begin();
    auto curr=lst.begin();
    while(curr!=lst.end()){
        if(*curr%2)
            curr=lst.erase_after(prev);
        else{
            prev=curr;
            ++curr;
        }
    }

    for(auto it=lst.begin();it!=lst.end();++it)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
}

//9.28
void insert_list(forward_list<std::string> &slst,const std::string &str1,const std::string &str2){
    auto prev=slst.before_begin();
    auto curr=slst.begin(),ends=slst.end();
    while(curr!=ends){
        if(*curr==str1){
            //curr=slst.erase_after(prev);
            curr=slst.insert_after(curr,str2);
            return;
        }else
            
            ++curr;
    }
    if(curr==ends)
        slst.insert_after(curr,str1);
}

int main(int argv,char **argc){
    vector<int> vec={1,2,3,4,5,6,7,8,9};
    std::cout<<"vector at:"<<vec.at(4)<<std::endl;
    std::cout<<"vector []:"<<vec[4]<<std::endl;
    std::cout<<"vector front:"<<vec.front()<<std::endl;
    std::cout<<"vector begin:"<<*vec.begin()<<std::endl;
    
    //9.27
    del_even();
    
    
    //9.28
    forward_list<std::string> lst={"beijing","chongqing","hangzhou","shanghai","guangdong"};
    insert_list(lst,"hangzhou","fujian");
    for(auto &ls:lst)
        std::cout<<ls<<"  ";
    std::cout<<std::endl;
    return 0;
}
