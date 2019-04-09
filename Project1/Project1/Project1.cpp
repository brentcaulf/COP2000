// Brent Caulfield
// COP2000.001
// Project 1: Personal Information

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// declare and define variables for all personal information
	string Name = "Brent Caulfield",
	Address = "2506 SW 98th DR Gainesville, FL 32608",
	Phone = "352-328-8107",
	Major = "Programming and Analysis";

	// display information on different lines using one cout statement
	cout << Name << endl << Address << endl << Phone << endl << Major << endl << endl;

	system("pause");

	return 0;
}