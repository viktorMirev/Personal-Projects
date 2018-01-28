#include<iostream>
using namespace std;

struct Line
{
	int x1;
	int y1;

	int x2;
	int y2;
};

bool AreParallelToX(Line * line1, Line * line2)
{
	return (line1->y1 == line1->y2 && line2->y1 == line2->y2);
}

bool AreParallelToY(Line * line1, Line * line2)
{
	return (line1->x1 == line1->x2 && line2->x1 == line2->x2);
}


int CommonLength(Line * line1, Line * line2)
{
	if (AreParallelToX(line1, line2))
	{
		if (line1->y1 == line2->y1)
		{
			if (line1->x2 < line1->x1) swap(line1->x1, line1->x2);
			if (line2->x2 < line2->x1) swap(line2->x1, line2->x2);

			int common = 0;
			if ((line1->x2 - line2->x1) > 0)  common += line1->x2 - line2->x1;
			return common;
		}
		return -1;
	}


	else
	{
		if (AreParallelToY(line1, line2)) 
		{
			if (line1->x1 == line2->x1)
			{
				if (line1->y2 < line1->y1) swap(line1->y1, line1->y2);
				if (line2->y2 < line2->y1) swap(line2->y1, line2->y2);

				int common = 0;
				if ((line1->y2 - line2->y1) > 0)  common += line1->y2 - line2->y1;
				return common;
			}
			return -1;
		}
	}

	return -1;
}


int main()
{
	Line lineOne;
	Line lineTwo;
	cin >> lineOne.x1 >> lineOne.y1;
	cin >> lineOne.x2 >> lineOne.y2;

	cin >> lineTwo.x1 >> lineTwo.y1;
	cin >> lineTwo.x2 >> lineTwo.y2;

	cout << CommonLength(&lineOne, &lineTwo) << endl;;
	system("pause");
	return 0;

}