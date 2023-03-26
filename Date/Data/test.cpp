#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
#include<iostream>
using namespace std;
void Test()
{
	Date d(2023, 3, 26);
	Date dd(d);
	d -= 100;
	d += 100;
	dd -= 100;

	
	cout << (d-dd) << endl;
}
int main()
{
	Test();
	return 0;
}