#include<iostream>
#include"Car.h"
#include"Truck.h"
#include"Motorcycle.h"
#include"Vehicle.h"

using namespace std;

int main()
{
	
	Car * myCar = new Car("mercedes", "sls amg", "white", 2005, 12300);
	Car * yourCar = new Car(*myCar);
	char * ss = nullptr;
	
	myCar->Details();
	cout << endl;
	yourCar->Details();

	*myCar = *yourCar;

	yourCar->SetColor("red");
	
	myCar->Details();
	cout << endl;
	yourCar->Details();


	Truck * myTruck = new Truck("MAN", "freezer", "red", 2004, 123456 , 10);
	Truck * yTruck = new Truck(*myTruck);

	myTruck->Details();
	cout << endl;
	yTruck->Details();

	*yTruck = *myTruck;
	yTruck->SetColor("smth");
	cout << endl;

	myTruck->Details();
	cout << endl;
	yTruck->Details();


	Motorcycle * motor = new Motorcycle("KVZKI", "lighting", "dark", 2016, 20000, "speed enf");

	Motorcycle * otherMotor = new Motorcycle(*motor);

	cout << endl;
	motor->Details();
	cout << endl;
	otherMotor->Details();

	*otherMotor = *motor;
	otherMotor->SetMake("honda");
	
	cout << endl;
	motor->Details();
	cout << endl;
	otherMotor->Details();

	int a;

	cin >> a;

}