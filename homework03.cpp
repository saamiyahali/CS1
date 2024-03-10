#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // display the welcome message
    cout << "Welcome to my Word Game! This is the template:\n\n";

    // display the template
    cout << "This is the story of NOUN.\n";
    cout << "They are about NUMBER years old.\n";
    cout << "They like the color NOUN because \n";
    cout << "it reminds them of NOUN.\n";
    cout << "On weekends, they VERB because it makes them feel ADJECTIVE.\n";
    cout << "They work as a stock market investor.\n";
    cout << "Currently, they are focusing on a stock with price $NUMBER.\n";
    cout << "The stock name is NOUN and uses the marker SYMBOL.\n\n";

    // TODO: gather the input needed for the story

    cout << "Enter the first noun: ";
    string noun1;
    getline(cin, noun1);

    cout << "Enter the first number (integer): ";
    int number1 = 0;
    cin >> number1;

    cout << "Enter the second noun: ";
    string noun2;
    cin.ignore();
    getline(cin, noun2);

    cout << "Enter the third noun: ";
    string noun3;
    getline(cin, noun3);

    cout << "Enter the verb: ";
    string verb1;
    getline(cin, verb1);

    cout << "Enter the adjective: ";
    string adjective1;
    getline(cin, adjective1);

    cout << "Enter the second number (double): ";
    double number2 = 0;
    cin >> number2;

    cout << "Enter the fourth noun: ";
    string noun4;
    cin.ignore();
    getline(cin, noun4);

    cout << "Enter the symbol (char): ";
    char symbol1;
    cin >> symbol1;

    // TODO: display the story with the filled information

    cout << "\nThis is the story of " << noun1 << ".\n";
    cout << "They are about " << number1 << " years old.\n";
    cout << "They like the color " << noun2 << " because it reminds them of " << noun3 << ".\n";
    cout << "On weekends, they " << verb1 << " because it makes them feel " << adjective1 << ".\n";
    cout << "They work as a stock market investor.\n";
    cout << "Currently, they are focusing on a stock with price $" << number2 << ".\n";
    cout << "The stock name is " << noun4 << " and uses the marker " << symbol1 << ".\n";

    // TODO: seed the random number generator using the current system time

    srand(time(0));
    int random_number_1 = 2 + rand() % (4 - 2 + 1);
    int random_number_2 = 2 + rand() % (4 - 2 + 1);
    int random_number_3 = 2 + rand() % (4 - 2 + 1);
    int random_number_4 = 2 + rand() % (4 - 2 + 1);
    int random_number_5 = 2 + rand() % (4 - 2 + 1);

    // TODO: create the graph
    cout << left;

    cout << "\nHere is a visual graph of the stock: \n" << endl;

    cout << setfill(symbol1) << setw(static_cast<int>(number2 + 0.5)) << symbol1 << endl;

    double stock_price = number2 * random_number_1;
    cout << setfill(symbol1) << setw(static_cast<int>(stock_price + 0.5)) << symbol1 << endl;

    stock_price /= random_number_2;
    cout << setfill(symbol1) << setw(static_cast<int>(stock_price + 0.5)) << symbol1 << endl;

    stock_price += random_number_3;
    cout << setfill(symbol1) << setw(static_cast<int>(stock_price + 0.5)) << symbol1 << endl;

    stock_price -= random_number_4;
    cout << setfill(symbol1) << setw(static_cast<int>(stock_price + 0.5)) << symbol1 << endl;

    stock_price *= random_number_5;
    cout << setfill(symbol1) << setw(static_cast<int>(stock_price + 0.5)) << symbol1 << endl;

    // TODO: display the final stock price
    cout << setprecision(2) << fixed;
    cout << "\nIn the end, the stock ended at $" << stock_price;

    // terminate
    return 0;
}
