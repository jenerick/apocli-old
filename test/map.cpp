#include <iostream>
#include <string>
// #include <unistd.h>

#include "../src/tile.h"
#include "../src/tools.h"

#define TILES_X 21
#define TILES_Y 11

int main(int argc, char** argv)
{
	const int tileX = TILES_X;
	const int tileY = TILES_Y;

	Actor * actor;
	Tile * tile[tileX][tileY];

	for (int countY = 0; countY <= tileY - 1; countY++) {
		for (int countX = 0; countX <= tileX -1; countX++) {
			tile[countX][countY] = new Tile(countX, countY);
		}
	}

	std::string sFirst;
	std::string sLast;

	const char * nFirst;
	const char * nLast;

	bool isChoosingFirst = true;

	while (isChoosingFirst) {
		std::cout << "What is your first name?" << std::endl;
		std::cin >> sFirst;
		if (sFirst.size() >= 10) {
			std::cout << "Name is too long!" << std::endl;
			// sleep(1);
		} else {
			isChoosingFirst = false;
		}
	}

	std::cout << "What is your last name?" << std::endl;
	std::cin >> sLast;

	nFirst = sFirst.c_str();
	nLast = sLast.c_str();

	actor = new Actor(nFirst, nLast);

	const int centerX = Tools::Location::rosX(0, tileX);
	const int centerY = Tools::Location::rosY(0, tileY);

	actor->setLocationX(centerX); actor->setLocationY(centerY);

	bool isRunning = true;
	char input;

	int lastLocationX = actor->getLocationX(),
	    lastLocationY = actor->getLocationY(),
	    currLocationX = lastLocationX,
	    currLocationY = lastLocationY;

	while (isRunning) {
		tile[lastLocationX][lastLocationY]->remActor();
		tile[currLocationX][currLocationY]->setActor(actor);
		lastLocationX = actor->getLocationX();
		lastLocationY = actor->getLocationY();

		for (int yCount = 0; yCount <= tileY - 1; yCount++) {
			for (int xCount = 0; xCount <= tileX - 1; xCount++) {
				std::cout << tile[xCount][yCount]->getPrintChar() << " ";
				if (xCount == tileX - 1) {
					std::cout << "| ";
					switch (yCount) {
						case 1:
							std::cout << "Name: " << actor->getNameFirst() << " " << actor->getNameLast();
							break;
						case 2:
							std::cout << "Health: " << actor->getHealth();
							break;
						case 4:
							std::cout << "Identifier: " << actor->getName();
							break;
						default:
							break;
					}
				}
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;
		// sleep(1);
	}

	return 0;
}
