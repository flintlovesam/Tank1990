#include "Menu.h"

MenuStruct::MenuStruct()
{
	maxSize = MENU_MAX_ELEMENTS;
	registered = false;
	currentElementFocus = 0;
}

MenuStruct::MenuStruct(int size) {
	if (size > MENU_MAX_ELEMENTS)
		size = MENU_MAX_ELEMENTS;
	maxSize = MENU_MAX_ELEMENTS;
	element = new MenuElement[size];
	currentSize = 0;
	registered = true;
	currentElementFocus = 0;
	this->topMargin = 0;
	this->leftMargin = 0;
}

void MenuStruct::destroy()
{
	delete[]element;
}

void MenuStruct::AutomaticLeftMargin(bool automatic)
{
	if (automatic)
		this->leftMargin = DISPLAY_WIDTH * 0.64;
}

void MenuStruct::SetLeftMargin(unsigned int margin)
{
	if (this->topMargin > DISPLAY_WIDTH)
	{
		this->topMargin = 0;
		logMessage("Left margins is too wide!", MESSAGE_WARNING);
	}
	this->leftMargin = margin;
}

void MenuStruct::AddElement(MenuElement elementToAdd)
{
	if (!registered)
		return;
	if (currentSize >= maxSize - 1)
		return;

	element[currentSize++] = elementToAdd;
	this->topMargin = this->CalculateTopMargin();
}

unsigned int MenuStruct::CalculateTopMargin()
{
	return DISPLAY_HEIGHT*0.4 - this->currentSize*MENU_ELEMENT_HEIGHT / 2;
}

void MenuStruct::display(ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font)
{
	changeBackgroundColor(COLOR_GRAY);
	for (int i = 0; i < this->currentSize; i++)
	{
		al_draw_text(font, al_map_rgb(MENU_FONT_COLOR), this->leftMargin, this->topMargin + i*MENU_ELEMENT_HEIGHT, ALLEGRO_ALIGN_CENTER, this->element[i].title.c_str());

	}
	al_flip_display();
	
}
