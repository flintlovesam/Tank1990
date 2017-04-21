#pragma once
#include "DebugTools.h"
typedef void(*LoopFunction)();

struct LoopFunctionsStruct
{
	LoopFunction * functionsArray;
	unsigned int maxSize;
	unsigned int currentSize;
	unsigned int iterator;
	bool registrated = false;
};

void initializeLoopFunctions(int maxSize);
void registerLoopFunction(void (*function)());
LoopFunction * getLoopFunctions(int &size);
void GlobalLoop();