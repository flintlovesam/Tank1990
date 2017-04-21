#include "Display.h"

ALLEGRO_COLOR currentBackgroundColor;


void displayMenu(ALLEGRO_DISPLAY * display, ALLEGRO_FONT *font)
{
	changeBackgroundColor(DISPLAY_BACKGROUND);
	al_draw_text(font, al_map_rgb(COLOR_WHITE), DISPLAY_HEIGHT/2, DISPLAY_WIDTH/2, ALLEGRO_ALIGN_CENTER, "menu display!");
	al_flip_display();
	registerLoopFunction(&displayLoop);
	//waits for 5 sec
	//al_rest(2.0);
}

void displayGame(ALLEGRO_DISPLAY * display, ALLEGRO_FONT *font)
{
	changeBackgroundColor(DISPLAY_BACKGROUND);
	al_draw_text(font, al_map_rgb(COLOR_WHITE), DISPLAY_HEIGHT/2, DISPLAY_WIDTH/2, ALLEGRO_ALIGN_CENTER, "menu game!");
	al_flip_display();
	//waits for 5 sec
	al_rest(2.0);
}

void displayLoop()
{
	logMessage("Drugi loop", MESSAGE_WARNING);
}

void displaySettings(ALLEGRO_DISPLAY * display, ALLEGRO_FONT *font)
{
	changeBackgroundColor(DISPLAY_BACKGROUND);
	al_draw_text(font, al_map_rgb(COLOR_WHITE), DISPLAY_HEIGHT/2, DISPLAY_WIDTH/2, ALLEGRO_ALIGN_CENTER, "menu settings!");
	al_flip_display();
	//waits for 5 sec
	al_rest(2.0);
}

void displayGameEditor(ALLEGRO_DISPLAY * display, ALLEGRO_FONT *font)
{
	changeBackgroundColor(DISPLAY_BACKGROUND);
	al_draw_text(font, al_map_rgb(COLOR_WHITE), DISPLAY_HEIGHT/2, DISPLAY_WIDTH/2, ALLEGRO_ALIGN_CENTER, "menu gamededitro!");
	al_flip_display();
	//waits for 5 sec
	al_rest(2.0);
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

ALLEGRO_COLOR getBackgroundColor()
{
	return currentBackgroundColor;
}
