#include<iostream>
#include<unordered_set>

class Person{
    public:
        Person(std::string name,int age):name(name),age(age){};
        std::string getName()const;
        int getAge()const;
    private:
        std::string name;
        int age;
};

std::string Person::getName()const{
    return this->name;
}
int Person::getAge()const{
    return this->age;
}
//define my hash
class MyHash{
    public:
        int operator()(const Person &A)const{
            return A.getAge();
        }
};

//
bool operator==(const Person &A,const Person &B){
    return A.getAge()==B.getAge();
}

class MyHashFunc{
    public:
        bool operator()(const Person &a,const Person &b) const{
            return (a.getName()==b.getName())&&(a.getAge()==b.getAge());
        }
};

int main(int argv,char **argc){
    std::unordered_set<Person,MyHash> myset1{{"zhaoliying",35}};

    std::unordered_set<Person,MyHashFunc>myset2{{"zhangsan",30}};

    for(auto w=myset1.begin();w!=myset1.end();++w)
        std::cout<<w->getName()<<" "<<w->getAge()<<std::endl;

    for(auto w=myset2.begin();w!=myset2.end();++w)
        std::cout<<w->getName()<<" "<<w->getAge()<<std::endl;
    return 0;
}
