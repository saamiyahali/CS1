#include <iostream>
using namespace std;

/*******************************************************************************
 * Global variable
*******************************************************************************/

const int COL_SIZE = 5;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

int total(const int[][COL_SIZE], const int);
double average(const int[][COL_SIZE], const int);
void userInit(int[][COL_SIZE], const int);

/*******************************************************************************
 * Description:
 * Starting point of the program. Declares and initializes a 2D array. Displays
 * the total sum and the average value. Repeats but with user values.
 *
 * Input:
 * N/A
 *
 * Output:
 * An integer that signals the exit code to the operating system (OS)
*******************************************************************************/

int main() {
	const int ROW_SIZE = 4;

	// TODO: declare and initialize a 2D array
	int intArray[ROW_SIZE][COL_SIZE] =
	{
	{117, -76, 128, -68, 85},
	{105, 34, -79, 54, 105},
	{-85, 151, 133, -50, 173},
	{-38, -20, 185, 173, -49}
	};
	// TODO: call functions to display the calculations
	int total_val = total(intArray, ROW_SIZE);
	double average_val = average(intArray, ROW_SIZE);


	cout << "Total: " << total_val << "\nAverage: " << average_val << endl;
	// now let the user try
	cout << "\nNow it's your turn!\n";

	// TODO: create a 2D array for the user with different row size
	const int NEW_ROW_SIZE = 2;
	int userArray[NEW_ROW_SIZE][COL_SIZE];


	// TODO: call functions to let user initialize 2D array and calculate again
	userInit(userArray, NEW_ROW_SIZE);
	int user_total_val = total(userArray, NEW_ROW_SIZE);
	double user_average_val = average(userArray, NEW_ROW_SIZE);
	cout << "Your Total: " << user_total_val << "\nYour Average: " << user_average_val << endl;



	// terminate
	return 0;
}



int total(const int intArray[][COL_SIZE], const int ROW_SIZE)
{
	int total = 0;
	for (int row = 0; row < ROW_SIZE; row++){
		for (int col = 0; col < COL_SIZE; col++){
			total += intArray[row][col];
		}
	}
	return total;
}

double average(const int intArray[][COL_SIZE], const int ROW_SIZE)
{
	int counter = 0;
	double average, total = 0;
	for (int row = 0; row < ROW_SIZE; row++){
		for (int col = 0; col < COL_SIZE; col++){
			total += intArray[row][col];
			counter++;
		}
	}

	average = total / counter;
	return average;
}

void userInit(int userArray[][COL_SIZE], const int NEW_ROW_SIZE)
{

	for (int row = 0; row < NEW_ROW_SIZE; row++){
		cout << "Enter 5 numbers in a row (" << (row + 1) << "/2): ";
		for (int col = 0; col < COL_SIZE; col++) {
			cin >> userArray[row][col];
		}

	}
}
