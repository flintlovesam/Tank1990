#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
//my headers
#include "Display.h"
#include "Utils.h"

//deklaracje wstêpuj¹ce
ALLEGRO_DISPLAY * initializeDisplay();
bool displayInitialized(ALLEGRO_DISPLAY **display);
void registerEvents(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER **timer, ALLEGRO_EVENT_QUEUE **eventQueue);
void installAllegroModules(ALLEGRO_DISPLAY *display);

void mainLoop(ALLEGRO_DISPLAY *, ALLEGRO_TIMER *, ALLEGRO_EVENT_QUEUE *, ALLEGRO_EVENT *);

void doSth(int **time)
{
	logMessage(std::to_string(**time));

	(**time)++;

	*time = NULL;
}

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	if (!displayInitialized(&display))
		exit(0);

	ALLEGRO_FONT* font = al_create_builtin_font();
	
	installAllegroModules(display);
	registerEvents(display, &timer, &eventQueue);

	//if there are more than 1 loop function register it
	initializeLoopFunctions(10);
	registerLoopFunction(&mainLoop);
	registerLoopFunction(&displayLoop);

	initializeMenus(display, font);
	displayScreen(SCREEN_SETTINGS, display, timer);
	ALLEGRO_EVENT eventObject;
	bool gameInProgress = true;

	while (gameInProgress)
	{
		GlobalLoop(display, timer, eventQueue, &eventObject);	//invokes all registered loops

		switch (eventObject.type)
		{

		case ALLEGRO_EVENT_TIMER:
			break;

		case ALLEGRO_EVENT_KEY_DOWN:
			switch (eventObject.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				gameInProgress = false;
			default:
				break;
			}

			break;

		default:
			break;
		}
	}

	al_destroy_timer(timer);
	al_destroy_event_queue(eventQueue);
	al_destroy_display(display);

	return 0;
}

ALLEGRO_DISPLAY * initializeDisplay()
{
	al_init();
	al_init_font_addon();
	return al_create_display(DISPLAY_HEIGHT, DISPLAY_WIDTH);
}

bool displayInitialized(ALLEGRO_DISPLAY **display)
{
	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL, "B³¹d podczas otwierania nowego okna!", NULL, 0);
		return false;
	}
	*display = initializeDisplay();
	if (!(*display)) {
		al_show_native_message_box(NULL, NULL, NULL, "B³¹d podczas rysowania okna", NULL, 0);
		return false;
	}
	return true;
}

//register event queue
void registerEvents(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER **timer, ALLEGRO_EVENT_QUEUE **eventQueue)
{
	*timer = al_create_timer(ALLEGRO_BPS_TO_SECS(FPS));

	*eventQueue = al_create_event_queue();

	al_register_event_source(*eventQueue, al_get_display_event_source(display));
	al_register_event_source(*eventQueue, al_get_timer_event_source(*timer));
	al_register_event_source(*eventQueue, al_get_keyboard_event_source());
	al_register_event_source(*eventQueue, al_get_mouse_event_source());

	al_start_timer(*timer);
}

void installAllegroModules(ALLEGRO_DISPLAY * display)
{
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_font_addon();

	al_hide_mouse_cursor(display);
	al_install_mouse();
}

void mainLoop(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT * eventObject)
{

}