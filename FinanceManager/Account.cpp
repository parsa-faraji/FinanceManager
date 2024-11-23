#include "Account.hpp"
#include <stdexcept>

// default constructor: initializes account number to 0 and balance to 0.0
Account::Account() : accountNumber(0), balance(0.0) {}

// parameterized constructor: initializes account number and balance with given values
Account::Account(long long accountNumber, double balance)
    : accountNumber(accountNumber), balance(balance) {}


// sets the account number with validation to ensure it is non-negative
void Account::setAccountNumber(long long newAccountNumber) {
    // a bank account number should have at least 8 digits
    if (newAccountNumber < 0 || (std::to_string(newAccountNumber).length() < 8)) {
        throw std::invalid_argument("Account number cannot be negative.");
    }
    accountNumber = newAccountNumber;
}

// sets the account balance with validation to ensure it is non-negative
void Account::setBalance(double newBalance) {
    if (newBalance < 0) {
        throw std::invalid_argument("Balance cannot be negative.");
    }
    balance = newBalance;
}
