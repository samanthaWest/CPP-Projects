#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ErrorMessage.h"

namespace sict {

    // Default Constructor
    ErrorMessage::ErrorMessage() {
        message_ = nullptr;
    }

    // Constructor (1 Parameter)
    ErrorMessage::ErrorMessage(const char* errorMessage) {
        message_ = nullptr;
        message(errorMessage);
    }


    ErrorMessage& ErrorMessage::operator=(const char* errormessage) {
        clear();
        message(errormessage);
        return *this;
    }

    ErrorMessage::~ErrorMessage() {
        delete[] message_;
    }

    void ErrorMessage::clear() {
        delete[] message_;
        message_ = nullptr;
    }

    bool ErrorMessage::isClear() const {
        bool valid = message_ == nullptr;
        return valid;
    }

    void ErrorMessage::message(const char* value) {
        delete[] message_;
        if (value != nullptr) {
            int newLength = strlen(value);
            message_ = new char[newLength + 1];
            strncpy(message_, value, newLength + 1);
        }
    }

    const char* ErrorMessage::message() const {
        return message_;
    }

    std::ostream& operator<<(ostream& os, const ErrorMessage& Er) {
        if (Er.isClear() == false) {
            os << Er.message();
        }
        return os;
    }

}