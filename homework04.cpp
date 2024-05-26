#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	int user_choice = 0;
	cout << "Welcome to my program! Pick an option:\n"
			<< "1. calculate the area of circle\n"
			<< "2. calculate the area of rectangle\n"
			<< "3. calculate the area of triangle\n"
			<< "4. a random choice\n"
			<< "5. exit program\n";
	cout << "\nEnter your option choice: ";
	cin >> user_choice;

	if (user_choice == 4)
	{
		srand(time(0));
		user_choice = 1 + rand() % (3 - 1 + 1);
		cout << "Option " << user_choice << " has been chosen!\n";
	}

	switch (user_choice)
	{
		case 1:
		{
			float radius = 0;
			float pi = 3.14159;
			cout << "Enter the radius value: ";
			cin >> radius;

			if (radius > 0)
			{
				float circle_area = 0.5 * pi * pow(radius, 2);
				cout << "The area of your circle is " << circle_area << endl;
				break;
			}
			else
			{
				cout << "Number can't be negative or 0 :(\n";
				break;
			}
		}
		case 2:
		{
			float length = 0, width = 0;
			cout << "Enter the width and length: ";
			cin >> width >> length;

			if ((width > 0) && (length > 0))
			{
				float rec_area = width * length;
				cout << "The area of your rectangle is " << rec_area << endl;
				break;
			}
			else
			{
				cout << "Number can't be negative or 0 :(\n";
				break;
			}

		}
		case 3:
		{
			float base = 0, height = 0;
			cout << "Enter the base and height: ";
			cin >> base >> height;

			if ((base > 0) && (height > 0))
			{
				float tri_area = 0.5 * base * height;
				cout << "The area of your triangle is " << tri_area << endl;
				break;
			}
			else
			{
				cout << "Number can't be negative or 0 :(\n";
				break;
			}
		}
		case 5:
		{
			cout << "Now exiting program.\n";
			break;
		}
		default:
		{
			cout << "Error, invalid choice!\n";
			break;
		}
	}

	// terminate
	return 0;
}
