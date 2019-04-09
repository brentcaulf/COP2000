//Brent Caulfield
//COP2000.001
//Project 6 - Gets a length and width of a rectangle from the user than calculates the area and perimeter

#include <iostream>
#include <iomanip>
using namespace std;

class Rectangle
{
private:
	//Variables
	float length;
	float width;

	//Functions	
	float setLength();
	float setWidth();
	void validate(float&);
	float getLength();
	float getWidth();
	float getArea();
	float getPerimeter();
	void displayResults();

public:
	Rectangle();
	void driver();
};

//Constructor
Rectangle::Rectangle()
{
	length = 0.0f;
	width = 0.0f;
}

//The primary driving function called from main function
void Rectangle::driver()
{
	cout << "This program calculates the area and perimeter of a rectangle." << endl << endl;

	length = setLength();
	width = setWidth();

	displayResults();
}

//Called from driver to set the length variable with user input
float Rectangle::setLength()
{
	float num;

	cout << "Please enter a length: ";
	cin >> num;

	validate(num);

	return num;
}

//Called from driver to set the width variable with user input
float Rectangle::setWidth()
{
	float num;

	cout << "Please enter a width: ";
	cin >> num;

	validate(num);

	return num;
}

//Validates the user input
void Rectangle::validate(float& num)
{
	while (!cin || num <= 0)
	{
		cout << "Invalid input, try again: ";
		fseek(stdin, 0, SEEK_END);
		cin.clear();
		cin >> num;
	}
}

//Returns the length variable
float Rectangle::getLength()
{
	return length;
}

//Returns the width variable
float Rectangle::getWidth()
{
	return width;
}

//Calculates the area using getLength and getWidth functions.
float Rectangle::getArea()
{
	float area = 0.0f;
	area = getLength() * getWidth();
	return area;
}

//Calculates the perimeter using getLength and getWidth functions.
float Rectangle::getPerimeter()
{
	float perimeter = 0.0f;
	perimeter = 2 * (getLength() + getWidth());
	return perimeter;
}

//Calls the getArea and getPerimeter functions to display the results
void Rectangle::displayResults()
{
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Rectangle Area is: " << getArea() << endl;
	cout << "Rectangle Perimeter is: " << getPerimeter() << endl << endl;
}

int main()
{
	//Create Rectangle Object
	Rectangle RecObj;
	//Call Driver function
	RecObj.driver();

	system("pause");
	return 0;
}


