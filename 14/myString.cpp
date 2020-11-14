#include<iostream>
#include<utility>


#include<memory>
//14.7
class String{
	friend std::ostream &operator<<(std::ostream &os,String &s);//const String &  error because element is changed

	//14.16
	friend bool operator==(const String &s1,const String &s2);
	friend bool operator!=(const String &s1,const String &s2);
public:
	String():element(nullptr),first_free(nullptr){}
	String(char *);
private:
	static std::allocator<char>alloc;
	char *element;
	char *first_free;
};
std::allocator<char>String::alloc;

//14.16
bool operator==(const String &s1,const String &s2){
	auto i=s1.element;
	auto j=s2.element;
	if((s1.first_free-s1.element)!=(s2.first_free-s2.element))
		return false;
	while((i!=s1.first_free) && (j!=s2.first_free))
		if(*(i++)!=*(j++))
			return false;
	return true;
}
bool operator!=(const String &s1,const String &s2){
	return !(s1==s2);
}

std::ostream &operator<<(std::ostream &os,String &s);

String::String(char *s){
	int i=0;
	while(s[i]!='\0')
		++i;
	auto newloc=alloc.allocate(i);
	auto dest=newloc;
	for(auto count=0;count!=i;++count)
		alloc.construct(dest++,s[count]);
	element=newloc;
	first_free=dest;
}

std::ostream &operator<<(std::ostream &os,String &s){
	while(s.element!=s.first_free){
		os<<*(s.element);
		s.element++;
	}
	std::cout<<std::endl;
	return os;
}

int main(int argv,char **argc){
	String s1;
	String s2("hellq world");
	String s3("hello world");
	std::cout<<s1;
	std::cout<<s2;
	std::cout<<s3;
	std::cout<<std::endl;
	std::cout<<(s2==s3)<<std::endl;
	return 0;
}
