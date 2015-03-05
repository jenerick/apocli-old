#ifndef APOCLI_OBJECTS_H_
#define APOCLI_OBJECTS_H_

#include <string>

class Object {
	private:
		std::string
			name;

		char	printChar;

		 int 	xLocation,
			yLocation,
			zPlane,
			type,
			identifier;
	public:
		std::string
			getName();

		void	setName(std::string nName),
			setPrintChar(char nChar),
			setIdentifier(int nIdent),
			setType(int nType);

		char	getPrintChar();

		int	getLocationX(),
			getLocationY(),
			getLocationZ();

		void	setLocationX(const int nX),
		     	setLocationY(const int nY),
		     	setLocationZ(const int nZ),
		     	moveUp(const int yBound),
		     	moveDn(const int yBound),
		     	moveLt(const int xBound),
		     	moveRt(const int xBound);
};

#endif
