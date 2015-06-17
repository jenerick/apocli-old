#include "object.h"

// begin class "Object"
std::string Object::getName() { return name; };

char Object::getPrintChar() { return printChar; };

int Object::getLocationX() { return xLocation; };
int Object::getLocationY() { return yLocation; };
int Object::getLocationZ() { return zPlane;    };

void Object::setLocationX(const int nX) { xLocation = nX; };
void Object::setLocationY(const int nY) { yLocation = nY; };
void Object::setLocationZ(const int nZ) { zPlane    = nZ; };
void Object::setPrintChar(char nChar)   { printChar = nChar; };
void Object::setName(std::string nName) { name = nName; };
void Object::setIdentifier(const int nIdent) { identifier = nIdent; };

void Object::moveUp(const int yBound)
{
	if (getLocationY() <= 0) {
		// std::cerr << "Can't move " << getName() << " up: boundary limit." << std::endl;
	} else {
		yLocation--;
	}
}

void Object::moveDn(const int yBound)
{
	if (getLocationY() >= yBound - 1) {
		// std::cerr << "Can't move " << getName() << " down: boundary limit." << std::endl;
	} else {
		yLocation++;
	}
}

void Object::moveLt(const int xBound)
{
	if (getLocationX() <= 0) {
		// std::cerr << "Can't move " << getName() << " left: boundary limit." << std::endl;
	} else {
		xLocation--;
	}
}

void Object::moveRt(const int xBound)
{
	if (getLocationX() >= xBound - 1) {
		// std::cerr << "Can't move " << getName() << " right: boundary limit." << std::endl;
	} else {
		xLocation++;
	}
}
// end class "Object"
