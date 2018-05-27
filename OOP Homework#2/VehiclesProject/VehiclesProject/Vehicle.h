#pragma once

class Vehicle
{
public:
	Vehicle();
	Vehicle(const char* make, const char* model, const char* color, int year, double mileage);
	Vehicle(const Vehicle&);
	Vehicle& operator=(const Vehicle&);
	~Vehicle();
    virtual void Details() const;

	//getters (not really needed to be all public)
	int GetYear() const;
	double GetMileage() const;
	const char * GetMake() const;
	const char * GetModel() const;
	const char * GetColor() const;

	//setters (not really needed to be all public)
	void SetYear(int y);
	void SetMileage(double m);
	void SetMake(const char*);
	void SetModel(const char*);
	void SetColor(const char*);
private:
	char * make;
	char * model;
	char * color;
	int year;
	double mileage;

	//delete all dynamic
	
protected:
	void Delete();
	void CopyFromOther(const Vehicle&);
};