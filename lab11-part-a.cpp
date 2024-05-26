#include <iostream>

using namespace std;

int main()
{
    // variables
    int maxVal = 0, userNumber = 0;
    const int SENTINEL = -1;

    // TODO: create a `while` loop version of finding the maximum number
    /*
    while (userNumber != SENTINEL)
    {
    	cout << "Enter a positive number or " << SENTINEL << " to stop: ";
    	cin >> userNumber;
    	if (userNumber > maxVal)
    	{
    		maxVal = userNumber;
    	}
    }
	*/

    // TODO: create a `do-while` loop version of finding the maximum number
    /*
    do
    {
    	cout << "Enter a positive number or " << SENTINEL << " to stop: ";
    	cin >> userNumber;
    	if (userNumber > maxVal)
    	{
    		maxVal = userNumber;
    	}
    } while (userNumber != SENTINEL);
    */

    // TODO: create a `for` loop version of finding the maximum number
    // /*
    for (; userNumber != SENTINEL;)
    {
    	cout << "Enter a positive number or " << SENTINEL << " to stop: ";
    	cin >> userNumber;
    	if (userNumber > maxVal)
    	{
    		maxVal = userNumber;
    	}
    }
    // */
    // display results
    cout << "\nMaximum number entered: " << maxVal << endl;

    // terminate
    return 0;
}
