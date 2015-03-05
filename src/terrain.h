#ifndef APOCLI_TERRAIN_H__
#define APOCLI_TERRAIN_H__

#include "object.h"

class Terrain : public Object {
};

class Dirt : public Terrain {
	public:
		Dirt();
};

class Grass : public Terrain {
	public:
		Grass();
};

class Shrub : public Terrain {
	public:
		Shrub();
};

#endif
