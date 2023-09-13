#include "Employee.h"

Employee::Employee()
{
	this->EmpName = "John Smith";
	this->EmpSalary = 1234.5;
	this->EmpYearsOfService = 0;
}

Employee::Employee(string name, double salary, int yearsOfService)
{
	this->EmpName = name;
	this->EmpSalary = salary;
	this->EmpYearsOfService = yearsOfService;
}

void Employee::setEmpName(string name)
{
	this->EmpName = name;
}

void Employee::setEmpSalary(double salary)
{
	this->EmpSalary = salary;
}

void Employee::setEmpYearsOfService(int yearsOfService)
{
	this->EmpYearsOfService = yearsOfService;
}

string Employee::getEmpName()
{
	return this->EmpName;
}

double Employee::getEmpSalary()
{
	return this->EmpSalary;
}

int Employee::getEmpYearsOfService()
{
	return this->EmpYearsOfService;
}

void Employee::print()
{
	cout << this->EmpName << " makes $" << this->EmpSalary
		<< " after being at the company for " << this->EmpYearsOfService
		<< " years." << endl;
}