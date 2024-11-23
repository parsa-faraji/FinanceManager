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
