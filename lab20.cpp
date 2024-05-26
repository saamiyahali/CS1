#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

int main() {

	int user_choice;
	cout << "hi :P learn abt some new functions! pick whatever number you want to learn about: \n";
	cout << "1. isdigit\n" << "2. isspace\n" << "3. ispunct" << endl;
	cout << "4. strpbrk\n" << "5. strcpy\n" << "6. strcmp" << endl;
	cout << "7. find\n" << "8. replace\n" << "9. rbegin" << endl;
	cin >> user_choice;

	switch(user_choice)
	{
		case 1:
		{
			cout << "isdigit checks if character is decimal digit. Decimal digits are any of the following: 0 1 2 3 4 5 6 7 8 9.\n";
			cout << "Returns true if argument is a digit, false if not. For example:\n " << endl;

			char case1;
			cout << "Enter a number: ";
			cin >> case1;

			if (isdigit(case1))
			{
				cout << "its a digit!" << endl;
			}
			else
			{
				cout << "its not a digit..." << endl;
			}

			break;
		}
		case 2:
		{
			cout << "isspace checks if the character is a white-space. This includes space, newline, tab, and vertical tab.\n";
			cout << "Returns true if argument is a white-space, false if not. For example:\n " << endl;

			char case2;
			cout << "Enter a white-space: ";
			cin.ignore();
			cin.get(case2);

			if (isspace(case2))
			{
				cout << "its a white-space!" << endl;
			}
			else
			{
				cout << "its not a white-space..." << endl;
			}

			break;
		}
		case 3:
		{
			cout << "ispunct checks if the character is a punctuation. This includes all graphic characters that are not alphanumeric (so a printable character other than a digit, letter, or space).\n";
			cout << "Returns true if argument is a punctuation, false if not. For example:\n " << endl;

			char case3;
			cout << "Enter a punctuation: ";
			cin >> (case3);

			if (ispunct(case3))
			{
				cout << "its a punctuation!" << endl;
			}
			else
			{
				cout << "its not a punctuation..." << endl;
			}

			break;
		}
		case 4:
		{
			cout << "strpbrk locates the first occurrence of any character in str2 in str1.\n";
			cout << "Returns a pointer to the occurrence, or null pointer if none of the characters of str2 is found in str1 before the terminating null-character/not found at all. For example:\n " << endl;

			char case4str1[] = "Sample sentence";
			char case4str2[] = "place";
			char * occ;
			occ = strpbrk(case4str1, case4str2);

			cout << "First occurrence of any character of " << case4str2 << " in " << case4str1 << " is at position " << occ-case4str1+1 << endl;

			break;
		}
		case 5:
		{
			cout << "strcpy copies second C-string to first C-string.\n";
			char case5str1[] = "sad";
			char case5str2[] = "happy";

			cout << "String 1: " << case5str1 << endl;
			cout << "String 2: " << case5str2 << endl;
			strcpy(case5str1, case5str2);
			cout << "Copy done. Str 1 is now " << case5str1 << endl;

			break;
		}
		case 6:
		{
			cout << "strcmp compares the C string str1 to the C string str2.\n";
			cout << "Returns 0 if str1 and str2 are the same, returns negative if str1 < str2, returns positive if str1 > str2. For example:\n " << endl;

			char case6str1[] = "heard";
			char case6str2[] = "herd";
			int compare = strcmp(case6str1, case6str2);
			cout << "Is heard the same as herd? " << compare << endl;

			break;
		}
		case 7:
		{
			cout << "find searches the string for the first occurrence of the sequence specified by its arguments." << endl;
			cout << "When pos is specified, the search only includes characters at or after position pos." << endl;

			string case7str1;
			string case7str2;
			cout << "Enter your first string: ";
			cin.ignore();
			getline(cin, case7str1);

			cout << "Enter your second string: ";
			getline(cin, case7str2);
			size_t position = case7str1.find(case7str2);

			cout << "\nPosition of " << case7str2 << " in " << case7str1 << " is at: " << position << endl;

			break;
		}
		case 8:
		{
			cout << "replace replaces the n characters in str1 beginning at position x with the characters in string object str";
			string case8str1 = "sad";
			string case8str2 = "happy";

			cout << "String 1: " << case8str1 << endl;
			cout << "String 2: " << case8str2 << endl;
			case8str1.replace(0, 5, case8str2);
			cout << "Copy done. String 1 is now " << case8str1 << endl;

			break;
		}
		case 9:
		{
			cout << "rbegin is a return reverse iterator to reverse the beginning of a string\n";
			cout << "If the string object is const-qualified, the function returns a const_iterator. Otherwise, it returns an iterator.:\n " << endl;

			string case9str = "racecar tacocat!!!!";
			for (string::reverse_iterator rit = case9str.rbegin(); rit!=case9str.rend(); rit++)
			{
				cout << *rit;
			}



			break;
		}
	}


	return 0;
}
