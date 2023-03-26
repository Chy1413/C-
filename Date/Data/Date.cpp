#include "Date.h"
// 获取某年某月的天数

int Date::GetMonthDay(int year, int month)
{
	int MonthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
		return 29;
	else
		return MonthDayArray[month];
}



// 全缺省的构造函数

Date::Date(int year, int month , int day )
{
	_year = year;
	_month = month;
	_day = day;
}



// 拷贝构造函数

// d2(d1)

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}



// 赋值运算符重载

// d2 = d3 -> d2.operator=(&d2, d3)

Date& Date::operator=(const Date& d)
{
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
	return *this;
}



// 析构函数

Date::~Date()
{
	_year = _month = _day = 0;
}



// 日期+=天数

Date& Date::operator+=(int day)
{
	Date& d = *this;
	d._day += day;
	while (d._day > GetMonthDay(d._year,d._month))
	{
		d._day -= GetMonthDay(d._year, d._month);
		d._month++;
		if (d._month == 13)
		{
			d._year++;
			d._month = 1;
		}
	}
	return d;
}



// 日期+天数

Date Date::operator+(int day)
{
	Date d(*this);
	d._day += day;
	while (d._day > GetMonthDay(d._year, d._month))
	{
		d._day -= GetMonthDay(d._year, d._month);
		d._month++;
		if (d._month == 13)
		{
			d._year++;
			d._month = 1;
		}
	}
	return d;
}



// 日期-天数

Date Date::operator-(int day)
{
	Date d(*this);
	d._day -= day;
	while (d._day <0)
	{
		d._day += GetMonthDay(d._year, d._month--);
		if (d._month == 0)
		{
			d._year--;
			d._month = 12;
		}
	}
	return d;
}



// 日期-=天数

Date& Date::operator-=(int day)
{
	Date& d = *this;
	d._day -= day;
	while (d._day < 0)
	{
		d._day += GetMonthDay(d._year, d._month--);
		if (d._month == 0)
		{
			d._year--;
			d._month = 12;
		}
	}
	return d;
}



//// 前置++
//
//Date& Date::operator++()
//{
//	return NULL;
//}
//
//
//
//// 后置++
//
//Date Date::operator++(int)
//{
//	return NULL;
//}



//// 后置--
//
//Date Date::operator--(int)
//{
//	return NULL;
//}
//
//
//
//// 前置--
//
//Date& Date::operator--()
//{
//	return NULL;
//}



// >运算符重载

bool Date::operator>(const Date& d)
{
	Date& p = *this;
	if (p._year > d._year)
		return true;
	else if (p._year == d._year && p._month > d._month)
		return true;
	else if (p._year == d._year && p._month == d._month && p._day > d._day)
		return true;
	else
		return false;
}



// ==运算符重载

bool Date::operator==(const Date& d)
{
	return this->_year == d._year
		&& this->_month == d._month
		&& this->_day == d._day;

}



// >=运算符重载

bool Date::operator >= (const Date& d)
{
	return this->operator>(d) || this->operator==(d);
}



// <运算符重载

bool Date:: operator < (const Date& d)
{
	return !(this->operator>=(d));
}



// <=运算符重载

bool Date:: operator <= (const Date& d)
{
	return this->operator<(d) || this->operator==(d);
}



// !=运算符重载

bool Date::operator != (const Date& d)
{
	return !(this->operator==(d));
}



// 日期-日期 返回天数

int Date::operator-(const Date& d) 
{
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (*this < d)
		//if (d > *this)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++n;
		min+=1;
	}

	return n * flag;
}