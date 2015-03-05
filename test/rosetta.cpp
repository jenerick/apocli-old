#include <iostream>

#include "../src/tools.h"

int main(int argc, char** argv)
{
	int dX,
	    dY,
	    rX,
	    rY;

	std::cout << "DimensionX:" << std::endl;
	std::cin >> dX;
	std::cout << "DimensionY:" << std::endl;
	std::cin >> dY;
	std::cout << "RosX:" << std::endl;
	std::cin >> rX;
	std::cout << "RosY:" << std::endl;
	std::cin >> rY;
	rX = Tools::Location::rosX(rX, dX);
	rY = Tools::Location::rosY(rY, dY);
	std::cout << dX << ' ' << dY << ' ' << rX << ' ' << rY << std::endl;
	return 0;
}
