#include<iostream>
//page:245
class Screen{
	friend size_t get_ctr(const Screen &);
	public:
		using pos=std::string::size_type;

		void some_member()const;

		Screen()=default;
		Screen(pos width,pos height):w(width),h(height)i,contents(""){}
		Screen(pos width,pos height,const std::string &c):w(width),h(height),contents(c){}

		char get()const{return contents[cursor];}
		inline char get(pos r,pos c)const;
		Screen &move(pos r,pos c);
	private:
		mutable size_t access_ctr;
		pos cursor;
		pos w,h;
		std::string contents;
};

//7.3.1
char Screen::get(pos r,pos c)const{
	return contents[r*w+c];
}
inline Screen &move(pos r,pos c){
	cursor=r*w+c;
	return *this;
}


size_t get_ctr(const Screen&s){
	return s.access_ctr;
}
void Screen::some_member()const{
	++access_ctr;
}

int main(int argc,char **argv){

	Screen s;
	for(size_t i=0;i<4;++i){
		s.some_member();
		std::cout<<i<<" "<<get_ctr(s)<<std::endl;
	}
	std::cout<<get_ctr(s)<<std::endl;
	return 0;
}
