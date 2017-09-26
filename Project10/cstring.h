/* Workshop 1 :: From One Translation Unit to Another
Filename: cstring.h
Samantha West (128111168)
2017/09/06
Implementing aspects of linkage, storage duration, namespaces,
guards and operating system interfaces.
*/
#pragma once
#include <iostream>

namespace w1 {

    const int MAX = 3;

    class Cstring {
        char str[MAX + 1]; // +1 FOR '\0'
    public:
        Cstring(char* s);
        void display(std::ostream& os);
    };

    std::ostream& operator<<(std::ostream& os, Cstring& s);

}