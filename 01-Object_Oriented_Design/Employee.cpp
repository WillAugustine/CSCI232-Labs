/*
  Employee.cpp

  Author: Will Augustine

  Description: The Employee class with corresponding tests in
	the main method
*/

#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
	int ID;
	string SSN;
	string firstName;
	string lastName;
	int yearsOfService;
	float hourlyPayRate;
	float hoursWorked;

public:
	Employee(int id,
		string ssn,
		string name_first,
		string name_last,
		int serviceLength,
		float rate,
		float hours)
	{
		this->ID = id;
		this->SSN = ssn;
		this->firstName = name_first;
		this->lastName = name_last;
		this->yearsOfService = serviceLength;
		this->hourlyPayRate = rate;
		this->hoursWorked = hours;
	}

	void setID(int id)
	{
		this->ID = id;
	}

	void setSSN(string ssn)
	{
		this->SSN = ssn;
	}

	void setFirstName(string name_first)
	{
		this->firstName = name_first;
	}

	void setLastName(string name_last)
	{
		this->lastName = name_last;
	}
	
	void setYearsOfService(int serviceLength)
	{
		this->yearsOfService = serviceLength;
	}

	void setHourlyPayRate(float rate)
	{
		this->hourlyPayRate = rate;
	}
	
	void setHoursWorked(float hours)
	{
		this->hoursWorked = hours;
	}

	int getID()
	{
		return this->ID;
	}

	string getSSN()
	{
		return this->SSN;
	}

	string getFirstName()
	{
		return this->firstName;
	}

	string getLastName()
	{
		return this->lastName;
	}

	int getYearsOfService()
	{
		return this->yearsOfService;
	}

	float getHourlyPayRate()
	{
		return this->hourlyPayRate;
	}

	float getHoursWorked()
	{
		return this->hoursWorked;
	}
};

int main()
{
	Employee emp1(1, "123-45-6789", "John", "Smith", 3, 10.25, 40);
	Employee emp2(2, "234-56-7890", "Kayleen", "Macey", 25, 80.72, 0);
	Employee emp3(3, "345-67-8901", "Ruby", "Betts", 18, 84.95, 40);
	Employee emp4(5, "456-78-9012", "Teddy", "Gordon", 13, 65.13, 40);
	Employee emp5(5, "567-89-0123", "Rickey", "Tate", 20, 77.72, 25);
	Employee emp6(6, "678-90-1234", "Dora", "Explorer", 13, 58.17, 20);
	Employee emp7(7, "789-01-2345", "Clark", "Tex", 11, 51.47, 28);
	Employee emp8(8, "890-12-3456", "Byron", "Garey", 1, 68.34, 36);
	Employee emp9(9, "901-23-4567", "Phil", "Lucinda", 14, 51.36, 8);
	Employee emp10(10, "012-34-5678", "Hillary", "Gales", 16, 30.76, 35);
	
	Employee employees[10] = { emp1, emp2, emp3, emp4, emp5, emp6, emp7, emp8, emp9, emp10 };
}