#pragma once

#ifdef FZ_PLATFORM_VALIDATE
	#ifndef NOMINMAX
	// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
	#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>
#include <functional>
#include <algorithm>
#include <utility>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#ifdef FZ_PLATFORM_VALIDATE 
	#include <Windows.h>
#endif   
