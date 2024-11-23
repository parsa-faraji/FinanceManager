//
//  util.cpp
//  FinanceManagementApp
//
//  Created by Parsa Faraji on 11/22/24.
//

#include "util.hpp"
#include "Transaction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <memory> // for smart pointers

using namespace std;

// define namespace
namespace FinanceManagement {

// define the categories list
const vector<string> categories = {
    "Food", "Housing", "Transport", "Healthcare",
    "Entertainment", "Education", "Savings", "Income",
    "Debt", "Other"
};


// auxilliary function to validate date mm/dd/yyyy
bool isValidDate(const string& dateStr) {
    if (dateStr.size() != 10 || dateStr[2] != '/' || dateStr[5] != '/') return false;

    try {
        int month = stoi(dateStr.substr(0, 2));
        int day = stoi(dateStr.substr(3, 2));
        int year = stoi(dateStr.substr(6));

        if (month < 1 || month > 12 || day < 1 || year < 1) return false;

        static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int maxDays = daysInMonth[month - 1];

        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            maxDays = 29;
        }
        return (day <= maxDays);
    } catch (const invalid_argument& e) {
        cerr << "Error parsing date: " << dateStr << " (" << e.what() << ")" << endl;
        return false;
    } catch (const out_of_range& e) {
        cerr << "Date out of range: " << dateStr << " (" << e.what() << ")" << endl;
        return false;
    }
}

