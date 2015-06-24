#include "actor.h"

int Actor::getStrength()    { return strength; }

void Actor::setStrength(const int nStrength)    { strength = nStrength; }

Actor::Actor(const char * nFirst, const char * nLast)
{
	setName("actor");
	setNameFirst(nFirst);
	setNameLast(nLast);
	setIdentifier(ID_ACTOR);
	// setPrintChar('@');
	setStrength(25);
}
