#include <iostream>

#include "interface.h"

#include <string.h>
const char* GetStandard();


void PrintMenu();

int main()
{   
    std::cout << "BEGIN:::::::" << Interface::Generate() << "::::::END" << std::endl;    
}
