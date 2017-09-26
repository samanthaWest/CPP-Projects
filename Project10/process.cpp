/* Workshop 1 :: From One Translation Unit to Another
Filename: process.cpp
Samantha West (128111168)
2017/09/06
Implementing aspects of linkage, storage duration, namespaces,
guards and operating system interfaces.
*/
#include "process.h"
#include "cstring.h"

void process(char* s)
{
    w1::Cstring cs(s);
    std::cout << cs << "\n";
}