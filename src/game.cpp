/* Game loop for ApoCLI */

#include "debug.h"

#ifdef DEBUG
#include <iostream> // DEBUG PURPOSES ONLY!!!
#endif

// #include <unistd.h>

#include "game.h"
#include "input.h"
#include "signal.h"
#include "tools.h"

void Game::loadDisplay(Display * nDisplay)
{
	display = nDisplay;
}

void Game::loadWorld(World * nWorld)
{
	world = nWorld;
}

void Game::makeActor()
{
	actor = new Actor("Bob", "Joe");
}

Game::Game(Display * nDisplay)
{
	bool	isRunning = false;
	
	int	xDimension,	yDimension,
		xCenter,	yCenter,
		curX,		curY,
		lstX,		lstY,
		rosX,		rosY;

	loadDisplay(nDisplay);
	makeActor();
	world = new World(WORLD_SMALL__);

	xDimension = world->getDimensionX();
	yDimension = world->getDimensionY();

	display->passNameFirst(actor->getNameFirst());
	display->passNameLast(actor->getNameLast());
	display->passHealth(actor->getHealth());
	display->passStrength(actor->getStrength());

	xCenter = Tools::Location::rosX(0, xDimension);
	yCenter = Tools::Location::rosY(0, yDimension);

	actor->setLocationX(xCenter); 
	actor->setLocationY(yCenter);

	curX = actor->getLocationX(); 
	curY = actor->getLocationY();

	lstX = curX;
	lstY = curY;

	rosX = Tools::Location::rosX(0, xDimension);
	rosY = Tools::Location::rosY(0, yDimension);

	isRunning = true;

	while (isRunning) {
		curX = actor->getLocationX();
		curY = actor->getLocationY();

		world->remActor(lstX, lstY);
		world->setActor(actor, curX, curY);

		rosX = Tools::Location::getX(curX, xDimension);
		rosY = Tools::Location::getY(curY, yDimension);

		display->passHealth(actor->getHealth());
		display->passStrength(actor->getStrength());
		display->passLocX(rosX);
		display->passLocY(rosY);

		lstX = curX;
		lstY = curY;

		for (int yCount = 0; yCount <= yDimension - 1; yCount++) {
			for (int xCount = 0; xCount <= xDimension - 1; xCount++) {
				display->doSendTile(world->getTile(xCount, yCount));
			}
		}
		
		display->doPrint();
		input(actor);
		isRunning = isKill("game");
	}
}
