#include<iostream>
#include<algorithm>

#include<utility>
using std::pair;
using std::make_pair;

#include<vector>
using std::vector;

#include<iterator>
#include<functional>
using namespace std::placeholders;//


//merge range
//method 1
class Interval{
    public:
        Interval(int first,int second):first(first),second(second){}
        void setStart(int first){this->first=first;}
        void setEnd(int second){this->second=second;}
        int getStart(){return first;}
        int getEnd(){return second;}
    private:
        int first,second;
};
static bool compare(Interval &a,Interval &b){
    return a.getStart()<b.getStart();
}
//[[1,3],[2,6],[8,10],[15,18]]
vector<Interval> merge(vector<Interval>&vec){
    //sort(vec.begin(),vec.end(),[](Interval &a,Interval &b){return a.getStart()<b.getStart();});
    sort(vec.begin(),vec.end(),bind(compare,_1,_2));
    //
    for(auto &v:vec)
        std::cout<<v.getStart()<<","<<v.getEnd()<<std::endl;
    //

    vector<Interval> res;
    size_t i=0,size=vec.size();
    Interval temp(vec[0].getStart(),vec[0].getEnd());

    while(i<size){
        temp.setStart(vec[i].getStart());
        temp.setEnd(vec[i].getEnd());
        while(i<size){
            if(i+1<size && vec[i+1].getStart()<=temp.getEnd()){
                if(vec[i+1].getEnd()>=temp.getEnd())
                    temp.setEnd(vec[i+1].getEnd());
                i++;
            }else{
                i++;
                break;
            }
        }
        res.push_back(temp);
    }
    return res;
}


//merge range
//method 2:
//utility pair,make_pair
//function sort,bind(using namespace std::placeholders::_1 or _2)
bool compare_bind(pair<int,int> &a,pair<int,int> &b){return a.first<b.first;}
vector<pair<int,int>> merge(vector<pair<int,int>> &vec){
    vector<pair<int,int>> res;
    sort(res.begin(),res.end(),bind(compare_bind,_1,_2));
    pair<int, int> temp({vec[0].first,vec[0].second});

    auto size=vec.size();
    auto i=0;
    while(i<size){
        temp={vec[i].first,vec[i].second};

        while(i<size){
            if(i+1<size && vec[i+1].first<=temp.second){
                if(vec[i+1].second>=temp.second)
                    temp.second=vec[i+1].second;
                ++i;
            }else{
                ++i;
                break;
            }
        }
        res.push_back(temp);
    }
    return res;
}

//str1 contains char of str2
std::string MyContains(std::string &str1,const std::string str2){
    std::string flag="true";
    vector<int> vec;
    int len=str1.size();
    for(auto i=0;i<len-1;++i){
        if(str1[i+1]==str1[i])
            vec.push_back(i+1);
    }

    for(auto i=0;i<vec.size();i++){
        int temp=vec[i]-i;
        //std::cout<<*str1.begin()<<" "<<temp<<std::endl;
        str1.erase(str1.begin()+temp);
    }
    for(auto i=0;i<str2.size();++i){

        auto num=find_if(str1.begin(),str1.end(),[i,str2](const char &a){return a==str2[i];});
        if(num==str1.end()){
            flag="false";
            break;
        }
    }
    return flag;
}

//unzip str, and sort ,print

int main(int argv,char **argc){
    //vector<Interval> vec;
    vector<pair<int,int>>vec;
    int a,b;
    while(std::cin>>a>>b){
        if(a<0)
            break;
        //vec.emplace_back(a,b);
        vec.push_back(make_pair(a,b));
    }
    //vector<Interval> res=merge(vec);
    //for(auto &val:res)
    //    std::cout<<"["<<val.getStart()<<","<<val.getEnd()<<"]"<<std::endl;
    
    vector<pair<int,int>> res=merge(vec);
    for(auto &v:res)
        std::cout<<"["<<v.first<<","<<v.second<<"]"<<std::endl;
    std::cout<<std::endl;

    std::string str1="BBDDCFFE",str2="LCEFB";
    std::cout<<MyContains(str1,str2)<<std::endl;
    return 0;
}
