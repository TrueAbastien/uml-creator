#pragma once
#include <string>

// Clear Command
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

// Type Definitions
#define NOTIFICATION_DATA std::string
