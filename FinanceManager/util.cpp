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
