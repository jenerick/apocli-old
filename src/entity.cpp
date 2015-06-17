#include "entity.h"

const char * Entity::getNameFirst()    { return nameFirst; };
const char * Entity::getNameLast()     { return nameLast; };

int Entity::getHealth()    { return health; };

void Entity::setHealth(const int nHealth)          { health = nHealth; };
void Entity::setNameFirst(const char * nFirst)     { nameFirst = nFirst; };
void Entity::setNameLast(const char * nLast)       { nameLast = nLast; };

Entity::Entity()
{
	setHealth(100);
}
