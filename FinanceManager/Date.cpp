#include "Date.hpp"
#include <stdexcept>

// default constructor: initializes the date to 0/0/0
Date::Date() : year(0), month(0), day(0) {}

// parameterized constructor: initializes the date with provided year, month, and day values
Date::Date(short int year, short int month, short int day)
    : year(year), month(month), day(day) {}

