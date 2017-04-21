#pragma once
#include "Utils.h"
#include "Display.h"
#define MENU_MAX_ELEMENTS 20

typedef  void (*MenuElementDelegate)();

struct MenuElement
{
	std::string title;
	MenuElementDelegate function;
};
struct MenuStruct
{
	MenuElement *element;
	unsigned int maxSize;
	unsigned int currentSize;
	bool registered;
	MenuStruct();
	MenuStruct(int size);
	void AddElement(MenuElement elementToAdd);
};
