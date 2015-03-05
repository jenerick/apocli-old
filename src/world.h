#ifndef APOCLI_WORLD_H__
#define APOCLI_WORLD_H__

#define WORLD_SMALL__ 15
#define WORLD_NORML__ 25
#define WORLD_LARGE__ 35

#include "tile.h"

class WorldDummy {
	private:
		int xDimension,
		    yDimension;
	public:
		int getDimensionX(),
		    getDimensionY();

		void setDimensionX(const int nX),
		     setDimensionY(const int nY);
};

class WorldSmall : public WorldDummy {
	private:
		Tile * tile[15][15];
	public:
		WorldSmall();
};

class WorldNorml : public WorldDummy {
	private:
		Tile * tile[25][25];
	public:
		WorldNorml();
};

class WorldLarge : public WorldDummy {
	private:
		Tile * tile[35][35];
	public:
		WorldLarge();
};

class World {
	private:
		WorldSmall * small;
		WorldNorml * norml;
		WorldLarge * large;

		int xDimension,
		    yDimension;

		Tile * tile[25][25];
	public:
		bool getIsActor(const int dX, const int dY);

		char getPrintChar(const int dX, const int dY);

		int getDimensionX(),
		    getDimensionY();

		void setActor(Actor * nActor, const int dX, const int dY);
		void remActor(const int dX, const int dY);

		Tile * getTile(const int dX, const int dY);

		World(const int worldID);
};

#endif
