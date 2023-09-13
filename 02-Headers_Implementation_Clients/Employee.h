/*
  Employee.h

  Author: Will Augustine

  Description: The Employee class header file
*/

// If the header file has not been defined, define it
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

class Employee
{
private:
	// Employee's name
	string EmpName;
	// Employee's salary
	float EmpSalary;
	// Employee's time at company (in years)
	int EmpYearsOfService;

public:
	// Default constructor
	Employee();
	// Parameterized constructor
	Employee(string, float, int);

	// Setters for employee information
	void setEmpName(string);
	void setEmpSalary(float);
	void setEmpYearsOfService(int);

	// Getters for employee information
	string getEmpName();
	float getEmpSalary();
	int getEmpYearsOfService();

	// Prints employee information
	void print();
};

// End if not defined if statement
#endif