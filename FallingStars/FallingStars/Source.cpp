#include<iostream>
#include<windows.h>
using namespace std;

int const MAXIMUM_STAR_NUMBER = 30;
int const MINIMUM_STAR_NUMBER = 8;
int const CONSOLE_WIDTH = 80;
int const CONSOLE_HEIGHT = 25;
int const MINIMUM_DISTANCE = 6;
int const MAXIMUM_DISTANCE = 25;
int const STAR_LENGHT = 6;

struct FallingStar
{
	int x;
	int y;
	int distance;
	FallingStar()
	{
		this->x = rand() % 80;
		this->y = 0;
		this->distance = 6 + rand() % 19;
	}
};

int main()
{
	InputHandler();
	LetItSnow();
}