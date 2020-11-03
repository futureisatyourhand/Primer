#include<iostream>
#include<string>
using namespace std;
//print(begin(int []),end(int[]))
void print(const int *beg,const int *end){
    while(beg!=end)
         cout<<*beg++<<endl;
}

//print_str(string.begin(),string.end())
void print_str(basic_string<char>::iterator beg,basic_string<char>::iterator end){
    while(beg!=end){
        cout<<*beg++<<endl;
       
    }
}

//print2(j,2)
void print2(const int ia[],size_t size){
    for(size_t i=0;i!=size;++i)
        cout<<ia[i]<<endl;
}

//char a[]={'1','2','3','4'}
//print3(a)
void print3(const char *cp){
    if(cp)
        while(*cp)
            cout<<*cp++<<endl;
}
//int a[10]={1,2,3,4,5,6,7,8,9,10}
//print3(a)
void print4(int (&arr)[10]){
    for(auto elem:arr)
        cout<<elem<<endl;
}
int main(int argv,char **argc){
    int i=0,j[2]={11,22};
    int k[]={10,20,30,40,50,60,70,80,90,100};
    print(begin(k),end(k));
    
    // 
    string strs="hello world!!!!!!";
    print_str(begin(strs),end(strs));
    
    //
    print2(j,2);
    
    //
    print4(k);
    // 
    char a[]={'1','2','3'};
    print3(a);
   
   string outs="";
   for(size_t i=1;i!=argv;++i){
        outs+=argc[i];
        outs+="  ";
    }
   cout<<outs<<endl;
    return 0;
}
