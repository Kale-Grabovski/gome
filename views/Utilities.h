#pragma once
#define RUNNING_WINDOWS
#include <iostream>
#include <string>
#include <algorithm>

namespace Utils {
	#include <unistd.h>
	inline std::string GetWorkingDirectory(){
		char cwd[1024];
		if(getcwd(cwd, sizeof(cwd)) != nullptr){
			return std::string(cwd) + std::string("/");
		}
		return "";
	}
}