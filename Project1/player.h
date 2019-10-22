#ifndef PLAYER_H
#define	PLAYER_H
#include "raylib.h"

namespace game {
	struct Player {
		Rectangle rec;
		int life;
	};

	extern Player player;
	void setPlayerParameters();
}

#endif