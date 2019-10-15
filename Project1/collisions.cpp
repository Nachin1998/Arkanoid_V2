#include "collisions.h"
#include "gameManager.h"
#include "player.h"
#include "ball.h"
#include "bricks.h"
#include "raylib.h"
#include <math.h>
void collisions() {
	// Collision ball ands walls 
	if (((ball.position.x + ball.radius) >= screenWidth) || ((ball.position.x - ball.radius) <= 0)) ball.speed.x *= -1;
	if ((ball.position.y - ball.radius) <= 0) ball.speed.y *= -1;
	if ((ball.position.y + ball.radius) >= screenHeight)
	{
		ball.speed = { 0, 0 };
		ball.active = false;
		player.life--;
	}

	// Collision ball and player
	if (CheckCollisionCircleRec(ball.position, ball.radius, player.rec))
	{
		if (ball.speed.y > 0)
		{
			ball.speed.y *= -1;
			ball.speed.x = (ball.position.x - player.rec.x) / (player.rec.width) * 5;
		}
	}

	// Collision ball and bricks
	for (int i = 0; i < LINES_OF_BRICKS; i++)
	{
		for (int j = 0; j < BRICKS_PER_LINE; j++)
		{
			if (brick[i][j].active)
			{
				// Hit below
				if (((ball.position.y - ball.radius) <= (brick[i][j].position.y + brickSize.y / 2)) &&
					((ball.position.y - ball.radius) > (brick[i][j].position.y + brickSize.y / 2 + ball.speed.y)) &&
					((fabs(ball.position.x - brick[i][j].position.x)) < (brickSize.x / 2 + ball.radius * 2 / 3)) && (ball.speed.y < 0))
				{
					brick[i][j].active = false;
					ball.speed.y *= -1;
				}
				// Hit above
				else if (((ball.position.y + ball.radius) >= (brick[i][j].position.y - brickSize.y / 2)) &&
					((ball.position.y + ball.radius) < (brick[i][j].position.y - brickSize.y / 2 + ball.speed.y)) &&
					((fabs(ball.position.x - brick[i][j].position.x)) < (brickSize.x / 2 + ball.radius * 2 / 3)) && (ball.speed.y > 0))
				{
					brick[i][j].active = false;
					ball.speed.y *= -1;
				}
				// Hit left
				else if (((ball.position.x + ball.radius) >= (brick[i][j].position.x - brickSize.x / 2)) &&
					((ball.position.x + ball.radius) < (brick[i][j].position.x - brickSize.x / 2 + ball.speed.x)) &&
					((fabs(ball.position.y - brick[i][j].position.y)) < (brickSize.y / 2 + ball.radius * 2 / 3)) && (ball.speed.x > 0))
				{
					brick[i][j].active = false;
					ball.speed.x *= -1;
				}
				// Hit right
				else if (((ball.position.x - ball.radius) <= (brick[i][j].position.x + brickSize.x / 2)) &&
					((ball.position.x - ball.radius) > (brick[i][j].position.x + brickSize.x / 2 + ball.speed.x)) &&
					((fabs(ball.position.y - brick[i][j].position.y)) < (brickSize.y / 2 + ball.radius * 2 / 3)) && (ball.speed.x < 0))
				{
					brick[i][j].active = false;
					ball.speed.x *= -1;
				}
			}
		}
	}
}
