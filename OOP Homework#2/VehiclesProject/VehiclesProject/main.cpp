#include<iostream>
#include"Car.h"
#include"Truck.h"
#include"Motorcycle.h"
#include"Vehicle.h"

using namespace std;

int main()
{
	cout << "Test the car class" << endl;
	cout << endl;
	Car * myCar = new Car("mercedes", "sls amg", "white", 2005, 12300);
	Car * yourCar = new Car(*myCar);
	Car * nullCar = new Car();

	nullCar->Details();
	
	myCar->Details();
	cout << endl;
	yourCar->Details();

	cout << endl;
	cout << "test operator =" << endl;
	cout << endl;
	*myCar = *yourCar;

	yourCar->SetColor("red");
	
	myCar->Details();
	cout << endl;
	yourCar->Details();

	cout << endl;
	cout << "Test the Truck class" << endl;

	Truck * myTruck = new Truck("MAN", "freezer", "red", 2004, 123456 , 10);
	Truck * yTruck = new Truck(*myTruck);

	myTruck->Details();
	cout << endl;
	yTruck->Details();

	cout << endl;
	cout << "Test operator =" << endl;
	cout << endl;

	*yTruck = *myTruck;
	yTruck->SetColor("smth");
	cout << endl;

	myTruck->Details();
	cout << endl;
	yTruck->Details();

	cout << endl;
	cout << "Test motorcycle" << endl;
	cout << endl;

	Motorcycle * motor = new Motorcycle("KVZKI", "lighting", "dark", 2016, 20000, "speed enf");

	Motorcycle * otherMotor = new Motorcycle(*motor);

	cout << endl;
	motor->Details();
	cout << endl;
	otherMotor->Details();

	cout << "Test operator =" << endl;

	*otherMotor = *motor;
	otherMotor->SetMake("honda");
	
	cout << endl;
	motor->Details();
	cout << endl;
	otherMotor->Details();
	
}