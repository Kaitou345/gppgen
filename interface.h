#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <string>

enum class Standard
{
	CPP98,
	CPP03,
	CPP11,
	CPP14,
	CPP17,
	CPP20,
	CPP23	
};

class Interface
{

public:
	Interface() = delete;
	Interface(const Interface& other) = delete;

	static const std::vector<std::string>&      GetSourceDirs();	// 1
	static const std::vector<std::string>& 	    GetIncludeDirs(); 	// 3
	static const std::vector<std::string>& 	    GetLibDirs();     	// 4
	static const std::vector<std::string>& 	    GetLibLinks();    	// 5
	static const std::vector<std::string>& 	    GetDefines();   	// 7
	static const bool 	    					GetDebugFlag();		// 6
	static const std::string&  					GetOutputDir();		// 8
	static const std::string&  					GetOutputName();	// 9
	static const std::string  					GetStandard();		// 2
	

	static void PushSourceDir(const std::string& dir);
	static void PushIncludeDir(const std::string& dir);
	static void PushLibDir(const std::string& dir);
	static void PushLibLink(const std::string& dir);
	static void PushDefine(const std::string& dir);

	static void SetStandard(Standard Standard);
	static void SetDebugFlag(bool flag);
	static void SetOutputDir(const std::string& dir);
	static void SetOutputName(const std::string& name);


	// Debug functions
	static void PrintList(const std::vector<std::string>& list);
	static void PrintSourceDir();
	static void PrintIncludeDir();
	static void PrintLibDir();
	static void PrintLibLink();
	static void PrintDefine();
	
	static std::string Generate();
private:
	static void PushTo(std::vector<std::string>& list, const std::string& value);
	static void AppendVector(std::vector<std::string>& list, std::string& value, const std::string& prefix = " ");

private:
	static std::vector<std::string> s_SourceDirs;          //  1
	
	/// Defaults to C++11
	static Standard                 s_Standard;            //  2
	
	static std::vector<std::string> s_IncludeDirs;         //  3
	static std::vector<std::string> s_LibDirs;             //  4
	static std::vector<std::string> s_LibLinks;            //  5

	/// defaults to release mode
	static bool                     s_DebugFlag;           //  6

	static std::vector<std::string> s_Defines;             //  7
	static std::string              s_OutputDir;           //  8
	static std::string              s_OutputName;          //  9

};

#endif