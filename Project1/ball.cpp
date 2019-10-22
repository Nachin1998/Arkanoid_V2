#include "ball.h"
#include "player.h"

namespace game {
	Ball ball;
	void setBallParameters() {
		ball.position = { player.rec.x + player.rec.width / 2, player.rec.y - 20 };
		ball.speed = { 0, 0 };
		ball.radius = 7;
		ball.active = false;
	}
}