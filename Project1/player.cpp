#include "player.h"
#include "gameManager.h"
Player player;

void setPlayerParameters() {
	player.rec.x = screenWidth / 2;
	player.rec.y = screenHeight * 7 / 8;
	player.rec.width = 80;
	player.rec.height = 10;
	player.life = PLAYER_MAX_LIFE;
}

