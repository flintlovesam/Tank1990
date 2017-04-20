#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "Colors.h"
#define DISPLAY_BACKGROUND 0,0,0
#define DISPLAY_HEIGHT 800
#define DISPLAY_WIDTH 600
#define FPS 30

void displayMenu(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);
void displayGame(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);
void displaySettings(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);
void displayGameEditor(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);