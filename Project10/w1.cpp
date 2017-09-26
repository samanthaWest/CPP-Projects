/* Workshop 1 :: From One Translation Unit to Another
Filename: w1.cpp
Samantha West (128111168)
2017/09/06
Implementing aspects of linkage, storage duration, namespaces,
guards and operating system interfaces.
*/
#include <iostream>
#include <string.h>
#include "cstring.h"
#include "process.h"

int main(int argc, char* argv[]) {

    std::cout << "Command Line :";
    for (int arg = 0; arg < argc; arg++) {
        std::cout << " " << argv[arg];
    }

    std::cout << "\nMaximum number of characters stored: " << w1::MAX << "\n";

    for (int arg = 1; arg < argc; arg++) {
        process(argv[arg]);
    }

    std::cout << "\n\nCommand Line : " << argv[0] << "\n";

    if (argc == 1) {
        std::cout << "Insufficient number of arguments (min 1)" << "\n";
        return 1;
    }

    return 0;
}