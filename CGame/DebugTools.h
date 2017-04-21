#pragma once
#pragma once
#include <string>
#include <iostream>
#define DEBUG 1
typedef enum MESSAGE_PRIORITY;

enum MESSAGE_PRIORITY
{
	MESSAGE_LOG,
	MESSAGE_WARNING,
	MESSAGE_ERROR
};

void logMessage(std::string message, MESSAGE_PRIORITY priority = MESSAGE_LOG);
