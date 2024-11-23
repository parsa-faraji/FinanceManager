//
//  Transaction.cpp
//  FinanceManagementApp
//
//  Created by Parsa Faraji on 11/15/24.
//

#include "Transaction.hpp"
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <iostream>

using namespace std;

// check if the transaction is valid
bool Transaction::isValidTransaction() const {
    return !transactionType.empty() && date.isValidDate() && time.isValidTime() && !category.empty();
}

// serialize transaction to csv format
string Transaction::toCSV() const {
    ostringstream oss;
    oss << transactionType << ","
        << setfill('0') << setw(2) << date.getMonth() << "/"
        << setfill('0') << setw(2) << date.getDay() << "/"
        << setw(4) << date.getYear() << "," // ensure year is always 4 digits
        << setfill('0') << setw(2) << time.getHour() << ":"
        << setfill('0') << setw(2) << time.getMinute()
        << setw(2) << time.getDayOrNight()
        << account.getAccountNumber() << ","
        << fixed << setprecision(2) << amount << ","
        << category << ","
        << (method == TransactionMethod::InStore ? "In-store" : "Online");
    return oss.str();
}
