#ifndef APOCLI_ACTOR_H__
#define APOCLI_ACTOR_H__

#include "entity.h"

enum actor_t {
	ID_ACTOR
};

class Actor : public Entity {
	private:
		int	strength;
	public:
		int	getStrength();

		void	setStrength(const int nStrength);

		Actor(const char * nFirst, const char * nLast);
};

#endif
