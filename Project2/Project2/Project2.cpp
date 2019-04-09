// Brent Caulfield
// COP2000.001
// Project 2 - Calculates a user's monthly and annual costs

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// Variables
	float Rent, Utilities, Phone, Cable, MonthlyCost, AnnualCost;

	// Display program title
	cout << "Expense Calculator" << endl << endl;

	// Ask for and get user input for rent
	cout << "Please enter the monthly amount of your rent or mortgage payment: $";
	cin >> Rent;

	// Ask for and get user input for utilities
	cout << "Please enter the monthly amount of your utilities payment: $";
	cin >> Utilities;

	// Ask for and get user input for phone
	cout << "Please enter the monthly amount of your phone payment: $";
	cin >> Phone;

	// Ask for and get user input for cable
	cout << "Please enter the monthly amount of your cable payment: $";
	cin >> Cable;

	//Calculate monthly and annual costs
	MonthlyCost = Rent + Utilities + Phone + Cable;
	AnnualCost = MonthlyCost * 12;

	// Display monthly and annual costs
	cout << fixed << showpoint << setprecision(2) << endl <<
		"Your monthly costs are: $" << MonthlyCost << endl;
	cout << "Your annual costs are: $" << AnnualCost << endl << endl;


	system("pause");

	return 0;
}