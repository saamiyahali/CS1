#include <iostream>
#include <string>

using namespace std;

/*******************************************************************************
 * Global variable
*******************************************************************************/

unsigned numCalls = 0;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

bool  checkValid(float);
float getFPNumber();
void  myFunc(float, bool = false);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls functions in various ways and
 * combinations. Displays the total number of function calls.
 *
 * Input:
 * N/A
 *
 * Output:
 * An integer representing the exit value to signal back to the OS
*******************************************************************************/

int main() {
    // call the functions
    myFunc(getFPNumber());
    myFunc(getFPNumber() + 9.5f);
    myFunc(getFPNumber(), true);
    myFunc(getFPNumber() - 17.84f, true);

    // display the total number of function calls made
    cout << "Number of function calls: " << numCalls << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Description: if the parameter variable is >= 6.7, return true, otherwise return false. increment function calls counter
 * Input: user's floating point num
 * Output: true or false
*******************************************************************************/

bool checkValid(float fpn)
{
	if (fpn >= 6.7f) {
		numCalls++;
		return true;
	}
	else {
		numCalls++;
		return false;
	}
}

/*******************************************************************************
 * Description: ask the user for floating-point value and store the input to variable. use valid check function to
 * check validity of function. increment function calls counter
 * Input: N/A
 * Output: valid floating point number
*******************************************************************************/

float getFPNumber()
{
	float fpn;

	do {
		cout << "Enter a floating-point value: ";
		cin >> fpn;
	} while (!checkValid(fpn));

	numCalls++;
	return fpn;
}

/*******************************************************************************
 * Description: set static string to some value. Display value and update it by "doubling" the string.
 * if the Boolean parameter is true, display the square value of the first parameter
 * if the Boolean parameter is false , display the value of the first parameter divided in half. increment function calls counter
 * Input: floating point number, bool
 * Output: N/A
*******************************************************************************/

void  myFunc(float fpn, bool x)
{
	static string name = "cat ";
	cout << name << endl;
	name += name;

	if (x)
	{
		cout << pow(fpn, 2) << endl;
	}
	else
	{
		cout << fpn * 0.5 << endl;
	}

	numCalls++;

}
