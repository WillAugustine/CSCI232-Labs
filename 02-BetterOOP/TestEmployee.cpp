/*
  TestEmployee.cpp

  Author: Will Augustine

  Description: Tests to ensure the Employee class is functioning
	as expected and calculates total salary, mean salary, and 
	mean years of service on an array of Employee objects
*/

// Include the Employee class
#include "Employee.h"
#include <array>

using namespace std;

/*
  Prints all employee information of inputted employees

  Inputs:
	Employee employees[]: array of Employee objects
	int numOfEmployees: size of inputted employees array

  Outputs: None
*/
static void printAllEmployeeInfo(Employee employees[], int numOfEmployees)
{
	for (int i = 0; i < numOfEmployees; i++)
	{
		Employee currEmployee = employees[i];
		currEmployee.print();
	}
}

/*
  Calculates the total salary of inputted employees

  Inputs:
	Employee employees[]: array of Employee objects
	int numOfEmployees: size of inputted employees array

  Outputs:
	float: the total salary of inputted employees
*/
static float calculateTotalSalary(Employee employees[], int numOfEmployees)
{
	// Start the total salary at 0
	float totalSalary = 0.0;

	// For each employee in inputted array of employees
	for (int i = 0; i < numOfEmployees; i++)
	{
		Employee currEmployee = employees[i];
		// Add current employee salary to total salary
		totalSalary += currEmployee.getEmpSalary();
	}
	return totalSalary;
}

/*
  Calculates the mean salary of inputted employees using the
	calculateTotalSalary method

  Inputs:
	Employee employees[]: array of Employee objects
	int numOfEmployees: size of inputted employees array

  Outputs:
	float: the mean salary of inputted employees
*/
static float calculateMeanSalary(Employee employees[], int numOfEmployees)
{
	// Get the total salary of inputted employees
	float totalSalary = calculateTotalSalary(employees, numOfEmployees);

	return totalSalary / numOfEmployees;
}

/*
  Calculates the mean years of service of inputted employees

  Inputs:
	Employee employees[]: array of Employee objects
	int numOfEmployees: size of inputted employees array

  Outputs:
	float: the mean years of service of inputted employees
*/
static float calculateMeanYearsOfService(Employee employees[], int numOfEmployees)
{
	// Start total years of service at 0
	float totalYearsOfService = 0.0;

	// For each employee in inputted array of employees
	for (int i = 0; i < numOfEmployees; i++)
	{
		Employee currEmployee = employees[i];
		// Add current employee years of service to the total
		totalYearsOfService += (float)currEmployee.getEmpYearsOfService();
	}
	return totalYearsOfService / (float)numOfEmployees;
}

// Main testing function
int main()
{
	// Creates five objects of Employee class using both
	// default and parameterized constructors
	Employee emp1("Frank", 123456.7, 5);
	Employee emp2;
	Employee emp3("Julie", 523, 7);
	Employee emp4("Mark", 150000, 16);
	Employee emp5("Brad", 112086.6, 13);

	// Create array of all Employee objects
	Employee employees[5] = { emp1, emp2, emp3, emp4, emp5 };

	// Print information of all employees in employees array
	cout << "Here are all of our employees:\n" << endl;
	printAllEmployeeInfo(employees, 5);

	// Display the total salary of all employees
	cout << "\nTheir salary total is $" << calculateTotalSalary(employees, 5) << endl;
	// Display the mean salary of all employees
	cout << "Their salary mean is $" << calculateMeanSalary(employees, 5) << endl;
	// Display the mean years of service of all employees
	cout << "Their years of service mean is " << calculateMeanYearsOfService(employees, 5) << "\n" << endl;

	// Update emp2's name, salary, and years of service
	employees[1].setEmpName("Jose");
	employees[1].setEmpSalary(85000.75);
	employees[1].setEmpYearsOfService(1);

	// Print information of all employees in employees array
	cout << "Here are all of our employees:\n" << endl;
	printAllEmployeeInfo(employees, 5);

	// Display the total salary of all employees
	cout << "\nTheir salary total is $" << calculateTotalSalary(employees, 5) << endl;
	// Display the mean salary of all employees
	cout << "Their salary mean is $" << calculateMeanSalary(employees, 5) << endl;
	// Display the mean years of service of all employees
	cout << "Their years of service mean is " << calculateMeanYearsOfService(employees, 5) << "\n" << endl;
}