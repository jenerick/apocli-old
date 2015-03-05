#ifndef APOCLI_TILE_H__
#define APOCLI_TILE_H__

#include "actor.h"
#include "terrain.h"

#define CONSTANT_PLANES_Z 5

class Tile {
	private:
		Actor 	*actor;
		Object	*object[5];

		int	xCoordinate,
			yCoordinate,
			zPlanes,
			queueFilled;
	public:
		bool	getIsActor();
		char	getPrintChar();

		int	getPlanesZ(),
			getCoordinateX(),
			getCoordinateY(),
			getIdentifier();

		void	setActor(Actor * nActor),
			remActor(),
			setCoordinateX(const int nX),
			setCoordinateY(const int nY),
			setObject(Object * nObject);

			Tile(const int nX, const int nY);
};

#endif
