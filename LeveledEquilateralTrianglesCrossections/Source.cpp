/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Viktor Mirev
* @idnumber 62231
* @task 7
* @compiler VC
*
*/



#include<iostream>
#include<algorithm>
using namespace std;

/*
this function gives as a result a number which is
0 if the triangle is not leveled and 1,2 or 3 if
the triangle is leveled and the number tells which point
is upmost
*/


int IsLeveled(double x1, double y1, double x2, double y2, double x3, double y3)
{
	if (y1 == y3)
	{
		return 2;
	}
	if (y1 == y2)
	{
		return 3;
	}
	if (y2 == y3)
	{
		return 1;
	}
	return 0;
}

int main()
{

}