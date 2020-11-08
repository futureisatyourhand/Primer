#include<iostream>
#include<vector>
using std::vector;

#include<functional>

#include<algorithm>

using namespace std::placeholders;
#include<list>
using std::list;

#include<iterator>
#include <fstream>

//10.34
void rprint(vector<int> &vec){
    for(auto it=vec.rbegin();it!=vec.rend();++it)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
}

//10.35
void rlist(vector<int> &vec,list<int> &lst){
    copy(vec.begin(),vec.end(),front_inserter(lst));
    for(auto &ls:lst)
        std::cout<<ls<<" ";
    std::cout<<std::endl;
}

//10.37
void rclist(){
    vector<int> vec1={20,1,3,7,4,10,24,3,0,5};
    list<int> li;
    sort(vec1.begin(),vec1.end());
    for(auto c:vec1)
        std::cout<<c<<" ";

    std::cout<<std::endl;
    auto w1=find(vec1.begin(),vec1.end(),3);
    auto w2=find(vec1.rbegin(),vec1.rend(),7);
    copy(w1,w2.base(),front_inserter(li));
    for(auto c:li)
        std::cout<<c<<" ";
    std::cout<<std::endl;
}

int main(int argv,char **argc){
    //10.34
    vector<int> vec={1,2,3,4,5,6,7,8,9};
    rprint(vec);

    //10.35
    list<int> lst;
    rlist(vec,lst);

    rclist();
    return 0;
}
