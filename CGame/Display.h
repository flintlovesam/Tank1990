#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "Colors.h"
#include "Utils.h"
#define DISPLAY_BACKGROUND 0,0,0
#define DISPLAY_HEIGHT 800
#define DISPLAY_WIDTH 600
#define FPS 30

typedef enum SCREEN_NAME;
enum SCREEN_NAME
{
	SCREEN_MENU,
	SCREEN_SETTINGS,
	SCREEN_GAME,
	SCREEN_GAMEEDITOR
};

void displayLoop(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *eventQueue);
void displayMenu(ALLEGRO_DISPLAY * display, ALLEGRO_FONT *font);
void displayGame(ALLEGRO_DISPLAY * display, ALLEGRO_FONT *font);
void displaySettings(ALLEGRO_DISPLAY * display, ALLEGRO_FONT *font);
void displayGameEditor(ALLEGRO_DISPLAY * display, ALLEGRO_FONT *font);
void changeBackgroundColor(unsigned char r, unsigned char g, unsigned char b);
void changeBackgroundColor(ALLEGRO_COLOR color);
ALLEGRO_COLOR getBackgroundColor();