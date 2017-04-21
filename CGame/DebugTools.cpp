#include "DebugTools.h"

void logMessage(std::string message, MESSAGE_PRIORITY priority)
{
	if (!DEBUG)
		return;

	switch (priority)
	{
	case MESSAGE_LOG:
		std::cout << "LOG:\t";
		break;
	case MESSAGE_WARNING:		
		std::cout << "WAR:\t";
		break;
	case MESSAGE_ERROR:
		std::cout << "ERR:\t";
		break;
	default:
		break;
	}

	std::cout << message << std::endl;
}
