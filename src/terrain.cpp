#include "terrain.h"

Dirt::Dirt()
{
	setName("dirt");
	setPrintChar('.');
	setLocationZ(0);
}

Grass::Grass()
{
	setName("grass");
	setPrintChar('\'');
	setLocationZ(1);
}

Shrub::Shrub()
{
	setName("shrub");
	setPrintChar('"');
	setLocationZ(2);
}
