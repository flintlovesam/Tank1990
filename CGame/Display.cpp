#include "Display.h"

void displayMenu(ALLEGRO_DISPLAY ** display, ALLEGRO_FONT **font)
{
	al_clear_to_color(al_map_rgb(DISPLAY_BACKGROUND));
	al_draw_text(*font, al_map_rgb(COLOR_WHITE), DISPLAY_HEIGHT/2, DISPLAY_WIDTH/2, ALLEGRO_ALIGN_CENTER, "menu display!");
	al_flip_display();
	//waits for 5 sec
	al_rest(2.0);
}

void displayGame(ALLEGRO_DISPLAY ** display, ALLEGRO_FONT **font)
{
	al_clear_to_color(al_map_rgb(DISPLAY_BACKGROUND));
	al_draw_text(*font, al_map_rgb(COLOR_WHITE), DISPLAY_HEIGHT/2, DISPLAY_WIDTH/2, ALLEGRO_ALIGN_CENTER, "menu game!");
	al_flip_display();
	//waits for 5 sec
	al_rest(2.0);
}

void displaySettings(ALLEGRO_DISPLAY ** display, ALLEGRO_FONT **font)
{
	al_clear_to_color(al_map_rgb(DISPLAY_BACKGROUND));
	al_draw_text(*font, al_map_rgb(COLOR_WHITE), DISPLAY_HEIGHT/2, DISPLAY_WIDTH/2, ALLEGRO_ALIGN_CENTER, "menu settings!");
	al_flip_display();
	//waits for 5 sec
	al_rest(2.0);
}

void displayGameEditor(ALLEGRO_DISPLAY ** display, ALLEGRO_FONT **font)
{
	al_clear_to_color(al_map_rgb(DISPLAY_BACKGROUND));
	al_draw_text(*font, al_map_rgb(COLOR_WHITE), DISPLAY_HEIGHT/2, DISPLAY_WIDTH/2, ALLEGRO_ALIGN_CENTER, "menu gamededitro!");
	al_flip_display();
	//waits for 5 sec
	al_rest(2.0);
}
