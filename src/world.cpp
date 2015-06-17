#include "world.h"

Tile* World::getTile(const int dX, const int dY) { return tile[dX][dY]; }

// begin class "WorldDummy"
int WorldDummy::getDimensionX()
{
	return xDimension;
}

int WorldDummy::getDimensionY()
{
	return yDimension;
}

void WorldDummy::setDimensionX(const int nX)
{
	xDimension = nX;
}

void WorldDummy::setDimensionY(const int nY)
{
	yDimension = nY;
}
// end class "WorldDummy"

WorldSmall::WorldSmall()
{
	setDimensionX(15);
	setDimensionY(15);

	for (int yCount = 0; yCount <= getDimensionY() - 1; yCount++) {
		for (int xCount = 0; xCount <= getDimensionX() - 1; xCount++) {
			tile[xCount][yCount] = new Tile(xCount, yCount);
		}
	}
}

WorldNorml::WorldNorml()
{
	setDimensionX(25);
	setDimensionY(25);

	for (int yCount = 0; yCount <= getDimensionY() - 1; yCount++) {
		for (int xCount = 0; xCount <= getDimensionX() - 1; xCount++) {
			tile[xCount][yCount] = new Tile(xCount, yCount);
		}
	}
}

WorldLarge::WorldLarge()
{
	setDimensionX(35);
	setDimensionY(35);

	for (int yCount = 0; yCount <= getDimensionY() - 1; yCount++) {
		for (int xCount = 0; xCount <= getDimensionX() - 1; xCount++) {
			tile[xCount][yCount] = new Tile(xCount, yCount);
		}
	}
}

// begin class "World"
/*bool World::getIsActor(const int dX, const int dY)
{
	// dummy function
	return false;
} */

char World::getPrintChar(const int dX, const int dY)
{
	return tile[dX][dY]->getPrintChar();
}

int World::getDimensionX()
{
	/* if (!large) { if (!norml) { if (!small) { return -1; 
			} else { return small->getDimensionX(); }
		} else { return norml->getDimensionX(); }
	} else { return large->getDimensionX(); } */

	return xDimension;
}

int World::getDimensionY()
{
	/* if (!large) { if (!norml) { if (!small) { return -1; 
			} else { return small->getDimensionY(); }
		} else { return norml->getDimensionY(); }
	} else { return large->getDimensionY(); } */

	return yDimension;
}

void World::setActor(Actor * nActor, const int dX, const int dY)
{
	tile[dX][dY]->setActor(nActor);
}

void World::remActor(const int dX, const int dY)
{
	tile[dX][dY]->remActor();
}

World::World(const int worldID)
{
	/* if (worldID != WORLD_LARGE__) { if (worldID != WORLD_NORML__) { if (worldID != WORLD_SMALL__) { // do nothing
			} else { small = new WorldSmall; }
		} else { norml = new WorldNorml; }
	} else { large = new WorldLarge; } */

	xDimension = 25;
	yDimension = 25;

	for (int yCount = 0; yCount <= yDimension - 1; yCount++) {
		for (int xCount = 0; xCount <= xDimension - 1; xCount++) {
			tile[xCount][yCount] = new Tile(xCount, yCount);
		}
	}
}
// end class "World"
