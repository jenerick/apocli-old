#ifndef APOCLI_GAME_H__
#define APOCLI_GAME_H__

#include "display.h"
#include "world.h"

class Game {
	private:
		Actor	*actor;
		Display *display;
		World	*world;
	public:
		void	loadDisplay(Display * nDisplay),
			loadWorld(World * nWorld),
			makeActor();

			Game(Display * nDisplay);
};

#endif
