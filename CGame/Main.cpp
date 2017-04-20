#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

//my headers
#include "Display.h"


//deklaracje wstêpuj¹ce
ALLEGRO_DISPLAY * initializeDisplay();
bool displayInitialized(ALLEGRO_DISPLAY *display);
void registerEvents(ALLEGRO_DISPLAY *display,ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *eventQueue);
void installAllegroModules(ALLEGRO_DISPLAY *display);

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY* display = initializeDisplay();
	ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT* font = al_create_builtin_font();

	if (!displayInitialized(display))
		exit(0);

	installAllegroModules(display);
	registerEvents(display, timer, eventQueue);

	displayMenu(display, font);

	return 0;
}

ALLEGRO_DISPLAY * initializeDisplay()
{
	al_init();
	al_init_font_addon();
	return al_create_display(DISPLAY_HEIGHT, DISPLAY_WIDTH);
}

bool displayInitialized(ALLEGRO_DISPLAY *display)
{
	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL, "B³¹d podczas otwierania nowego okna!", NULL, 0);
		return false;
	}
	display = al_create_display(800, 600);
	if (!display) {
		al_show_native_message_box(NULL, NULL, NULL, "B³¹d podczas rysowania okna", NULL, 0);
		return false;
	}
	return true;
}

//register event queue
void registerEvents(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *eventQueue)
{
	float freq = 1 / FPS;
	timer =  al_create_timer(freq);
	
	eventQueue = al_create_event_queue();

	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_register_event_source(eventQueue, al_get_mouse_event_source());
	al_start_timer(timer);
}

void installAllegroModules(ALLEGRO_DISPLAY * display)
{
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_font_addon();

	al_hide_mouse_cursor(display);
	al_install_mouse();
}


