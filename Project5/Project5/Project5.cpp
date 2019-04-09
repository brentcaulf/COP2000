//Brent Caulfield
//COP2000.001
//Project 5 - A C++ program that will use the input file numbers.txt to determine the number 
// of even numbers, the number of odd numbers, and the number of zeroes that exist in the file.

#include<iostream>
#include<fstream>
#include <cstdlib>

using namespace std;

//Prototypes
ifstream openFile();								//Open the input file in the current directory
int readFile(ifstream& file);						//Read a number from the input file and return that number to the calling function
void determine(int num, int& O, int& E, int& Z);	//Determines if the number is odd, even, or zero and increment it's counter variable
void display(int Odds, int Evens, int Zeroes);		//Display the total number of odd, even, and zero numbers in the file
void closeFile(ifstream& file);						//Close the input file

//Main Function
int main()
{
	//Variables
	int num = 0;		//Used by readFile and determine to check number type
	int NrOfOdds = 0;	//Number of odds
	int NrOfEvens = 0;	//Number of evens
	int NrOfZeroes = 0;	//Number of zeroes

	ifstream inNumbers;	// File

	//Open file, validate it, and set its variable
	inNumbers = openFile();

	//Priming the read
	num = readFile(inNumbers);

	//While the ifstream is valid loop through the file checking each number then gets the number on the next line
	while (inNumbers)
	{
		determine(num, NrOfOdds, NrOfEvens, NrOfZeroes);
		num = readFile(inNumbers);
	}

	//Display results
	display(NrOfOdds, NrOfEvens, NrOfZeroes);

	//Close file
	closeFile(inNumbers);

	//End program
	system("pause");
	return 0;
}

/**********************Function Definitions**********************/

//Opens and validates the file
ifstream openFile()
{
	ifstream fileToOpen;

	//File name and open call
	fileToOpen.open("numbers.txt");

	//Validate
	if (!fileToOpen)
	{
		//Display error message, pause, then exit
		cerr << "numbers.txt did not open properly" << endl;
		system("pause");
		exit(0);
	}

	return fileToOpen;
}

//Reads a line of the file and returns an int
int readFile(ifstream& file)
{
	int num = 0;

	//Read file line and set to num
	file >> num;

	return num;
}

//Takes in a int and the number of odds,evens, and zeroes and then determines what it is and adds to it's total
void determine(int num, int& O, int& E, int& Z)
{	
	if (num % 2 > 0) //If division remainder is greater than 0 it must be odd
		O++;
	else if (num == 0) //If the num int is equal to 0 its zero
		Z++;
	else               //Otherwise it must be even
		E++;
}

//Closes the file
void closeFile(ifstream& file)
{
	file.close();
}

//Displays the number of odds, evens, and zeroes
void display(int Odds, int Evens, int Zeroes)
{
	cout << "numbers.txt contains the following number types." << endl << endl;
	cout << "Number of Odds: " << Odds << endl;
	cout << "Number of Evens: " << Evens << endl;
	cout << "Number of Zeroes: " << Zeroes << endl;
	cout << endl;
}