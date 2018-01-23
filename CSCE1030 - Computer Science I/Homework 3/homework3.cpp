
/*
============================================================================
Program Name : homework3.cpp
Author : Justin Wei
Instructor: David Keathley
Course: CSCE 1030
Date: 11/7/2016
Description : The program gets the input of two bases of a trapezoid as well as
a character symbol to draw a trapezoid. Returns the calculated area of the trapezoid.
============================================================================
*/


#include <iostream>

using namespace std;

//Functions
/*
============================================================================
Function : draw
Parameters : two integers for the bases of the trapezoid.
Return : nothing
Description : This function draws the trapezoid with the character
============================================================================
*/
void drawTrapezoid(int base1, int base2);

/*
============================================================================
Function : CalcluateArea
Parameters : two integers for the two bases
Return : a float for the calulated area of the trapezoid
Description : This function calulates the area of a trapezoid
============================================================================
*/
float calculateArea(int base1, int base2);

/*
============================================================================
Function : ValidateBase
Parameters : three integers for the base value and the range
Return : a boolean that is true if the base is valid, false otherwise.
Description : This function validates the base
============================================================================
*/
bool ValidateBase(int base, int min, int max);

int main(){

	//Variables

	//integers for the bases of the trapezoid
	int base1, base2;

	//float for the area of the trapezoid since we will be dividing by two.
	float area;

	cout << "+-----------------------------------------+" << endl;
	cout << "| Computer Science and Engineering        |" << endl;
	cout << "| CSCE 1030 - Computer Science I          |" << endl;
	cout << "| Justin Wei jaw0561 JustinWei@my.unt.edu |" << endl;
	cout << "+-----------------------------------------+" << endl;

	//Get input for base1
	do{
			cout << "Enter odd integer for base1 of trapezoid (1 - 21): " << endl;
			cin >> base1;

			//reset cin failure flag clear the input stream if invalid input
			if(cin.fail()){
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
    //base1 must be between the range [1,21]
	while(!ValidateBase(base1,1,21));

	//get input for base2
	do{
			cout << "Enter odd integer for base2 of trapezoid (3 - 23): " << endl;
			cin >> base2;

			//reset cin failure flag clear the input stream if invalid input
			if(cin.fail()){
				cin.clear();
				cin.ignore(1000,'\n');
			}
		}
  //Base2 must be between the range (base1 >= 3, 23]
	while(!ValidateBase(base2,base1 + 2, 23));

  //make space for trapezoid
	cout << '\n';

	//call draw function to draw trapezoid
	drawTrapezoid(base1, base2);

	//call calculateArea funtion to calculate area
	area = calculateArea(base1, base2);

	cout << "The area of the trapezoid is " << area << " units squared." << endl;

	return 0;

}


void drawTrapezoid(int base1, int base2){
  //caculate the height
	int height = (base2-base1)/2 + 1;

  //get input for printable character
  cout << "Please enter a printable character to draw trapezoid: " << endl;
  char symbol;
  cin >> symbol;

	//Maximum number of spaces before row
	int maxNumSpaces = height - 1;

	//loop through base1 to base2 and add two each time
	for(int rowLength = base1; rowLength <= base2; rowLength+=2){

		//print the amount of spaces
		for(int numSpaces = 0; numSpaces <maxNumSpaces; numSpaces++){
			cout << ' ';
		}

		//print the actual row
		for(int numSymbols = 0; numSymbols <rowLength; numSymbols++){
			cout << symbol;
		}

		//new line for new row
		cout << endl;

		//Less padding in fron for next row
		maxNumSpaces--;
	}

return;
}

bool ValidateBase(int base, int min, int max){
  //check if odd
  if(base % 2 != 1){
    cout << "error: not odd." << endl;
  }
  //check if in range
  else if (base < min || base > max) {
    cout << "error: out of range. Note that the second base must be greater than the first." << endl;
  }
  //must be valid if odd and in range
  else{
    return true;
  }


  //if it cannot pass those tests, it must be invalid.
  return false;
}

float calculateArea(int base1, int base2){
  //caculate the height
  int height = (base2-base1)/2 + 1;

	//uses the formula a = 1/2 * (b1 + b2) * h
	return .5 * (base1 + base2) * height;
}
