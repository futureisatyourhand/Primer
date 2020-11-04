#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
#include<string>
using std::string;
#include<vector>
using std::vector;
//#include<initializer__list>
using std::initializer_list;
using std::ostringstream;
#include<cassert>
//6.27/
//sum(initializer_list<int>a={1,2,3,4,5,6,7,8,9,10})
//count(a.begin(),a.end())
int count(initializer_list<int>::iterator begin,initializer_list<int>::iterator end){
    int s=0;
    while(begin!=end)
        s+=*begin++;
    return s;
}

//6.28
struct ErrCode{
    ErrCode(int i):num(i){}
    int msg(){
        return num;
    }
   int num;
};
void error_msg(ErrCode e,initializer_list<string> il){
    cout<<e.msg()<<":";
    for(const auto &elem:il)
        cout<<elem<<"    ";
    cout<<endl;
}

char &get_val(string &str,string::size_type ix){
    return str[ix];
}

//change array by &
int &get(int *arry,int index){
    return arry[index];
}

//6.33
//Recursively outputs values in the vector
//print_vector(vec.begin(),vec.end())
//or void print_vector(vector<int>::iterator begin,vector<int>::iterator end)
void print_vector(vector<int>::const_iterator begin,vector<int>::const_iterator end){
    if(begin!=end){
        cout<<*begin<<endl;
        print_vector(++begin,end);
    }else
        return;
}

//6.36
string (&func(string (&arrstr)[10]))[10];
//6.37
using Arr=string[10];
Arr &fun1(Arr& arr);
auto fun2(Arr& arr)->string(&)[10];
string strs[10];
decltype(strs) &fun3(Arr &arr);

inline const string &shorterString(const string &s1,const string &s2){
    cerr<<"__func__:"<<__func__<<endl;
    return s1.size()<=s2.size()?s1:s2;
}


constexpr int new_sz(){return 42;}
constexpr size_t scale(size_t cnt){return new_sz()*cnt;}

//6.47
//vector<string> vec={"11","22","33"};
//print_vec(vec);
void print_vec(vector<string>&vec){
    #ifndef DEBUG
    cout<<"vector size="<<vec.size()<<endl;
    #endif

   if(!vec.empty()){
      auto tmp=vec.back();
      vec.pop_back();
      print_vec(vec);
     cout<<"print vector:"<<tmp<<" ";
   }
}

int main(int argv,char **argc){
    initializer_list<int> list={1,2,3,4,5,6,7,8,9,10};
    cout<<count(list.begin(),list.end())<<endl;

    error_msg(ErrCode(0),{"functionx","okay"}); 

    string s("a value");
    cout<<get_val(s,2)<<endl;

    int ia[10];
    for(size_t i=0;i!=10;++i){
        get(ia,i)=i;
        cout<<ia[i]<<"   ";
    }
    
    vector<int> vec={11,22,33,44,55,66,77,88,99};
    print_vector(vec.begin(),vec.end());

   unsigned len=10;
   string bad[len];
   cout<<bad[0]<<endl;
   //assert(list.size()>1200);//Assertion `list.size()>1200' failed
    cout<<shorterString("hello","2021")<<endl;

    int arr[scale(2)];
    int i=2;
    int a2[scale(i)];
    
    vector<string> vec2;
    string cins;
    while(getline(cin,cins)){
        if(cins=="")
           break;
        vec2.push_back(cins);
        
    }
    print_vec(vec2);
    return 0;
}
