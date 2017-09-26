/* Workshop 1 :: From One Translation Unit to Another
Filename: cstring.cpp
Samantha West (128111168)
2017/09/06
Implementing aspects of linkage, storage duration, namespaces,
guards and operating system interfaces.
*/
#pragma warning(disable:4996)
#include <iostream>
#include "cstring.h"
#include "string.h"

namespace w1 {

    Cstring::Cstring(char* s)
    {
        bool valid = s[0] != '\0';
        if (valid) {
            strncpy(str, s, MAX);
            str[MAX] = '\0';
            // cout <<"     ...saved(" << str << ")\n";
        }
        else {
            str[0] = '\0';
        }
    }

    void Cstring::display(std::ostream& os) {
        os << str;
    }

    std::ostream& operator<<(std::ostream& os, Cstring& s)
    {
        static int count = 0;
        std::cout << count << " : ";
        s.display(os);
        count++;
        std::cout << "\n\n";
        return os;
    }

}