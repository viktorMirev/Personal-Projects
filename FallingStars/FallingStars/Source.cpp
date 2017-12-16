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

void InputHandler(char* symbol, int* numberOfStars)
{
	cout << "Falling Stars" << endl;
	while (*numberOfStars<MINIMUM_STAR_NUMBER && *numberOfStars>MAXIMUM_STAR_NUMBER)
	{
		cout << "Please enter the number of the stars ("<<MINIMUM_STAR_NUMBER<<", "<<MAXIMUM_STAR_NUMBER<<")" << endl;
		cin >> *numberOfStars;
	}
	cout << "Please enter the symbol representing a star" << endl;
	cin >> *symbol;
}

int main()
{
	int numberOfStars = 0;
	char symbol;
	InputHandler(&symbol,&numberOfStars);
	LetItSnow();
}