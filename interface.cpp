#include "interface.h"

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string>    Interface::s_SourceDirs;        //  1
Standard                    Interface::s_Standard;          //  2
std::vector<std::string>    Interface::s_IncludeDirs;       //  3
std::vector<std::string>    Interface::s_LibDirs;           //  4
std::vector<std::string>    Interface::s_LibLinks;          //  5
bool                        Interface::s_DebugFlag;         //  6
std::vector<std::string>    Interface::s_Defines;           //  7
std::string                 Interface::s_OutputDir;         //  8
std::string                 Interface::s_OutputName;        //  9

const std::vector<std::string>& Interface::GetSourceDirs()  { return s_SourceDirs; }    // 1
const std::vector<std::string>& Interface::GetIncludeDirs() { return s_IncludeDirs; }   // 3
const std::vector<std::string>& Interface::GetLibDirs()     { return s_LibDirs; }       // 4
const std::vector<std::string>& Interface::GetLibLinks()    { return s_LibLinks; }      // 5
const std::vector<std::string>& Interface::GetDefines()     { return s_Defines; }       // 7
const bool                      Interface::GetDebugFlag()   { return s_DebugFlag; }     // 6
const std::string&              Interface::GetOutputDir()   { return s_OutputDir; }     // 8
const std::string&              Interface::GetOutputName()  { return s_OutputName; }    // 9

const std::string               Interface::GetStandard()                                // 6
{
    switch (s_Standard)
    {
    case Standard::CPP98:
        return "C++98";
        break;
    case Standard::CPP03:
        return "C++03";
        break;
    case Standard::CPP11:
        return "C++11";
        break;
    case Standard::CPP14:
        return "C++14";
        break;
    case Standard::CPP17:
        return "C++17";
        break;
    case Standard::CPP20:
        return "C++20";
        break;
    case Standard::CPP23:
        return "C++23";
        break;
    default:
        return "C++11";
        break;
    }

}

void Interface::PushTo(std::vector<std::string>& list, const std::string& value)
{
    bool found = std::find(list.begin(), list.end(), value) != list.end();
    if(!found)
    {
        list.push_back(value);
    }
}

void Interface::PushSourceDir(const std::string& dir)  { PushTo(s_SourceDirs, dir);  }
void Interface::PushIncludeDir(const std::string& dir) { PushTo(s_IncludeDirs, dir); }
void Interface::PushLibDir(const std::string& dir)     { PushTo(s_LibDirs, dir);     }
void Interface::PushLibLink(const std::string& lib)    { PushTo(s_LibLinks, lib);    }
void Interface::PushDefine(const std::string& name)    { PushTo(s_Defines, name);    }

void Interface::SetStandard(Standard Standard)   { s_Standard = Standard; }
void Interface::SetDebugFlag(bool flag)          { s_DebugFlag = flag; }
void Interface::SetOutputDir(std::string& dir)   { s_OutputDir = dir;  }
void Interface::SetOutputName(std::string& name) { s_OutputName = name; }

void Interface::PrintList(const std::vector<std::string>& list)
{
    for(auto& value : list)
    {
        std::cout << value << std::endl;
    }
}

void Interface::PrintSourceDir()  { PrintList(GetSourceDirs());  }
void Interface::PrintIncludeDir() { PrintList(GetIncludeDirs()); }
void Interface::PrintLibDir()     { PrintList(GetLibDirs());     }
void Interface::PrintLibLink()    { PrintList(GetLibLinks());    }
void Interface::PrintDefine()     { PrintList(GetDefines());     }