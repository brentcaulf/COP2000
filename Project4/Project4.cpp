//Brent Caulfield
//COP2000.001
//Project 4 - Read in population figures from a .txt file then display a bar char
//which shows the population growth of Sparksville at 20 year intervals over 100 years.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//Variables
	ifstream popText;				//Stores the txt file
	int pop = 0;					//Stores input from the txt file
	int popCounter = 0;				//Used to determine number of asterisks
	int nrOfLines = 0;				//Number of lines in the text file
	int year = 1910;				//Starting year of the txt file input
	string asterisks;				//Stores the asterisk string to print
	const int POP_DIVISION = 1000;  //Used to determine number of asterisks

	//Open the People.txt file and print error message if not found
	popText.open("People.txt");
	if (!popText)
	{
		cerr << "People.txt not found please check file name." << endl << endl;
		return 1234;
	}
	//Get number of lines of txt file
	while (popText >> pop)
	{
		nrOfLines++;
	}

	//Close and then re-open popText to "reset" it. Assume good txt name since it was validated above.
	popText.close();
	popText.open("People.txt");

	//Display introduction
	cout << "Sparksville Population Growth" << endl;
	cout << "(each * represents 1000 people)" << endl << endl;

	//Start for loop to calculate and print asterisks and years
	for (int i = 0; i < nrOfLines; i++)
	{
		popText >> pop;					  //Read first line of text and send it to pop
		popCounter = pop / POP_DIVISION; //Get the number of asterisks by dividing pop by 1000
		while (popCounter > 0)
		{
			asterisks += "*";			//Add one asterisk to the asterisk string variable
			popCounter--;				//Decrement popCounter
		}
		cout << year << ": " << asterisks << endl; //Display results
		asterisks = "";							  //Reset asterisk variable
		year += 20;								 //Add 20 years
	}

	cout << endl;
	system("pause");
	return 0;
}
