// #include <iostream> // DEBUG PURPOSES ONLY!!!

#include "debug.h"
#include "game.h"

int main(int argc, char** argv)
{
	int APOCLI_TERMCAP__;
	Display * display;
	Game * game;

	APOCLI_TERMCAP__ = DISPLAY_DUMB__;

	display = new Display(APOCLI_TERMCAP__, 25, 25);
	game = new Game(display); // set up the game

	return 0; // exited with no errors
}
