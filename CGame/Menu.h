#pragma once
#include "allegro5\allegro.h"
#include "Utils.h"
#include "Display.h"

#define MENU_MAX_ELEMENTS 20
#define MENU_ELEMENT_HEIGHT 10
#define MENU_FONT_COLOR 255,255,0
#define MENU_FONT_SIZE 12
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
	unsigned int topMargin;
	unsigned int leftMargin;
	unsigned int currentElementFocus;
	bool registered;
	bool automaticLeftMargin;
	MenuStruct();
	MenuStruct(int size);
	void destroy();
	void AutomaticLeftMargin(bool automatic);
	void SetLeftMargin(unsigned int margin);
	void AddElement(MenuElement elementToAdd);
	unsigned int CalculateTopMargin();
	void display(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);
};
