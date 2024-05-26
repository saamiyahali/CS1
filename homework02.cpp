#include <iostream>
#include <string>

using namespace std;

int main()
{
	// TODO 1
	string employee_name = "Sam Hill";
	int hours_per_month = 100;
	float pay_rate = 16.50;

	// TODO 2
	float monthly_pay = hours_per_month * pay_rate;
	float monthly_rent = 850;
	float monthly_utility = 100;

	// TODO 3
	float money_after_rent = monthly_pay - monthly_rent;
	float money_after_utility = money_after_rent - monthly_utility;

	// TODO 4
	int days_per_month = 30;
	float per_diem = money_after_utility / days_per_month;

	// TODO 5

	cout << "Employee report for Sam Hill\n";
	cout << "\nPay rate: $" << pay_rate << endl;
	cout << "Hours worked per month: " << hours_per_month << endl;
	cout << "Total pay: " << hours_per_month << " * " << pay_rate << " = $" << monthly_pay << endl;
	cout << "\nRent: $" << monthly_rent << endl;
	cout << "Utility Bill: $" << monthly_utility << endl;
	cout << "\nAfter rent: $" << monthly_pay << " - $" << monthly_rent << " = $" << money_after_rent << endl;
	cout << "After utility: $" << money_after_rent << " - $" << monthly_utility << " = $" << money_after_utility << endl;
	cout << "\nSpend per day: " << money_after_utility << " / " << days_per_month << " = $" << per_diem << endl;


    // terminate
    return 0;
}
