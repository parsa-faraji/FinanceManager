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


// auxilliary function to validate time hh:mm
bool isValidTime(const string& timeStr) {
    if (timeStr.size() != 5 || timeStr[2] != ':') return false;

    try {
        int hour = stoi(timeStr.substr(0, 2));
        int minute = stoi(timeStr.substr(3, 2));
        return hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59;
    } catch (const invalid_argument& e) {
        cerr << "Error parsing time: " << timeStr << " (" << e.what() << ")" << endl;
        return false;
    } catch (const out_of_range& e) {
        cerr << "Time out of range: " << timeStr << " (" << e.what() << ")" << endl;
        return false;
    }
}

// generic function to handle errors
template <typename T>
T getValidatedInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please try again." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    return value;
}

// processFile function
void processFile() {
    fstream fout("/Users/parsafaraji/Desktop/Project2-FinanceManagementApp/Project2-FinanceManagementApp/data.txt", ios::out | ios::app);
    if (!fout.is_open()) {
        cerr << "Error opening file. Please check file directory or permissions." << endl;
        return;
    }

    while (true) {
        cout << "\n===============================================\n";
        cout << "Welcome to Finance Management App\n";
        cout << "===============================================\n";
        cout << "1) Record a transaction\n2) View monthly summary\n3) Exit\n";
        cout << "===============================================\n";

        int choice = getValidatedInput<int>("Enter your choice: ");
        switch (choice) {
            case 1:
                recordTransaction(fout);
                break;
            case 2: {
                int month = getValidatedInput<int>("Enter the month (1-12) for the summary: ");
                if (month < 1 || month > 12) {
                    cerr << "Invalid month. Please enter a value between 1 and 12." << endl;
                    break;
                }
                vector<Transaction> transactions = readTransactionsFromFile("/Users/parsafaraji/Desktop/Project2-FinanceManagementApp/Project2-FinanceManagementApp/data.txt");
                if (!transactions.empty()) {
                    displayMonthlySpendingPattern(transactions, month);
                } else {
                    cerr << "No transactions found." << endl;
                }
                break;
            }
            case 3:
                fout.close();
                return;
            default:
                cerr << "Invalid choice. Please try again." << endl;
        }
    }
}
