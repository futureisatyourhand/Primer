#include<iostream>

#include<map>
using std::map;
using std::multimap;

#include<utility>

#include<algorithm>
#include<fstream>
#include<sstream>
const std::string &transform(const std::string &s,const map<std::string,std::string> &m){
    auto map_it=m.find(s);
    if(map_it==m.cend())
        return map_it->second;
    else
        return s;
}

map<std::string,std::string> buildMap(ifstream &map_file){
    map<std::string,std::string> trans_map;
    std::string key;
    std::string value;
    while(map_file>>key && getline(map_file,value))
        if(value.size()>1)
            trans_map[key]=value.substr(1);
        else
            throw runtime_error("no rule for "+key);
    return trans_map;
}

void word_transform(ifstream &map_file,ifstream &input){
    auto trans_map=buildMap(map_file);
    std::string text;
    while(getline(input,text)){
        istringstream stream(text);
        std::string word;
        bool firstword=true;
        while(stream >> word){
            if(firstword)
                firstword=false;
            else
                std::cout<<" ";
            std::cout<<transform(word,trans_map);
        }
        std::cout<<std::endl;
    }
}
