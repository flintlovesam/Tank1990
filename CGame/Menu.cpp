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

void AddMenuElement(MenuStruct & menuStructure, MenuElement elementToAdd)
{
	if (menuStructure.registered)
	{
		if (menuStructure.currentSize < menuStructure.maxSize - 1)
			menuStructure.element[menuStructure.currentSize++] = elementToAdd;
	}
}
