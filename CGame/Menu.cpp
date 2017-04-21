#include "Menu.h"

MenuStruct::MenuStruct()
{
		registered = false;
}

MenuStruct::MenuStruct(int size) {
	if (size > MENU_MAX_ELEMENTS)
		size = MENU_MAX_ELEMENTS;
	element = new MenuElement[size];
	currentSize = 0;
	registered = true;
}

void MenuStruct::AddElement(MenuElement element)
{
	if (this->registered)
	{
		if (this->currentSize < this->maxSize - 1)
			this->element[currentSize++] = element;
	}
}