#include<iostream>

#include<vector>
using std::vector;

#include<list>
using std::list;

#include<algorithm>
//10.1
void countVector(vector<int> &vec,const int &val){
    int i;
    while(std::cin>>i){
        if(i<0)
            break;
        vec.push_back(i);
    }
    auto cnt=count(vec.begin(),vec.end(),val);
    std::cout<<"vector<int> count=val:"<<cnt<<std::endl;
}

//10.2
void countList(list<std::string> &lst,const std::string &val){
    std::string str;
    while(getline(std::cin,str)){
        if(str=="")
            break;
        lst.push_back(str);
    }
    std::cout<<"List<string> count=val:"<<count(lst.begin(),lst.end(),val)<<std::endl;
}

//10.3
void accumulateVector(vector<int> &vec){
    int sum=accumulate(vec.begin(),vec.end(),0);
    std::cout<<"accumulate vector<int>:"<<sum<<std::endl;
}

//10.11
bool isShorter(const std::string &s1,const std::string &s2){
    return s1.size()<s2.size();
}

//10.9
void elimDups(vector<std::string> &words){
    sort(words.begin(),words.end(),isShorter);
    auto end_unique=unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}

//10.13
bool isLonger(const std::string &s){
    return s.size()>=5;
}


vector<std::string>::iterator finds(vector<std::string> &s,vector<std::string>::size_type sz){
    auto wc=find_if(s.begin(),s.end(),[sz](const std::string a){return a.size()>=sz;});
    return wc;
}

//10.16
void bigger(vector<std::string> &words,vector<std::string>::size_type sz){
    elimDups(words);

    stable_sort(words.begin(),words.end(),
                [](const std::string &a,const std::string &b){
                        return a.size()<b.size();});

    auto wc=find_if(words.begin(),words.end(),[sz](const std::string &a){return a.size()>=sz;});

    auto cnt=words.end()-wc;

    //std::cout<<cnt<<" "<<make_plural(cnt,"word","s")<<" of length "<<sz<<"  or longer "<<std::endl;

    for_each(wc,words.end(),[](const std::string &s){std::cout<<s<<" ";});
    std::cout<<std::endl;

}

//10.20
int larger(vector<std::string>&vec,vector<std::string>::size_type sz){
    int cnt=count_if(vec.begin(),vec.end(),[sz](const std::string &s)->bool{return s.size()>sz;});
    return cnt;
}

//10.21
void dec(int value){
    int i=value;
    auto d=[&i]()->bool{
        if(i>0){
            --i;
            return false;
        }else
            return true;
    };
    for(auto f=0;f<value+1;f++)
        std::cout<<d()<<" ";
   std::cout<<std::endl;
}
int main(int argv,char **argc){
    //10.1
    //vector<int> vec;
    //countVector(vec,10);

    //10.2
    //list<std::string> lst;
    //countList(lst,"beijing");
    
    //10.3
    //accumulateVector(vec);
    
    vector<std::string> vv={"abc","beijing","chongqing","shanghai","chongqing","beijing","beijing"};
    //elimDups(vv);
    partition(vv.begin(),vv.end(),isLonger);
    for(auto &v:vv)
        std::cout<<v<<"  ";
    std::cout<<std::endl;
    
    vector<std::string>::size_type sz=3;
    vector<std::string>::iterator it=finds(vv,sz);
    std::cout<<*it<<std::endl;
   
    //10.14
    auto sums=[](const int &a,const int &b){return a+b;};
    std::cout<<"[](const int &a,const int &b){return a+b;}=="<<sums(10,20)<<std::endl;
   
    //10.15
    int a=1000;
    auto sums2=[a](const int &b){return a+b;};
    std::cout<<"[a](const int &b){return a+b;}=="<<sums2(1)<<std::endl;
    
    bigger(vv,sz);
    
    std::cout<<"count_if:"<<larger(vv,sz)<<std::endl;
    
    dec(4);
    return 0;
}
