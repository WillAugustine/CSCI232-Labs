/*
  Employee.cpp

  Author: Will Augustine

  Description: The Employee class with corresponding tests in
	the main method
*/

#include <iostream>
#include <string>

using namespace std;

// Employee class
class Employee
{
// Private variables only visible to Employee class methods
private:
	// Employee ID
	int ID;
	// Employee social security number (string due to '-' in number)
	string SSN;
	// Employee first name
	string firstName;
	// Employee last name
	string lastName;
	// How long employee has worked at company
	int yearsOfService;
	// Employee pay rate (hourly)
	double hourlyPayRate;
	// Employee hours worked in pay period
	double hoursWorked;

// Public items in Employee class
public:
	/*
	Parameterized constructor

	Inputs: 
		int id: employee ID
		string ssn: employee social security number
		string name_first: employee first name
		string name_last: employee last name
		int serviceLength: employee time at company
		double rate: employee hourly rate of pay
		double hours: employee hours worked in pay period

	Outputs: None
	*/
	Employee(int id,
		string ssn,
		string name_first,
		string name_last,
		int serviceLength,
		double rate,
		double hours)
	{
		// Maps inputs to private class variables
		this->ID = id;
		this->SSN = ssn;
		this->firstName = name_first;
		this->lastName = name_last;
		this->yearsOfService = serviceLength;
		this->hourlyPayRate = rate;
		this->hoursWorked = hours;
	}

	/*
	Setter for employee ID

	Inputs:
		int id: employee ID

	Outputs: None
	*/
	void setID(int id)
	{
		this->ID = id;
	}

	/*
	Setter for employee first name

	Inputs:
		string name_first: employee first name

	Outputs: None
	*/
	void setFirstName(string name_first)
	{
		this->firstName = name_first;
	}

	/*
	Setter for employee last name

	Inputs:
		string name_last: employee last name

	Outputs: None
	*/
	void setLastName(string name_last)
	{
		this->lastName = name_last;
	}

	/*
	Setter for employee years of service

	Inputs:
		int serviceLength: employee time at company

	Outputs: None
	*/
	void setYearsOfService(int serviceLength)
	{
		this->yearsOfService = serviceLength;
	}

	/*
	Setter for employee hourly rate

	Inputs:
		double rate: employee hourly rate of pay

	Outputs: None
	*/
	void setHourlyPayRate(double rate)
	{
		this->hourlyPayRate = rate;
	}

	/*
	Setter for employee hours worked in pay period

	Inputs:
		double hours: employee hours worked in pay period

	Outputs: None
	*/
	void setHoursWorked(double hours)
	{
		this->hoursWorked = hours;
	}

	/*
	Getter for employee ID

	Inputs: None

	Outputs:
		int: employee ID
	*/
	int getID()
	{
		return this->ID;
	}
	
	/*
	Getter for employee social security number 

	Inputs: None

	Outputs:
		string: employee social security number
	*/
	string getSSN()
	{
		return this->SSN;
	}

	/*
	Getter for employee first name

	Inputs: None

	Outputs:
		string: employee first name
	*/
	string getFirstName()
	{
		return this->firstName;
	}

	/*
	Getter for employee last name

	Inputs: None

	Outputs:
		string: employee last name
	*/
	string getLastName()
	{
		return this->lastName;
	}

	/*
	Getter for employee years of service

	Inputs: None

	Outputs:
		int: employee time at company
	*/
	int getYearsOfService()
	{
		return this->yearsOfService;
	}

	/*
	Getter for employee hourly pay rate

	Inputs: None

	Outputs:
		double: employee hourly rate of pay
	*/
	double getHourlyPayRate()
	{
		return this->hourlyPayRate;
	}

	/*
	Getter for employee hours worked in pay period

	Inputs: None

	Outputs:
		double: employee hours worked in pay period
	*/
	double getHoursWorked()
	{
		return this->hoursWorked;
	}	
};

/*
Prints all names (first and last) of employees in inputted employees array

Inputs:
	Employee employees[]: array of Employee class objects to be printed
	int size: size of inputted employees array

Outputs: None
*/
void printEmployees(Employee employees[], int size)
{
	cout << "----- EMPLOYEE LIST -----" << endl;
	// For each Employee object in inputted employees array
	for (int i = 0; i < size; i++)
	{
		// Print employee first and last name
		cout << employees[i].getFirstName() << " " << employees[i].getLastName() << endl;
	}
	cout << endl;
}

/*
Prints all names (first and last) of employees in inputted employees array
	as well as their payroll summary (rate, hours worked, gross pay, tax rate,
	and net pay)

Inputs:
	Employee employees[]: array of Employee class objects to be printed
	int size: size of inputted employees array

Outputs: None
*/
void printPayrollInformation(Employee employees[], int size)
{
	cout << "----- PAYROLL SUMMARY -----" << endl;
	// For each Employee object in inputted employees array
	for (int i = 0; i < size; i++)
	{
		// Print employee first and last name
		cout << employees[i].getFirstName() << " " << employees[i].getLastName() << ":" << endl;
		// Print employee pay rate
		cout << "\tPay rate: $" << employees[i].getHourlyPayRate() << "/hour" << endl;
		// Print employee number of hours worked
		cout << "\tHours worked: " << employees[i].getHoursWorked() << endl;
		// Calculate gross pay and net pay given tax rate
		double taxRate = .1;
		double grossPay = employees[i].getHourlyPayRate() * employees[i].getHoursWorked();
		double netPay = grossPay * (1 - taxRate);
		// Print employee totals for payroll
		cout << "\tTotals: $" << grossPay << " with " << taxRate * 100 << "% tax = $" << netPay << endl;
	}
	cout << endl;
}

