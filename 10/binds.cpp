#include<iostream>

#include<vector>
using std::vector;

#include<list>
using std::list;

#include<algorithm>
#include<functional>
using namespace std::placeholders;
//10.22
bool lens(const std::string &s,std::string::size_type sz){
    return s.size()<=sz;
}
int counts(vector<std::string> &vec,vector<std::string>::size_type sz){
    int cnt=count_if(vec.begin(),vec.end(),bind(lens,_1,sz));
    return cnt;
}

//10.24
bool check_size(const int &v,const std::string::size_type &s){
    return v>s;
}

vector<int>::iterator finds(vector<int> &vec,const std::string &s){
    auto wc=find_if(vec.begin(),vec.end(),bind(check_size,_1,s.size()));
    return wc;
}
int main(int argv,char **argc){
    //10.22
    vector<std::string> vec={"beijing","chongqing","shanghai","guangdong","jiangshu","a","ab","abc"};
    vector<std::string>::size_type sz=6;
    std::cout<<counts(vec,sz)<<std::endl;
    
    //10.24
    vector<int> vec_int={1,2,3,1,1212,34,45,6,56,67,100};
    vector<int>::iterator it=finds(vec_int,"beijing");
    std::cout<<*it<<std::endl;
    return 0;
}
