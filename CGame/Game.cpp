#include "Game.h"

ALLEGRO_DISPLAY *displayArg;
ALLEGRO_FONT *fontArg;
GameObj game;
void initializeGame()
{
	game.height = DISPLAY_HEIGHT;
	game.width = DISPLAY_WIDTH;
	game.activated = false;
}

void gameLoop(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *eventQueue, ALLEGRO_EVENT * eventObject)
{
	if (!game.activated)
		return;
	switch (eventObject->type)
	{
	case ALLEGRO_EVENT_KEY_DOWN:
		switch (eventObject->keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			game.player.position.y++;
			game.player.movementDirection = North;
			logMessage("going up!");
			break;
		case ALLEGRO_KEY_DOWN:
			game.player.position.y--;
			game.player.movementDirection = South;

			break;
		case ALLEGRO_KEY_LEFT:
			game.player.position.x--;
			game.player.movementDirection = West;

			break;
		case ALLEGRO_KEY_RIGHT:
			game.player.position.x++;
			game.player.movementDirection = East;

			break;
		case ALLEGRO_KEY_SPACE:
			game.player.shoot();
			break;


		default:
			break;
		}
		break;
	default:
		break;
	}
}

void destructGame()
{
	;
}

BoardBrick::BoardBrick()
{
	this->height = game.height;
	this->width = game.width;

	this->size = this->height*this->width;
}

void BoardBrick::generate(Brick *)
{
	;
}

void BoardBrick::destroyBrick(Position position)
{
	if (position.x*position.y > this->size)
		return;

	if (this->bricks[position.x*position.y].type != BRICK_NONE)
		this->bricks[position.x * position.y].type = BRICK_NONE;

}

void BoardBrick::draw()
{
	if (height <= 0 || height >= game.height)
	{
		logMessage("Check whether board's height was initialized properly!", MESSAGE_ERROR);
		return;
	}
	if (width <= 0 || width >= game.width)
	{
		logMessage("Check whether board's width was initialized properly!", MESSAGE_ERROR);
	}
	return;

	for (int y = 0; y < this->height; y++)
	{
		for (int x = 0; x < this->width; x++)
		{
			;
		}
	}
}

Brick::Brick(BRICK_TYPE brick_type)
{
	this->type = brick_type;
	hitsCounter = 0;
}

inline void Brick::registerHit()
{
	++this->hitsCounter;
}


void Player::shoot()
{
	Missile missile;
	missile.direction = this->movementDirection;
	missile.position = this->position;

	//adjust position to be out of the object
	switch (this->movementDirection)
	{
	case North:
		missile.position.y += Player::height / 2;
		break;
	case East:
		missile.position.x += Player::width / 2;
		break;
	case South:
		missile.position.y -= Player::height / 2;
		break;
	case West:
		missile.position.x -= Player::width / 2;
		break;
	case DIRECTION_NONE:
		break;
	default:
		break;
	}

	this->launchedMissiles;
}

void Player::refreshMissilesPosition()
{
	int a = launchedMissiles.size();
	for (int i = 0; i < a; i++)
	{
		Missile missile = launchedMissiles.front();
		launchedMissiles.pop();
		Missile::updatePosition(&missile);
		launchedMissiles.push(missile);

	}
}

Missile::Missile()
{
	direction = North;
}

void Missile::updatePosition(Missile *missile)
{
	switch (missile->direction)
	{
	case North:
		missile->position.y++;
		break;
	case East:
		missile->position.x++;
		break;
	case South:
		missile->position.y--;
		break;
	case West:
		missile->position.x--;
		break;
	case DIRECTION_NONE:
		break;
	default:
		break;
	}
}
