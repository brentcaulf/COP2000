//Brent Caulfield
//COP2000.001
//Project 6 - Gets a length and width of a rectangle from the user than calculates the area and perimeter

#include <iostream>
#include <iomanip>
using namespace std;

//Class declaration and variable/member function declarations
class Rectangle
{
private:
	//User Input Variables
	float length;
	float width;

public:
	//Functions
	Rectangle();

	void setLength(float num);
	void setWidth(float num);

	float getLength();
	float getWidth();

	float getArea();
	float getPerimeter();
};

//Constructor
Rectangle::Rectangle()
{
	length = 0.0f;
	width = 0.0f;
}

//Called from driver to set the length variable with user input
void Rectangle::setLength(float num)
{
	length = num;
}

//Called from driver to set the width variable with user input
void Rectangle::setWidth(float num)
{
	width = num;
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

/******Beginning of Main Function Section******/

//Prototypes

void driver(Rectangle& Obj);
float setLength();
float setWidth();
void validate(float& num);
void displayResults(Rectangle& Obj);

//Main Function
int main()
{
	//Create rectangle object
	Rectangle RecObj;
	//Call driver function
	driver(RecObj);

	system("pause");
	return 0;
}

/******Function Definitions******/
//The primary driving function
void driver(Rectangle& Obj)
{
	//Display program purpose
	cout << "This program calculates the area and perimeter of a rectangle." << endl << endl;

	//Set the Length and Width using getNum
	Obj.setLength(setLength());
	Obj.setWidth(setWidth());

	//Displays the results
	displayResults(Obj);
}

//Gets a length, validates it, then returns it
float setLength()
{
	float num;

	cout << "Please enter a length: ";
	cin >> num;

	validate(num);

	return num;
}

//Gets a width, validates it, then returns it
float setWidth()
{
	float num;

	cout << "Please enter a width: ";
	cin >> num;

	validate(num);

	return num;
}

//Validates the user input
void validate(float& num)
{
	while (!cin || num <= 0)
	{
		cout << "Invalid input, try again: ";
		fseek(stdin, 0, SEEK_END);
		cin.clear();
		cin >> num;
	}
}

//Calls the getArea and getPerimeter functions from the Rectangle class to display the results
void displayResults(Rectangle& Obj)
{
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Rectangle Area is: " << Obj.getArea() << endl;
	cout << "Rectangle Perimeter is: " << Obj.getPerimeter() << endl << endl;
}