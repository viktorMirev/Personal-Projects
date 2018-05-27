#include<iostream>
#include"Pair.h"
#include"Settings.h"

using namespace std;

int main()
{
	Settings<int> * testSet = new Settings<int>();
	Pair<int> one("Mirev", 1);
	Pair<int> two("Emil", 2);

	cout << "Test some functionalities of the points" << endl;
	cout << endl;

	one.setValue(4);

	cout << one.getKey() << "  " << one.getValue() << endl;

	one = two;

	one.setValue(20);
	cout << one.getKey() << "  " << one.getValue() << endl;

	cout << endl;
	cout << "Test some functionalities of the Settings" << endl;
	cout << endl;

	testSet->set("first", 1);
	testSet->set("second", 2);
	cout << endl;
	int val;
	testSet->get("first", val);
	cout << endl;
	cout << "should be the value of the first" << endl;
	cout << val;
	cout << endl;
	cout << endl;
	testSet->set("first", 10);
	cout << "should change the value of the first" << endl;
	testSet->get("first", val);
	cout << val << endl;
	cout << endl;

	cout << "test the copy constructor" << endl;
	Settings<int> * test2Set = new Settings<int>(*testSet);
	testSet->get("first", val);
	cout << val << endl;
	cout << endl;



	cout << "test if the copy constructor changes the first object" << endl;
	test2Set->set("second", 30);
	int val2;
	testSet->get("second", val);
	test2Set->get("second", val2);
	cout << endl;
	cout << "should be different" << endl;
	cout << val <<"  " <<val2<< endl;
	cout << endl;


	cout << "test the operator=" << endl;
    *test2Set = *testSet;
	testSet->get("first", val);
	cout << val << endl;
	cout << endl;



	cout << "test if operator= changes the first object" << endl;
	test2Set->set("second", 40);
	int val3;
	testSet->get("second", val);
	test2Set->get("second", val3);
	cout << endl;
	cout << "should be different" << endl;
	cout << val << "  " << val3 << endl;
	cout << endl;


	cout << "Test the number counter" << endl;
	test2Set->set("third", 3);
	cout << "Number (should be 3): " << test2Set->count() << endl;

}