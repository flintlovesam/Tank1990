#include "DebugTools.h"

void logMessage(std::string message, MESSAGE_PRIORITY priority)
{
	if (!DEBUG)
		return;

	switch (priority)
	{
	case LOG:
		std::cout << "LOG:\t";
		break;
	case WARNING:		
		std::cout << "WAR:\t";
		break;
	case ERROR:
		std::cout << "ERR:\t";
		break;
	default:
		break;
	}

	std::cout << message << std::endl;
}
