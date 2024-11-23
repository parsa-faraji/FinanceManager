#include "Account.hpp"
#include <stdexcept>

// default constructor: initializes account number to 0 and balance to 0.0
Account::Account() : accountNumber(0), balance(0.0) {}

// parameterized constructor: initializes account number and balance with given values
Account::Account(long long accountNumber, double balance)
    : accountNumber(accountNumber), balance(balance) {}
