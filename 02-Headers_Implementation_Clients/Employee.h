#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

class Employee
{
private:
	string EmpName;
	double EmpSalary;
	int EmpYearsOfService;

public:
	Employee();
	Employee(string, double, int);

	void setEmpName(string);
	void setEmpSalary(double);
	void setEmpYearsOfService(int);

	string getEmpName();
	double getEmpSalary();
	int getEmpYearsOfService();

	void print();
};

#endif