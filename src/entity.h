#ifndef APOCLI_ENTITY_H__
#define APOCLI_ENTITY_H__

#include "object.h"

class Entity : public Object {
	private:
		const char
			*nameFirst,
			*nameLast;

		int	health;
	public:
		const char
			*getNameFirst(),
			*getNameLast();

		int	getHealth();

		void	setHealth(const int nHealth),
			setNameFirst(const char * nFirst),
			setNameLast(const char * nLast);

			Entity();
};

#endif
