#include "Display.h"

ALLEGRO_COLOR currentBackgroundColor;
MenuStruct *menus;
MenuStruct *activeMenu;
bool menuSelectorEnabled = false;
//void displayMenu(ALLEGRO_DISPLAY * display, ALLEGRO_FONT *font)
//{
//	changeBackgroundColor(DISPLAY_BACKGROUND);
//	al_draw_text(font, al_map_rgb(COLOR_WHITE), DISPLAY_HEIGHT/2, DISPLAY_WIDTH/2, ALLEGRO_ALIGN_CENTER, "menu display!");
//
//	registerLoopFunction(&displayLoop);
//}

void displayScreen(SCREEN_NAME screen, ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *font)
{
	activeMenu = &menus[screen];
	menuSelectorEnabled = true;
	//switch (screen)
	//{
	//case SCREEN_MENU:
	//	activeMenu = &menus[SCREEN_GAME];
	//	break;

	//case SCREEN_SETTINGS:
	//	menus[SCREEN_SETTINGS].display(display);
	//	break;

	//default:
	//	break;
	//}
}


void changeBackgroundColor(unsigned char r, unsigned char g, unsigned char b)
{
	currentBackgroundColor = al_map_rgb(r,g,b);
	al_clear_to_color(currentBackgroundColor);
	al_flip_display();
}

void changeBackgroundColor(ALLEGRO_COLOR color)
{
	changeBackgroundColor(color.r, color.g, color.b);
}

void initializeMenus(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font)
{
	menus = new MenuStruct[20];
	MenuStruct *menu = new MenuStruct(10);

	menu->AutomaticLeftMargin(true);
	menu->setFont(font);

	MenuElement *element = new MenuElement();
	element->title = "Start new game";

	menu->AddElement(*element);
	element = new MenuElement();
	element->title = "Settings";
	element->function = &doSth;
	menu->AddElement(*element);
	element = new MenuElement();
	element->title = "Exit";
	menu->AddElement(*element);

	menus[SCREEN_MENU] = *menu;

	menu = new MenuStruct(5);
	menu->AutomaticLeftMargin(true);
	menu->setFont(font);
	element = new MenuElement();
	element->title = "Level";
	menu->AddElement(*element);
	element = new MenuElement();
	element->title = "Sth";
	menu->AddElement(*element);
	element = new MenuElement();
	element->title = "Back";
	menu->AddElement(*element);

	menus[SCREEN_SETTINGS] = *menu;


//	delete menu;

}

ALLEGRO_COLOR getBackgroundColor()
{
	return currentBackgroundColor;
}

void doSth()
{
	logMessage("diong sth");
}

void displayLoop(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT * eventObject)
{
	switch (eventObject->type)
	{

	case ALLEGRO_EVENT_TIMER:
		break;

	case ALLEGRO_EVENT_KEY_DOWN:
		switch (eventObject->keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			activeMenu->incrementMenuIterator();
			//logMessage("+ " + std::to_string(activeMenu->menuIterator));

			break;
		case ALLEGRO_KEY_DOWN:

			activeMenu->decrementMenuIterator();
		//	logMessage("- " + std::to_string(activeMenu->menuIterator));

			break;
		case ALLEGRO_KEY_ENTER:
			if (activeMenu->element[activeMenu->menuIterator].function != nullptr)
			{
				activeMenu->element[activeMenu->menuIterator].function();
			}
			break;
		default:
			break;
		}

		break;

	default:
		break;
	}

	if (menuSelectorEnabled && activeMenu != nullptr)
	{
		activeMenu->display(display);
	}


}
