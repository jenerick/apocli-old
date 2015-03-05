#ifndef APOCLI_UI_H__
#define APOCLI_UI_H__

class UI {
	private:
		const char
			*nameFirst,
			*nameLast;

		int	statHealth,
			statStrength,
			xLoc,
			yLoc;
	public:
		const char
			*getNameFirst(),
			*getNameLast();

		int	getHealth(),
			getStrength(),
			getLocX(),
			getLocY();

		void	passNameFirst(const char * nFirst),
			passNameLast(const char * nLast),
			passHealth(const int nHealth),
			passStrength(const int nStrength),
			passLocX(const int nX),
			passLocY(const int nY);
};

#endif
