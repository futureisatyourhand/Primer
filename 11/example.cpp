#include<iostream>

#include<map>
using std::map;
using std::multimap;
#include<utility>
using std::pair;

#include<vector>
using std::vector;

#include<string>
#include<algorithm>
void example1(map<std::string,size_t> &word_count){
    std::string word;
    while(getline(std::cin,word)){
        if(word=="")
            break;
        ++word_count[word];
    }
    for(const auto &w:word_count)
        std::cout<<w.first<<" accurs:"<<w.second<<((w.second>1)?"times":"time")<<std::endl;
}

//11.12
void vector_pair(){
    pair<std::string,int>p;
    int val;
    std::string strs;
    vector<pair<std::string,int>> vec;
    while(std::cin>>strs>>val){
        p={strs,val};
        //p=make_pair(strs,val);
        //pair<std::string ,int>p{strs,val};
        vec.push_back(p);
    }

    for(const auto &w:vec)
        std::cout<<w.first<<" "<<w.second<<std::endl;
}
//11.20
void map_insert(map<std::string,size_t> &mp){
    //map<std::string,size_t> mp;
    std::string word;
    while(getline(std::cin,word)){
        if(word=="")
            break;
        if(isupper(word[0]))
            word[0]=tolower(word[0]);
        if(ispunct(word[word.size()-1]))
            word.pop_back();
        auto ret=mp.insert({word,1});
        if(!ret.second)//existed
            ++ret.first->second;
    }
    for(const auto &w:mp)
        std::cout<<w.first<<" "<<w.second<<((w.second>1)?" times":" time")<<std::endl;
}

//11.23
void insert_mul(multimap<std::string,std::string> &mp,const std::string &fam,const std::string &child){
    mp.insert({fam,child});
}

//11.31
void remove_author(multimap<std::string,std::string> &books,const std::string &author){

    auto entries=books.count(author);
    if(!entries){
        std::cout<<"author doesn't exist"<<std::endl;
        return;
    }else{
        auto iter=books.find(author);
        while(entries){
            iter=books.erase(iter);
            --entries;
        }
    }
}
void print_books(multimap<std::string,std::string> &books){
    if(books.empty()){
        std::cout<<"it's empy"<<std::endl;
        return;
    }
    for(auto item:books){
        std::cout<<"author:"<<item.first<<";"<<item.second<<std::endl;
    }
}
int main(int argv,char **argc){
    map<std::string ,size_t> wc;
    //example1(wc);
    
    //vector_pair();
    
    //map_insert(wc);
    
    multimap<std::string,std::string> mp;
    //insert_mul(mp,"abc","a");
    //insert_mul(mp,"def","d");
    //for(auto &w:mp)
    //    std::cout<<w.first<<":"<<w.second<<std::endl;
    
    multimap<std::string,std::string>books;
    books.insert({"author1","book1"});
    books.insert({"author1","book2"});
    books.insert({"author2","book1"});
    books.insert({"author2","book2"});
    print_books(books);
    return 0;
}
