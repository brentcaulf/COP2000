//Brent Caulfield
//COP2000.001
//Project 3 - The Speed of Sound

//Write a C++ program that displays a menu allowing the user to select air, water, or steel.After the user has made a selection, 
//the number of feet a sound wave will travel in the selected medium should be entered.The program will then display the amount of time 
//it will take.Round the answer to 4 decimal places.
//
//Input validation : decide how the program should handle an illegal input for the menu choice or distance.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//variables	
	int MenuSelection = 0;
	int NrOfFeet = 0;
	float TimeToTravel = 0.0f;
	float const AIR = 1100.0f, WATER = 4900.0f, STEEL = 16400.0f;

	//Display introduction
	cout << "Calculate the time it takes for sound to travel through a inputed length in Air, Water, and Steel." << endl << endl;

	//Display menu, prompt selection, and get selection
	cout << "********************" << endl;
	cout << "Enter 1 for Air." << endl;
	cout << "Enter 2 for Water." << endl;
	cout << "Enter 3 for Steel." << endl;
	cout << "********************" << endl << endl;

	cout << "Your choice: ";
	cin >> MenuSelection;

	//Validate menu selection input
	while (MenuSelection < 1 || MenuSelection > 3 || !cin)
	{
		cout << "Invalid menu choice. Please enter 1, 2, or 3: ";
		fseek(stdin, 0, SEEK_END);
		cin.clear();
		cin >> MenuSelection;
	}

	//Prompt user to input the number of feet a sound wave will travel
	cout << endl << "Please enter the number of feet: ";
	cin >> NrOfFeet;
	
	//Validate sound wave input
	while (NrOfFeet < 0 || !cin)
	{
		cout << "Invalid input. Please enter a whole number greater than 0: ";
		fseek(stdin, 0, SEEK_END);
		cin.clear();
		cin >> NrOfFeet;
	}	

	//Calculate and display result
	cout << endl << fixed << setprecision(4);

	switch (MenuSelection)
	{
	case 1: TimeToTravel = NrOfFeet / AIR;
		cout << "It will take " << TimeToTravel << " seconds for sound to travel through " << NrOfFeet << " feet of air." << endl;
		break;
	case 2: TimeToTravel = NrOfFeet / WATER;
		cout << "It will take " << TimeToTravel << " seconds for sound to travel through " << NrOfFeet << " feet of water." << endl;
		break;
	case 3: TimeToTravel = NrOfFeet / STEEL;
		cout << "It will take " << TimeToTravel << " seconds for sound to travel through " << NrOfFeet << " feet of steel." << endl;
		break;
	}

	cout << endl;
	
	//end program
	system("pause");
	return 0;
}