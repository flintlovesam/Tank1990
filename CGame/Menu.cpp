#include "Menu.h"

MenuStruct::MenuStruct()
{
	maxSize = MENU_MAX_ELEMENTS;
	registered = false;
	menuIterator = 0;
}

MenuStruct::MenuStruct(int size) {
	if (size > MENU_MAX_ELEMENTS)
		size = MENU_MAX_ELEMENTS;
	maxSize = MENU_MAX_ELEMENTS;
	element = new MenuElement[size];
	currentSize = 0;
	registered = true;
	menuIterator = 0;
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

void MenuStruct::setFont(ALLEGRO_FONT * font)
{
	this->font = font;
}

unsigned int MenuStruct::CalculateTopMargin()
{
	return DISPLAY_HEIGHT*0.4 - this->currentSize*MENU_ELEMENT_HEIGHT / 2;
}

void MenuStruct::display(ALLEGRO_DISPLAY * display)
{
	if (this->menuIterator == 0)
		return;
	if (this->font == NULL)
	{
		logMessage("Font is not set", MESSAGE_ERROR);
		return;
	}
	changeBackgroundColor(COLOR_GRAY);
	for (int i = 0; i < this->currentSize; i++)
	{
		if(this->menuIterator == i)
			al_draw_text(font, al_map_rgb(COLOR_RED), this->leftMargin, this->topMargin + i*MENU_ELEMENT_HEIGHT, ALLEGRO_ALIGN_CENTER, this->element[i].title.c_str());
		else
			al_draw_text(font, al_map_rgb(COLOR_GREEN), this->leftMargin, this->topMargin + i*MENU_ELEMENT_HEIGHT, ALLEGRO_ALIGN_CENTER, this->element[i].title.c_str());

	}	
	
}

void MenuStruct::incrementMenuIterator()
{
	this->menuIterator++;
	this->menuIterator = this->menuIterator % this->currentSize;
}

void MenuStruct::decrementMenuIterator()
{
	this->menuIterator = (this->menuIterator + this->currentSize-1) % this->currentSize;
}


void MenuStruct::loop(ALLEGRO_DISPLAY * display, ALLEGRO_TIMER * timer, ALLEGRO_EVENT_QUEUE * eventQueue, ALLEGRO_EVENT * eventObject)
{

	switch (eventObject->type)
	{


	case ALLEGRO_EVENT_KEY_DOWN:
		switch (eventObject->keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			this->incrementMenuIterator();
			break;
		case ALLEGRO_KEY_DOWN:
			this->decrementMenuIterator();
			break;
		default:
			break;
		}

		break;

	default:
		break;
	}
	this->display(display);

}
