#pragma once

#ifdef FZ_PLATFORM_VALIDATE
	#ifdef FZ_BUILD_DLL
		#define FIZZION_API __declspec (dllexport)
	#else 
		#define FIZZION_API __declspec (dllimport)
	#endif
#else
	#error Fizzion only supports Windows! 
#endif

// Loading inbuild libraries
#include <string>
#include <functional>