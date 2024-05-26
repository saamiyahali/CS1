#include <iostream>

using namespace std;

int main()
{
    // constants (DO NOT MODIFY)
    const int MAX_ROWS  = 11;
    const int MAX_STARS = 21;

    // outer loop controlling how many rows to print
    for (int row = 1; row <= MAX_ROWS; row++)
    {
        // inner loop to print the spaces on the left side
        for (int space = 0; space < row; space++)
        {
            cout << ' ';
        }

        // inner loop to print the stars
        for (int stars = 1; stars <= (MAX_STARS) - (row * 2); stars++)
        {
            cout << '*';
        }

        // break the line for the next row
        cout << endl;
    }

    // terminate
    return 0;
}
