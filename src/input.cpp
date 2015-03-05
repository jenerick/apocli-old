#include <iostream>

#include "signal.h"
#include "input.h"

void input(Actor * tActor)
{
	char input;

	std::cout << '>';
	std::cin >> input;

	switch (input) {
		case 'w':
			tActor->moveUp(25);
			break;
		case 's':
			tActor->moveDn(25);
			break;
		case 'a':
			tActor->moveLt(25);
			break;
		case 'd':
			tActor->moveRt(25);
			break;
		case 'q':
			killGame(killNorm);
			break;
		default:
			break;
	}
}
