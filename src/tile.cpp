#include "tile.h"

bool Tile::getIsActor()
{
	if (!actor) return false;
		else return true;
}

char Tile::getPrintChar()
{
	int actPlane, objPlane;

	if (!actor) {
		return '.';
	} else {
		return actor->getPrintChar();
	}
}

int Tile::getPlanesZ()        { return zPlanes;     };
int Tile::getCoordinateX()    { return xCoordinate; };
int Tile::getCoordinateY()    { return yCoordinate; };

tile_type Tile::getIdentifier()     { return TILE_DIRT; };

void Tile::setActor(Actor * nActor)        { actor = nActor;   };
void Tile::remActor()                      { actor = NULL;     };
void Tile::setCoordinateX(const int nX)    { xCoordinate = nX; };
void Tile::setCoordinateY(const int nY)    { yCoordinate = nY; };

Tile::Tile(const int nX, const int nY)
{
	zPlanes = CONSTANT_PLANES_Z;
	queueFilled = 0;
	setCoordinateX(nX);
	setCoordinateY(nY);
}
