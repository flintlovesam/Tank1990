#pragma once
#pragma once
#include <string>
#include <iostream>
#define DEBUG 1
typedef enum MESSAGE_PRIORITY;

enum MESSAGE_PRIORITY
{
	LOG,
	WARNING,
	ERROR
};

void logMessage(std::string message, MESSAGE_PRIORITY priority = LOG);
