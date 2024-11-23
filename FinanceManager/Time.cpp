#include "Time.hpp"
#include <stdexcept>

// default constructor
Time::Time() : hour(0), minute(0) {}

// parameterized constructor
Time::Time(short int hour, short int minute) : hour(hour), minute(minute) {
    if (!isValidTime()) {
        throw std::invalid_argument("Invalid time provided.");
    }
}
