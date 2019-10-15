#include "ball.h"
#include "gameManager.h"
Ball ball;
void setBallParameters() {
	ball.position = { screenWidth / 2, screenHeight * 7 / 8 - 30 };
	ball.speed = { 0, 0 };
	ball.radius = 7;
	ball.active = false;
}