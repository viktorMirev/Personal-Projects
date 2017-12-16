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
int const FRAME_DELAY = 1000;

struct FallingStar
{
	int x;
	int y;
	int distance;
	FallingStar()
	{
		this->x = rand() % 80;
		this->y = 0;
		this->distance = 0;
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

void LetItDraw(FallingStar stars[MAXIMUM_STAR_NUMBER] , int* numberOfStars,char* symbol)
{
	system("cls");
	for (size_t i = 0; i < *numberOfStars; i++)
	{
		COORD coord = { stars[i].x,stars[i].y};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << *symbol;
	}
}

void LetItSnow(char* symbol, int* numberOfStars)
{
	FallingStar stars[MAXIMUM_STAR_NUMBER];
	while (true)
	{
		for (int i = 0; i < *numberOfStars; i++)
		{
			if (stars[i].distance == 0)
			{
				stars[i] = FallingStar();
				stars[i].distance = MINIMUM_DISTANCE + rand() % (MAXIMUM_DISTANCE - MINIMUM_DISTANCE);
			}
		}


		LetItDraw(stars,numberOfStars,symbol);


		for (int i = 0; i < *numberOfStars; i++)
		{
			stars[i].distance--;
			stars[i].y++;
		}

		Sleep(FRAME_DELAY);
	}
}

int main()
{
	int numberOfStars = 0;
	char symbol;
	InputHandler(&symbol,&numberOfStars);
	LetItSnow(&symbol,&numberOfStars);
}