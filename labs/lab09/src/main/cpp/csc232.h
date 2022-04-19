/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2019
 *
 * @file    Lab07.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros for use in Lab05.
 */

#ifndef CSC232_LAB07_H
#define CSC232_LAB07_H

#define FALSE 0
#define TRUE 1
#define EXECUTE_BLOCK FALSE
// TODO: When you create your pull request, make sure all of the following are set to TRUE
#define TEST_INVALID_TARGET_EXCEPTION TRUE
#define TEST_UNEXPECTED_ERROR_EXCEPTION TRUE
#define TEST_INVALID_RANGE_EXCEPTION TRUE

#include <stdexcept>
#include <string>

class TargetNotFoundException : public std::logic_error {
public:
    explicit TargetNotFoundException(const std::string &message = "")
            : std::logic_error("Target not found: " + message) {

    }
};

// TODO: Create a custom exception class named InvalidTargetException that extends std::invalid_argument
class InvalidTargetException : public std::invalid_argument {
public:
    explicit InvalidTargetException(const std::string &message = "")
            : std::invalid_argument("Invalid target: " + message) {

    }
};

// TODO: Create a custom exception class named UnexpectedErrorException that extends std::runtime_error
class UnexpectedErrorException : public std::runtime_error {
public:
    explicit UnexpectedErrorException(const std::string &message = "")
            : std::runtime_error("An unexpected error occurred during runtime while " + message) {

    }
};

// TODO: Create a custom exception class named InvalidRangeException that extends std::range_error
class InvalidRangeException : public std::range_error {
public:
    explicit InvalidRangeException(const std::string &message = "")
            : std::range_error("An invalid range was encountered while " + message) {

    }
};

void ThrowTargetNotFoundException(const std::string& target) {
    throw TargetNotFoundException(target);
}

void ThrowInvalidTargetException(const std::string& error) {
    // TODO: throw an InvalidTargetException with the given error message
    throw InvalidTargetException(error);
    // TODO: when done, change TEST_INVALID_TARGET_EXCEPTION to TRUE and commit your changes
}

void ThrowUnexpectedErrorException(const std::string& error) {
    // TODO: throw an UnexpectedErrorException with the given error message
    throw UnexpectedErrorException(error);
    // TODO: when done, change TEST_UNEXPECTED_ERROR_EXCEPTION to TRUE and commit your changes
}

void ThrowInvalidRangeException(const std::string& error) {
    // TODO: throw an InvalidRangeException with the given error message
    throw InvalidRangeException(error);
    // TODO: when done, change TEST_INVALID_RANGE_EXCEPTION to TRUE and commit your changes
}

#endif //CSC232_LAB07_H
