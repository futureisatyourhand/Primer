#include<iostream>
 
#include<vector>
using std::vector;

#include<list>
using std::list;

#include<deque>
using std::deque;
//9.4
bool search(vector<int>::iterator beg,vector<int>::iterator end,int val){

    while(beg!=end){
        if(*beg==val)
            return true;
        ++beg;
    }
    return false;
}

//9.6
vector<int>::iterator search2(vector<int>::iterator beg,vector<int>::iterator end,int val){

    while(beg!=end){
        if(*beg==val)
            return beg;
        ++beg;
    }
    return end;
}

//9.13
vector<double> get(list<int> &c){
    vector<double> vec(c.begin(),c.end());
    return vec;
}

vector<double> get(vector<int> &c){
    vector<double> vec(c.begin(),c.end());
    return vec;
}

//9.22
void insert922(){
    vector<int> vec={5,5,5,5,5};
    vector<int>::iterator iter=vec.begin(),mid=vec.begin()+vec.size()/2;
    int val=5;
    while(iter!=mid){
        auto diff=mid-iter;
        if(*iter==val){
            iter=vec.insert(iter,2*val);
            iter+=2;
            mid=--diff+iter;
        }
    
    }

    for(auto i:vec)
        std::cout<<i<<" ";
    std::cout<<std::endl;
}
int main(int argv,char **argc){
    //
    vector<int> vec={1,2,3,11,22,33,44,55,64,435,34234,231};
    std::cout<<"search bool:"<<search(vec.begin(),vec.end(),435)<<std::endl;

    //
    vector<int>::iterator it=search2(vec.begin(),vec.end(),435);
    std::cout<<"search iterator:"<<*it<<std::endl;
    
    //
    list<int> lst={1,2,3,4,5,6,7};
    vector<double> v=get(lst);
    vector<double> d=get(vec);
    for(auto &l:lst)
        std::cout<<l<<" ";
    std::cout<<std::endl;
    for(auto &dd:d)
        std::cout<<dd<<" ";
    std::cout<<std::endl;
    
    //9.14
    list<const char *>lst2={"lst1","lst2","lst3"};
    vector<std::string> str;
    str.assign(lst2.cbegin(),lst2.cend());
    for(auto &s:str)
        std::cout<<s<<" ";
    std::cout<<std::endl;
    
    //9.18
    //std::string strs;
    //deque<std::string> deq;
    //while(getline(std::cin,strs)){
    //    deq.push_back(strs);
    //    if(strs=="")
    //        break;
    //}
    //for(auto &dq:deq)
    //    std::cout<<dq<<" ";
    //std::cout<<std::endl;
    
    //9.19
    deque<int> odd,jishu;
    for(auto &v:vec)
        if(v%2==0)
            odd.push_back(v);
        else
            jishu.push_back(v);
    
    //9.22
    insert922();
    return 0;
}
