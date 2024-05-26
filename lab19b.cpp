#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

void   printParallel(const vector<double&>, const vector<string&>);
double updateAndSum(const vector<double&>, const vector<string&>);

/*******************************************************************************
 * Description:
 * Starting point of the program. Creates two arrays. Uses loops to let the user
 * populate the arrays. Calls functions to print out and update the arrays in
 * parallel.
 *
 * Input(s):
 * N/A
 *
 * Output:
 * An integer that signals the exit code to the operating system (OS)
*******************************************************************************/

int main() {
    // declare first array
    double firstVector(5);

    // range-based `for` loop to get user input for `firstArray`
    for (double& elem : firstVector) {
        cout << "Enter a floating-point number: ";
        cin  >> elem;
        firstVector.push_back(elem);
    }

    // declare second array
    string secondVector;

    // normal `for` loop to get user input for `secondArray`
    cin.ignore();
    for (unsigned i = 0; i < firstVector.size(); i++) {
        string elem;
    	cout << "Enter a name: ";
        getline(cin, secondVector[elem]);
    }

    // function calls
    printParallel(firstVector, secondVector);
    cout << "Sum: " << updateAndSum(firstVector, secondVector) << endl;
    printParallel(firstVector, secondVector);

    // terminate
    return 0;
}

/*******************************************************************************
 * Description:
 * Uses a `while` loop to print the two arrays in parallel.
 *
 * Input(s):
 * DARR       - a constant array of `double` elements
 * SARR       - a constant array of `string` elements
 * ARRAY_SIZE - a constant integer that represents how many elements exist in
 *              the arrays
 *
 * Output:
 * N/A
*******************************************************************************/

void printParallel(const vector<double&> DARR, const vector<string&> SARR) {
    cout << endl;
    int i = 0;
    while (i < DARR.size) {
        cout << DARR.at(i) << ' ' << SARR.at(i) << endl;
        i++;
    }
    cout << endl;
}

/*******************************************************************************
 * Description:
 * Uses a normal `for` loop to update `darr` by adding the length of its
 * parallel element in `SARR`. Also calculates the sum of the new values.
 *
 * Input(s):
 * darr       - an array of `double` elements
 * SARR       - a constant array of `string` elements
 * ARRAY_SIZE - a constant integer that represents how many elements exist in
 *              the arrays
 *
 * Output:
 * The sum of the newly updated elements in `darr`.
*******************************************************************************/

double updateAndSum(vector<double&> darr, const vector<string&> sarr) {
    double sum = 0.0;
    for (int i = 0; i < darr.size; i++) {
        darr[i] += sarr.at(i);
        sum += darr[i];
    }
    return sum;
}
