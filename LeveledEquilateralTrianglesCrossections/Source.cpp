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

/*
Function that calculates the distance between two points
*/
double Distance(double x1, double y1, double x2, double y2)
{
	double dis = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	return dis;
}

/*
Function that determines weather the triangle is equaliteral
it returns the side if it is true
*/

double IsEqualiteral(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double firstSide = Distance(x1, y1, x2, y2);
	double secondSide = Distance(x2, y2, x3, y3);
	double thirdSide = Distance(x1, y1, x3, y3);



	if (round(firstSide * 100) / 100 == round(secondSide * 100) / 100 && round(secondSide * 100) / 100 == round(thirdSide * 100) / 100)
	{
		return firstSide;
	}

	return 0;

}

/*
Function that find the crossection
where the vertices are like this
   11
   * *
  *   *
12 * * 13

   21
   * *
  *   *
22 * * 23
*/

double Crossection(double x11, double y11, double x12, double y12, double x13, double y13, double x21, double y21, double x22, double y22, double x23, double y23)
{
	double height1 = sqrt(3)*(x13 - x12) / 2;
	double height2 = sqrt(3)*(x23 - x22) / 2;

	double disPoint11toSide23 = abs(y11 - y22); //Point 1 from the first triangle to side 23 from the second
	double disPoint21toSide23 = abs(y21 - y12); //Point 1 from the second triangle to side 23 from the first
	if (disPoint11toSide23 >= (height1 + height2) || disPoint21toSide23 >= (height1 + height2))
	{
		return 0;
	}

	double a23 = (y11 - y12) / (x11 - x12); //the coeficent in  y = ax + b function
	double b23 = y11 - a23*x11;
	//calculating the distance between the point 23 to side 12 from triangle 1
	double disPoint23toSide12 = abs(y23 - a23*x23 - b23) / 2;
	if (disPoint23toSide12 >= (height1 + height2))
	{
		return 0;
	}

	double a13 = (y21 - y22) / (x21 - x22); //the coeficent in  y = ax + b function
	double b13 = y21 - a13*x21;
	//calculating the distance between the point 13 to side 12 from triangle 2
	double disPoint13toSide12 = abs(y13 - a13*x13 - b13) / 2;
	if (disPoint13toSide12 >= (height1 + height2))
	{
		return 0;
	}

	double a22 = (y11 - y13) / (x11 - x13); //the coeficent in  y = ax + b function  
	double b22 = y11 - a22*x11;
	//calculating the distance between the point 22 to side 13 from triangle 1
	double disPoint22toSide13 = abs(y22 - a22*x22 - b22) / 2;
	if (disPoint22toSide13 >= (height1 + height2))
	{
		return 0;
	}

	double a12 = (y21 - y23) / (x21 - x23); //the coeficent in  y = ax + b function
	double b12 = y21 - a12*x21;
	//calculating the distance between the point 12 to side 13 from triangle 2
	double disPoint12toSide13 = abs(y12 - a12*x12 - b12) / 2;
	if (disPoint12toSide13 >= (height1 + height2))
	{
		return 0;
	}
	//check if the minimum distance is bigger than the minimum height and the 
	//crossection in this case will be the area of the smaller triangle

	double realMin = min(disPoint11toSide23, disPoint12toSide13);

	realMin = min(realMin, disPoint13toSide12);
	realMin = min(realMin, disPoint21toSide23);
	realMin = min(realMin, disPoint22toSide13);
	realMin = min(realMin, disPoint23toSide12);



	if (realMin >= min(height1, height2))
	{
		return pow(min(height1, height2), 2) / sqrt(3);
	}


	//now you are sure that the smaller one is not inside the bigger 
	//but you are also sure that they have a non zero crossection
	//so the area of the crossection is the area of a triangle 
	//which has the height of the minimum distance

	return pow(realMin, 2) / sqrt(3);

	//nqma kak da sa minimalni i da sa 2 ednakvi ako ne sa 3
}

int main()
{
	/*
	TEST
	4, 3.4641, 2, 0, 6, 0
	cout << Crossection(3, 4.4641, 1, 1, 5, 1, 4, 3.4641, 2, 0, 6, 0) << endl;
	cout << Crossection(2, 3.4641, 0, 0, 4, 0, 2, 1.73205, 1, 0, 3, 0) << endl;
	cout << IsEqualiteral(3, 4.4641, 1, 1, 5, 1)<<endl;
	cout << IsLeveled(3, 4.4641, 1, 1, 5, 1) << endl;
	int a;
	cin >> a;
	return main();
	*/

	double x11, x12, x13, x21, x22, x23;
	double y11, y12, y13, y21, y22, y23;

	cout << "Enter the coordinates of the first triangle in the format x y" << endl;
	cout << "the coordinates for each point should be on separate lines" << endl;
	cin >> x11 >> y11;
	cin >> x12 >> y12;
	cin >> x13 >> y13;
	cout << endl;
	cout << "Enter the coordinates of the second triangle in the format x y" << endl;
	cout << "the coordinates for each point should be on separate lines" << endl;
	cin >> x21 >> y21;
	cin >> x22 >> y22;
	cin >> x23 >> y23;

	bool isBoth;
	bool isFirstEq = IsEqualiteral(x11, y11, x12, y12, x13, y13);
	bool isSecondEq = IsEqualiteral(x21, y21, x22, y22, x23, y23);
	
}