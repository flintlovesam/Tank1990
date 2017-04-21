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

void MenuStruct::AddElement(MenuElement elementToAdd)
{
	if (registered)
	{
		if (currentSize < maxSize - 1)
			element[currentSize++] = elementToAdd;
	}
}