/*
Calculates the mean years of service for all employees in inputted
	array of Employee objects

Inputs:
	Employee employees[]: array of Employee class objects
	int size: size of inputted employees array

Outputs:
	double: the calculated mean years of service
*/
double calculateMeanYearsOfService(Employee employees[], int size)
{
	// Start total years of service for all employees at 0
	int totalYearsOfService = 0;
	// For each Employee object in inputted employees array
	for (int i = 0; i < size; i++)
	{
		// Add current employee years of service to total
		totalYearsOfService += employees[i].getYearsOfService();
	}
	// Calculate mean years of service and return value
	return double(totalYearsOfService) / double(size);
}

/*
Calculates the median years of service for all employees in inputted
	array of Employee objects. If not true median (even number of employees)
	then take average of middle two numbers

Inputs:
	Employee employees[]: array of Employee class objects
	int size: size of inputted employees array

Outputs:
	double: the calculated median years of service
*/
double calculateMedianYearsOfService(Employee employees[], int size)
{
	// Sort the Employee objects by their years of service
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (employees[j].getYearsOfService() > employees[j + 1].getYearsOfService()) {
				swap(employees[j], employees[j + 1]);
			}
		}
	}
	// If true median is available (odd number of employees)
	if ((size - 1) % 2 == 0)
	{
		// Return the true median
		return double(employees[size - 1].getYearsOfService());
	}
	// Otherwise (if true median is not available) calculate average of middle two values and return value
	return (double(employees[(size / 2) - 1].getYearsOfService() + employees[size / 2].getYearsOfService()) / double(2));
}

// Main function for testing
int main()
{
	// Create Employee objects
	Employee emp1(1, "123-45-6789", "John", "Smith", 3, 10.25, 40);
	Employee emp2(2, "234-56-7890", "Kayleen", "Macey", 25, 80.72, 0);
	Employee emp3(3, "345-67-8901", "Ruby", "Betts", 18, 84.95, 40);
	Employee emp4(4, "456-78-9012", "Teddy", "Gordon", 13, 65.13, 40);
	Employee emp5(5, "567-89-0123", "Rickey", "Tate", 20, 77.72, 25);
	Employee emp6(6, "678-90-1234", "Dora", "Explorer", 13, 58.17, 20);
	Employee emp7(7, "789-01-2345", "Clark", "Tex", 11, 51.47, 28);
	Employee emp8(8, "890-12-3456", "Byron", "Garey", 1, 68.34, 36);
	Employee emp9(9, "901-23-4567", "Phil", "Lucinda", 14, 51.36, 8);
	Employee emp10(10, "012-34-5678", "Hillary", "Gales", 16, 30.76, 35);

	// Set the number of Employee objects created
	const int numOfEmployees = 10;
	// Place Employee objects in array
	Employee employees[numOfEmployees] = { emp1, emp2, emp3, emp4, emp5, emp6, emp7, emp8, emp9, emp10 };
	
	// Sort the array of Employee objects by last name using bubble sort
	for (int i = 0; i < numOfEmployees - 1; i++) {
		for (int j = 0; j < numOfEmployees - i - 1; j++) {
			if (employees[j].getLastName() > employees[j + 1].getLastName()) {
				swap(employees[j], employees[j + 1]);
			}
		}
	}

	// Print all employee names
	printEmployees(employees, numOfEmployees);

	// Print all employee payroll information
	printPayrollInformation(employees, numOfEmployees);

	// Calculate and display mean years of service for all employees
	cout << "Mean years of service: " << calculateMeanYearsOfService(employees, numOfEmployees) << endl;

	// Calculate and display median years of service for all employees
	cout << "Median years of service: " << calculateMedianYearsOfService(employees, numOfEmployees) << endl;

	// Update some employee info to ensure methods work properly
	employees[2].setYearsOfService(36);
	employees[6].setHoursWorked(35);
	employees[0].setLastName("Zadarius");
	employees[9].setHourlyPayRate(35.25);
	employees[3].setFirstName("Franklin");

	// Re-sort the array of Employee objects by last name using bubble sort
	for (int i = 0; i < numOfEmployees - 1; i++) {
		for (int j = 0; j < numOfEmployees - i - 1; j++) {
			if (employees[j].getLastName() > employees[j + 1].getLastName()) {
				swap(employees[j], employees[j + 1]);
			}
		}
	}

	// Print all employee names
	printEmployees(employees, numOfEmployees);

	// Print all employee payroll information
	printPayrollInformation(employees, numOfEmployees);
	
	// Calculate and display mean years of service for all employees
	cout << "Mean years of service: " << calculateMeanYearsOfService(employees, numOfEmployees) << endl;

	// Calculate and display median years of service for all employees
	cout << "Median years of service: " << calculateMedianYearsOfService(employees, numOfEmployees) << endl;
}