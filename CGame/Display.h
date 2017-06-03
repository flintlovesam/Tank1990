#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "Colors.h"
#include "Utils.h"
#include "Menu.h"
#define DISPLAY_BACKGROUND 0,255,0
#define DISPLAY_HEIGHT 800
#define DISPLAY_WIDTH 600
#define FPS 30

typedef enum SCREEN_NAME;
enum SCREEN_NAME
{
	SCREEN_MENU = 0,
	SCREEN_SETTINGS = 1,
	SCREEN_GAME = 2,
	SCREEN_GAMEEDITOR = 3
};

void displayLoop(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT * eventObject);
void displayScreen(SCREEN_NAME, ALLEGRO_DISPLAY *, ALLEGRO_TIMER * , ALLEGRO_FONT *);
void changeBackgroundColor(unsigned char r, unsigned char g, unsigned char b);
void changeBackgroundColor(ALLEGRO_COLOR color);
void initializeMenus(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);
ALLEGRO_COLOR getBackgroundColor();
//displaying adequete screens
void DisplaySettings();
void DisplayGame();