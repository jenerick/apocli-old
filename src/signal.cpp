#include "signal.h"

static bool isGameKill = true;

void	killGame(const int sign)    { isGameKill = false; };

bool	isKill(const char *id)      { if (id == "game") return isGameKill; };
