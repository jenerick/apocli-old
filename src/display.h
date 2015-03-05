#ifndef APOCLI_DISPLAY_H__
#define APOCLI_DISPLAY_H__

#include "tile.h"
#include "ui.h"

#define DISPLAY_DUMB__ 5;

class Display {
	private:
		const char
			*line[2];

		Tile    *tileBuff[25][25];

		int	viewX,
			viewY,
			viewPosX,
			viewPosY,
			lineCount;

		UI	*user_interface;
	public:
		const char
			getTileCharacter(const int dX, const int dY);

		int	getViewPosX(),
			getViewPosY(),
			getViewPortX(),
			getViewPortY();

		void	passNameFirst(const char * nFirst),
			passNameLast(const char * nLast),
			passHealth(const int nHealth),
			passStrength(const int nStrength),
			doSendTile(Tile *nTile),
			doSendLine(const char * nLine),
			doBreak(),
			doRecieve(),
			doPrint(),
			setViewPosX(const int nX),
			setViewPosY(const int nY),
			setViewPortX(const int nX),
			setViewPortY(const int nY),
			setTileBuffer(Tile *nV, const int dX, const int dY),
			passLocX(const int nX),
			passLocY(const int nY),
			clearTileBuffer();

			Display(const int dID, const int nViewX, const int nViewY);

		Tile*	getTileBuffer(int, int);
};

#endif
