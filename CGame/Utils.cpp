#include "Utils.h"
LoopFunctionsStruct loopFunctions;


void initializeLoopFunctions(int maxSize)
{
	loopFunctions.functionsArray = new LoopFunction[maxSize];
	loopFunctions.maxSize = maxSize;
	loopFunctions.currentSize = 0;
	loopFunctions.iterator = 0;
	loopFunctions.registrated = true;
}

void extern registerLoopFunction(LoopFunction function)
{
	if (!loopFunctions.registrated)
	{
		logMessage("Loops not registrated!", MESSAGE_ERROR);
		return;
	}
	if (loopFunctions.currentSize == loopFunctions.maxSize - 1)
	{
		logMessage("Loops not registrated!", MESSAGE_ERROR);
		return;
	}
	loopFunctions.functionsArray[loopFunctions.iterator++] = function;
	loopFunctions.currentSize++;
}

void registerLoopFunction(LoopFunction * function)
{
	if (!loopFunctions.registrated)
	{
		logMessage("Loops not registrated!", MESSAGE_ERROR);
		return;
	}
	if (loopFunctions.currentSize == loopFunctions.maxSize - 1)
	{
		logMessage("Loops not registrated!", MESSAGE_ERROR);
		return;
	}
	loopFunctions.functionsArray[loopFunctions.iterator++] = *function;
	loopFunctions.currentSize++;
}

LoopFunction * getLoopFunctions(int &size)
{
	return loopFunctions.functionsArray;
}

void GlobalLoop(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT * eventObject)
{
	al_wait_for_event(eventQueue, eventObject);

	if (!loopFunctions.registrated)
	{
		logMessage("Loops not registrated!", MESSAGE_ERROR);
		return;
	}
	for (int i = 0; i < loopFunctions.currentSize; i++)
	{
		loopFunctions.functionsArray[i](display, timer, eventQueue, eventObject);
	}
	al_flip_display();
}

