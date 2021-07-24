#include <iostream>

#include "interface.h"

#include <string.h>
const char* GetStandard();


void PrintMenu();

int main()
{   
    Interface::PushIncludeDir("/home/dev/");
    Interface::PushIncludeDir("/home/dev/");
    Interface::PushIncludeDir("/home/dev/");
    Interface::PushIncludeDir("/home/dev/");

    Interface::PrintInclude();
}

void PrintMenu()
{

    std::cout << " 1. Add source directories."               << std::endl;
 
    std::cout << " 2. Set C++ standard. Current standard: "
              << Interface::GetStandard()                    << std::endl;

    std::cout << " 3. Add include directories"               << std::endl;
    std::cout << " 4. Add library directories"               << std::endl;
    std::cout << " 5. Add library links"                     << std::endl;

    std::cout << " 6. Set debug flag. Current flag: "
              << Interface::GetDebugFlag()                   << std::endl;

    std::cout << " 7. Add defines"                           << std::endl;
    std::cout << " 8. Set output directory"                  << std::endl;
    std::cout << " 9. Set output filename"                   << std::endl;
    std::cout << "10. Generate"                              << std::endl;
}

