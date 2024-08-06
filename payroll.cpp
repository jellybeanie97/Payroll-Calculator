#include <iostream>
#include <vector>
#include <iomanip> // For std::setprecision
using namespace std;

int main() {
    // Defining pay period
    int period_start_month, period_start_day, period_end_month, period_end_day;
    double total_hours = 0.0, rate, pay, bonus = 0.0;

    // Get the period start and end dates from the user
    cout << "Insert the start (mm/dd) and end (mm/dd) of the period: ";
    char slash; // To read the '/' character
    cin >> period_start_month >> slash >> period_start_day >> period_end_month >> slash >> period_end_day;

    // Collect hours worked for each day in the period
    cout << "Enter the total hours worked for each day in the period:" << endl;

    // Loop over the range of days (this example does not check for valid days/months)
    for (int month = period_start_month; month <= period_end_month; ++month) {
        int start_day = (month == period_start_month) ? period_start_day : 1;
        int end_day = (month == period_end_month) ? period_end_day : 31; // Assuming 31 days for simplicity

        for (int day = start_day; day <= end_day; ++day) {
            double hours;
            cout << "Enter hours worked on " << month << "/" << day << ": ";
            cin >> hours;
            total_hours += hours; // Add to total hours
        }
    }

    // Get the hourly pay rate
    cout << "How much do you get paid per hour? ";
    cin >> rate;

    // Ask if there is a bonus
    char bonus_response;
    cout << "Did you receive a bonus? (y/n): ";
    cin >> bonus_response;

    // If there's a bonus, get the amount
    if (bonus_response == 'y' || bonus_response == 'Y') {
        cout << "Enter the bonus amount: ";
        cin >> bonus;
    }

    // Calculate the period pay including bonus
    pay = (total_hours * rate) + bonus;

    // Display the total hours worked and the period pay
    cout << fixed << setprecision(2); // Set precision for currency output
    cout << "Total hours worked from " << period_start_month << "/" << period_start_day
        << " to " << period_end_month << "/" << period_end_day
        << " is " << total_hours << " hours." << endl;

    cout << "Your earnings from " << period_start_month << "/" << period_start_day
        << " to " << period_end_month << "/" << period_end_day
        << " is $" << pay << endl;

    return 0;
}
