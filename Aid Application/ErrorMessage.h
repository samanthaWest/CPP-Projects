/* Milestone 5: AMAPRODUCT & AMAPERISHABLE CLASSES
Student: Samantha West (128111168)
Filename: ErrorMessage.h
Date: 2017/07/20
Description: Aid management releif app.
//////////////////////////////////////////////
*/
#ifndef ERROR_MESSAGE_H
#define ERROR_MESSAGE_H
using namespace std;

namespace sict {
    class ErrorMessage {
        char* message_;
    public:
        ErrorMessage();
        ErrorMessage(const char*);
        ErrorMessage(const ErrorMessage&) = delete;
        ErrorMessage& operator=(const ErrorMessage&) = delete;
        ErrorMessage& operator=(const char*);
        virtual ~ErrorMessage();
        void clear();
        bool isClear() const;
        void message(const char*);
        const char* message() const;
    };

    std::ostream& operator<<(std::ostream&, const ErrorMessage&);
}

#endif