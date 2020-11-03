#include<iostream>
#include<string>
using namespace std;
//
string::size_type find_char(const string &s,char f,string::size_type &occurs){
    if(occurs==0)
        return 1;
    for(auto it=0;it!=s.size();++it){
        if(s[it]==f)
            return it;
    }
    return -1;
}

//6.17
bool is_upper(const string &s){
    for(auto &c:s){
        if(isupper(c))
            return true;
    }
    return false;
}
//6.17
bool change_lower(string &s){
    for(auto &c:s){
       c=tolower(c); 
   }
}
//6.21
int my_compare(int a,int *b){
    if(a>*b)
        return a;
    else
        return *b;
}
//6.22
int change_point(int *&a,int *&b){
    int *c=NULL;
    c=a;
    a=b;
    b=c;
}
int main(int argv,char **argc){
    string::size_type str=10;
    cout<<find_char("hello world",'w',str)<<endl;


   string str1="hello World";
   cout<<is_upper(str1)<<endl;
   change_lower(str1);   
   cout<<str1<<endl;

   int x,y;
   cin>>x>>y;
   int *val2=&y;
   cout<<"compare"<<my_compare(x,val2)<<endl;
   
    int *val1=&x;
    cout<<"before exchange int point:"<<*val1<<" "<<*val2<<endl;
    change_point(val1,val2);
    cout<<"after exchange int point:"<<*val1<<" "<<*val2<<endl;
}
