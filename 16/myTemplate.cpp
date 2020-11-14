#include<iostream>
using namespace std;
#include<vector>

#include<list>
#include<string>

//16.2
template<typename T>
int compare(const T &v1,const T &v2){
	if(v1<v2) return -1;
	if(v2<v1) return 1;
	return 0;
}


//16.4
//list<string> lst={"beijing","shanghai","guangzhou","chongqing"};
//auto f=find(lst.begin(),lst.end(),"shanghai");
template <typename I,typename T>
I find(I beg,I end,const T &val){
	auto iter=beg;
	for(;iter!=end;++iter){
		if(*iter==val)
			return iter;
	}
	return end;
}

//16.5
//int p[]={1,2,3,4,5};
//print(p);
template<typename V, unsigned T>
void print(const V (&a)[T]){
	auto i=0;
	for(;i!=T;++i)
		cout<<" "<<a[i];
	cout<<endl;
}


//16.6
//for(auto p=begin(arr);p!=end(arr);++p) cout<<*p<<endl;
template<typename V,unsigned T>
V *begin(const V (&arr)[T]){
	return &arr[0];
}
template<typename V,unsigned T>
V *end(const V (&arr)[T]){
	return &arr[T-1];
}

//16.7
template<typename V,unsigned T>constexpr
unsigned size(const V (&arr)[T]){
	return T-1;
}

int main(int argv, char **argc){
	std::cout<<compare(1,0)<<std::endl;

	std::vector<int> v1{1,2,3};
	std::vector<int> v2{1,2,3};
	std::cout<<compare(v1,v2)<<std::endl;

	//16.4
	auto p=find(v1.begin(),v1.end(),2);
	std::cout<<*p<<std::endl;
	
	list<string>lst={"beijing","shanghai","chongqing","guangzhou"};
	auto ls=find(lst.begin(),lst.end(),"chongqing");
	std::cout<<*ls<<std::endl;

	//16.5
	int arr[]={1,2,3,4,5,6,7,8,9,10,12,13};
	print(arr);
	string str[]={"a","b","c"};
	print(str);	
	
	//16.6	
	for(auto i=begin(arr);i!=end(arr);++i)
		cout<<*i<<" ";
	cout<<endl;
	
	//16.7
	cout<<size(arr)<<endl;
	return 0;
}
