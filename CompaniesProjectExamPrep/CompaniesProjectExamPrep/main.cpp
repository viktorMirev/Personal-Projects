#include<iostream>
#include"Consortium.h"
#include"Company.h"
#include"PrivateCompany.h"
#include"StateOwnedCompany.h"
using namespace std;

int main()
{
	Consortium highwayAvt("Highway Adventurers");
	PrivateCompany bgBagers("Bulgarian Bagers",2);
	StateOwnedCompany vlek("Perfect vlekachi");
	Consortium grunch("grunci");
	PrivateCompany carpenters("Perfect Carpenters",4);

	grunch.addSubcontractor(carpenters);
	highwayAvt.addSubcontractor(bgBagers);
	highwayAvt.addSubcontractor(vlek);
	highwayAvt.addSubcontractor(grunch);

	highwayAvt.printStatus();

	cout << highwayAvt.reliabilityRate() << endl;

	highwayAvt.perform("pedalska rabota");
	highwayAvt.perform("kef da ima");
	highwayAvt.perform("hvarlqne na lesha");
	highwayAvt.perform("otidi do IKEA");
	highwayAvt.perform("iztreznqvane");
	highwayAvt.perform("galena da pee");
	highwayAvt.perform("salfetki da valqt");
	highwayAvt.perform("pusni show biz");

	cout << highwayAvt.reliabilityRate() << endl;

	system("pause");
}