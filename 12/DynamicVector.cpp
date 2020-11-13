#include<iostream>

#include<vector>
using std::vector;

//12.6
vector<int>* factory(){
    return new vector<int>();
}

void add_element(vector<int> *vec){
    int i;
    while(std::cin>>i)
        vec->push_back(i);
}

void print(vector<int> *vec){
    for(auto i:*vec)
        std::cout<<i<<" ";
    std::cout<<std::endl;
}


//12.7
#include<memory>
using std::shared_ptr;
using std::make_shared;
shared_ptr<vector<int>> factory2(){
    return make_shared<vector<int>>();
}
void add_element(shared_ptr<vector<int>> vec){
    int i;
    while(std::cin>>i)
        vec->push_back(i);

}
void print(shared_ptr<vector<int>> vec){
    for(auto v:*vec)
        std::cout<<v<<" ";
    std::cout<<std::endl;
}

//12.14
struct destination{};
struct connection{};
connection connect(destination *);
void disconnect(connection);
void end_connection(connection *p){disconnect(*p);}

void f(destination &d){
    connection c=connect(&d);
    //disconnect(*p);
    shared_ptr<connection> p(&c,end_connection);
}

connection connect(destination *des){
    std::cout<<"already connect"<<std::endl;
    return connection();
}
void disconnect(connection){
    std::cout<<"has been discount"<<std::endl;
}


//12.15
#include<functional>
using namespace std::placeholders;
void f2(destination &d){
    connection c=connect(&d);
    //shared_ptr<connection> p(&c,[](connection *p){disconnect(*p);});
    shared_ptr<connection> p(&c,bind(end_connection,_1));
}
int main(int argv,char **argc){
    //vector<int>* p=factory();
    
    shared_ptr<vector<int>> p=factory2();
    add_element(p);
    print(p);
    //delete p;
    //auto ptr:auto delete 
    
    destination d;
    f2(d);
    return 0;
}
