/*
  Employee.cpp

  Author: Will Augustine

  Description: The Employee class that contains a default
	constructor and parameterized constructor. There are
	getters and setters for the employee information (name,
	salary, and years of service)
*/

// Include the class header file
#include "Employee.h"

/*
  Employee class default constructor

  Inputs: None

  Outputs: None
*/
Employee::Employee()
{
	// set employee name to default value
	this->EmpName = "John Smith";
	// set employee salary to default value
	this->EmpSalary = 1234.5;
	// set employee years of service to default value
	this->EmpYearsOfService = 0;
}

/*
  Employee class parameterized constructor

  Inputs:
	string name: the name of the employee
	float salary: the salary of the employee
	int yearsOfService: how long the employee has been with the company

  Outputs: None
*/
Employee::Employee(string name, float salary, int yearsOfService)
{
	this->EmpName = name;
	this->EmpSalary = salary;
	this->EmpYearsOfService = yearsOfService;
}

/*
  Setter for employee name

  Inputs:
	string name: the updated employee name

  Outputs: None
*/
void Employee::setEmpName(string name)
{
	this->EmpName = name;
}

/*
  Setter for employee salary

  Inputs:
	float salary: the updated employee salary

  Outputs: None
*/
void Employee::setEmpSalary(float salary)
{
	this->EmpSalary = salary;
}

/*
  Setter for employee years of service

  Inputs:
	int yearsOfService: the updated employee years of service

  Outputs: None
*/
void Employee::setEmpYearsOfService(int yearsOfService)
{
	this->EmpYearsOfService = yearsOfService;
}

/*
  Getter for employee name

  Inputs: None

  Outputs: 
	string: the employee's name
*/
string Employee::getEmpName()
{
	return this->EmpName;
}

/*
  Getter for employee salary

  Inputs: None

  Outputs:
	float: the employee's salary
*/
float Employee::getEmpSalary()
{
	return this->EmpSalary;
}

/*
  Getter for employee years of service

  Inputs: None

  Outputs:
	int: the employee's years of service
*/
int Employee::getEmpYearsOfService()
{
	return this->EmpYearsOfService;
}

/*
  Prints all information about the employee

  Inputs: None

  Outputs: None
*/
void Employee::print()
{
	cout << this->EmpName << " makes $" << this->EmpSalary
		<< " after being at the company for " << this->EmpYearsOfService
		<< " years." << endl;
}