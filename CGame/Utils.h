#pragma once
#include "DebugTools.h"
#include "allegro5\allegro.h"
typedef void(*LoopFunction)(ALLEGRO_DISPLAY *, ALLEGRO_TIMER *, ALLEGRO_EVENT_QUEUE *);
struct LoopFunctionsStruct
{
	LoopFunction * functionsArray;
	unsigned int maxSize;
	unsigned int currentSize;
	unsigned int iterator;
	bool registrated = false;
};

void initializeLoopFunctions(int maxSize);
void registerLoopFunction(void (*function)(ALLEGRO_DISPLAY *, ALLEGRO_TIMER *, ALLEGRO_EVENT_QUEUE *));
LoopFunction * getLoopFunctions(int &size);
void GlobalLoop(ALLEGRO_DISPLAY *, ALLEGRO_TIMER *, ALLEGRO_EVENT_QUEUE *);