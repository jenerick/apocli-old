#include <iostream>

#include "debug.h"
#include "display.h"

Tile * Display::getTileBuffer(const int dX, const int dY) { return tileBuff[dX][dY]; };

const char Display::getTileCharacter(const int dX, const int dY)
{
	Tile *tempTile = getTileBuffer(dX, dY);

	if (!tempTile->getIsActor()) {
		switch (tempTile->getIdentifier()) {
			case TILE_DIRT:
			return '.';
			break;
			case TILE_GRASS:
			return '"';
			break;
			case TILE_STONE:
			return ',';
			break;
			default:
			return '!';
			break;
		}
	} else return '@';
}

int Display::getViewPortX()    { return viewX;    }
int Display::getViewPortY()    { return viewY;    }
int Display::getViewPosX()     { return viewPosX; }
int Display::getViewPosY()     { return viewPosY; }

Display::Display(const int dID, const int dX, const int dY)
{
	user_interface = new UI;
	setViewPortX(dX);
	setViewPortY(dY);
	setViewPosX(0);
	setViewPosY(0);
	lineCount = 0;
}

void Display::setViewPosX(const int nX)    { viewPosX = nX;    }
void Display::setViewPosY(const int nY)    { viewPosY = nY;    }
void Display::doBreak()                    { doSendLine("\n"); }

void Display::doSendTile(Tile *nTile)
{
	/* tileBuff[getViewPosX()][getViewPosY()] = nTile; */

	setTileBuffer(nTile, getViewPosX(), getViewPosY());

#ifdef DEBUG
	std::cout << "Recieved tile! " << getViewPosX() << ", " << getViewPosY() << std::endl;
#endif

	if (getViewPosY() < getViewPortY()) {
		if (getViewPosX() < getViewPortX() - 1) {
			setViewPosX(getViewPosX() + 1);
		} else {
			setViewPosX(0);
			setViewPosY(getViewPosY() + 1);
		}
	} else {
		setViewPosX(0);
		setViewPosY(0);
	}
}
void Display::doSendLine(const char * nLine)
{
	line[lineCount] = nLine;
	lineCount++;
}

void Display::doRecieve()
{
	for (int count = 0; count <= lineCount - 1; count++) {
		std::cout << line[count];
	}
}

void Display::passNameFirst(const char * nFirst)                     { user_interface->passNameFirst(nFirst);   };
void Display::passNameLast(const char * nLast)                       { user_interface->passNameLast(nLast);     };
void Display::passHealth(const int nHealth)                          { user_interface->passHealth(nHealth);     };
void Display::passStrength(const int nStrength)                      { user_interface->passStrength(nStrength); };
void Display::setViewPortX(const int nX)                             { viewX = nX;                              };
void Display::setViewPortY(const int nY)                             { viewY = nY;                              };
void Display::passLocX(const int nX)                                 { user_interface->passLocX(nX);            };
void Display::passLocY(const int nY)                                 { user_interface->passLocY(nY);            };
void Display::setTileBuffer(Tile *nV, const int dX, const int dY)    { tileBuff[dX][dY] = nV;                   };

void Display::clearTileBuffer()
{
	setViewPosX(0);
	setViewPosY(0);

	for (int yCount = 0; yCount <= getViewPortY() - 1; yCount++) {
		for (int xCount = 0; xCount <= getViewPortX() - 1; xCount++) {
			setTileBuffer(NULL, xCount, yCount);
		}
	}
}

void Display::doPrint()
{
	for (int yCount = 0; yCount <= getViewPortY() - 1; yCount++) {
		for (int xCount = 0; xCount <= getViewPortX() - 1; xCount++) {
			std::cout << getTileCharacter(xCount, yCount) << " ";
			/* Stats Pane */
			if (xCount == getViewPortX() - 1) {
				std::cout << "| ";
				switch (yCount) {
					case 1:
						std::cout << "Name: " << user_interface->getNameFirst() << " " << user_interface->getNameLast();
						break;
					case 3:
						std::cout << "Health: " << user_interface->getHealth();
						break;
					case 4:
						std::cout << "Strength: " << user_interface->getStrength();
						break;
					case 6:
						std::cout << "Location: " << user_interface->getLocX() << ", " << user_interface->getLocY();
						break;
					default:
						break;
				}
			}
		} std::cout << std::endl;
	}

	clearTileBuffer();
}
