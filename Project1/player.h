#ifndef PLAYER_H
#define	PLAYER_H
#include "raylib.h"

	struct Player {
		Rectangle rec;
		int life;
	};

	extern Player player;
	void setPlayerParameters();

#endif