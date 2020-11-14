#include<iostream>

//14.27
/* 前置递增 */
StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
/* 前置递减 */
StrBlobPtr& StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}
/* 后置递增 */
StrBlobPtr StrBlobPtr::operator++(int)
{
	auto temp = *this;
	++*this;
	return temp;
}
/* 后置递减 */
StrBlobPtr StrBlobPtr::operator--(int)
{
	auto temp = *this;
	--*this;
	return temp;
}

//14.28    
StrBlobPtr& StrBlobPtr::operator+=(const size_t &n)
{
	check(curr, "increment past end of StrBlobPtr");
	curr += n;
	return *this;
}
 
StrBlobPtr& StrBlobPtr::operator-=(const size_t &n)
{	
	curr -= n;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}
 
 
StrBlobPtr operator+(const StrBlobPtr &lhs, const size_t &n)
{
	auto ret = lhs;
	ret += n;
	return ret;
}
 
StrBlobPtr operator-(const StrBlobPtr &lhs, const size_t &n)
{
	auto ret = lhs;
	ret -= n;
	return ret;
}
