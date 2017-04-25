#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <stdlib.h>
#include <ctime>
#include <queue>          // std::queue
#include "Utils.h"
#include "Display.h"

typedef struct Position;
typedef struct Opponent;
typedef struct Game;
typedef struct Player;
typedef struct BoardBrick;
typedef enum BRICK_TYPE;
typedef struct Brick;
typedef struct GameSettings;
typedef struct Missile;
typedef enum DIRECTION;

const unsigned short int BRICK_WALL_MAX_HITS = 3;

enum DIRECTION
{
	North,
	East,
	South, 
	West,
	DIRECTION_NONE
};

struct Position
{
	int x;
	int y;
};

struct Missile
{
	Position position;
	DIRECTION direction;
	Missile();
	static void updatePosition(Missile *missile);
};

enum BRICK_TYPE
{
	BRICK_WALL,
	BRICK_FOREST,
	BRICK_MONUMENT,
	BRICK_NONE
};

struct Brick
{
	BRICK_TYPE type;
	unsigned short int hitsCounter;
	Brick(BRICK_TYPE);
	inline void registerHit();
};

struct BoardBrick
{
	BoardBrick();
	Brick *bricks; //one-dimensional array, that has height*width cells
	unsigned int size;

	unsigned int height;
	unsigned int width;

	static void generate(Brick *);
	void destroyBrick(Position);
	void draw();

};

struct Player
{
	static const unsigned int height = 10;
	static const unsigned int width = 10;

	int lives;
	Position position;
	std::queue<Missile> launchedMissiles;
	DIRECTION movementDirection;
	void shoot();
	void refreshMissilesPosition();
};


struct Opponent
{
	int lives;
	Position position;
};

struct Game
{
	unsigned int height;
	unsigned int width;
	Opponent *oponents;
	Player player;
	
} game;


void initializeGame();
void gameLoop(ALLEGRO_DISPLAY *, ALLEGRO_TIMER *, ALLEGRO_EVENT_QUEUE *, ALLEGRO_EVENT * );
void destructGame();