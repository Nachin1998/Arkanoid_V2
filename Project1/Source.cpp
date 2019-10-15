#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "collisions.h"

#include "gameManager.h"
#include "player.h"
#include "ball.h"
#include "bricks.h"

static bool gameOver = false;
static bool pause = false;

typedef enum GameScreen { LOGO, TITLE, GAMEPLAY, ENDING } GameScreen;

enum gameMode {
	singlePlayer,
	multyPlayer
}gamemode;

static void InitGame(void);         // Initialize game
static void UpdateGame(void);       // Update game (one frame)
static void DrawGame(void);         // Draw game (one frame)
static void UnloadGame(void);       // Unload game
static void UpdateDrawFrame(void);  // Update and Draw (one frame)

int main(void)
{
	InitWindow(screenWidth, screenHeight, "Nark-anoid");

	SetTargetFPS(60);

	// Main game loop
	while (!WindowShouldClose()) 
	{
		gameOver = false;
		UpdateDrawFrame();
	}

	UnloadGame();
	CloseWindow();
	return 0;
}

void UpdateDrawFrame(void)
{
	UpdateGame();
	DrawGame();
}

// Update game (one frame)
void UpdateGame(void)
{
	
		if (IsKeyPressed('P')) pause = !pause;

		if (!pause)
		{
			// Player movement logic
			if (IsKeyDown(KEY_LEFT)|| IsKeyDown(KEY_A)) player.rec.x -= 6;
			if ((player.rec.x - player.rec.width / 2) <= 0) player.rec.x = player.rec.width / 2;
			if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) player.rec.x += 6;
			if ((player.rec.x + player.rec.width / 2) >= screenWidth) player.rec.x = screenWidth - player.rec.width / 2;

			// Ball launching logic
			if (!ball.active)
			{
				if (IsKeyPressed(KEY_SPACE))
				{
					ball.active = true;
					ball.speed = { 0, -5 };
				}
			}

			// Ball movement
			if (ball.active)
			{
				ball.position.x += ball.speed.x;
				ball.position.y += ball.speed.y;
			}
			else
			{
				ball.position = { player.rec.x, screenHeight * 7 / 8 - 30 };
			}

			collisions();
			//// Collision ball ands walls 
			//if (((ball.position.x + ball.radius) >= screenWidth) || ((ball.position.x - ball.radius) <= 0)) ball.speed.x *= -1;
			//if ((ball.position.y - ball.radius) <= 0) ball.speed.y *= -1;
			//if ((ball.position.y + ball.radius) >= screenHeight)
			//{
			//	ball.speed = { 0, 0 };
			//	ball.active = false;

			//	player.life--;
			//}

			//// Collision ball and player
			//if (CheckCollisionCircleRec(ball.position, ball.radius,{ player.rec.x - player.rec.width / 2, player.rec.y - player.rec.height/ 2, player.rec.width, player.rec.height}))
			//{
			//	if (ball.speed.y > 0)
			//	{
			//		ball.speed.y *= -1;
			//		ball.speed.x = (ball.position.x - player.rec.x) / (player.rec.width / 2) * 5;
			//	}
			//}

			//// Collision ball and bricks
			//for (int i = 0; i < LINES_OF_BRICKS; i++)
			//{
			//	for (int j = 0; j < BRICKS_PER_LINE; j++)
			//	{
			//		if (brick[i][j].active)
			//		{
			//			// Hit below
			//			if (((ball.position.y - ball.radius) <= (brick[i][j].position.y + brickSize.y / 2)) &&
			//				((ball.position.y - ball.radius) > (brick[i][j].position.y + brickSize.y / 2 + ball.speed.y)) &&
			//				((fabs(ball.position.x - brick[i][j].position.x)) < (brickSize.x / 2 + ball.radius * 2 / 3)) && (ball.speed.y < 0))
			//			{
			//				brick[i][j].active = false;
			//				ball.speed.y *= -1;
			//			}
			//			// Hit above
			//			else if (((ball.position.y + ball.radius) >= (brick[i][j].position.y - brickSize.y / 2)) &&
			//				((ball.position.y + ball.radius) < (brick[i][j].position.y - brickSize.y / 2 + ball.speed.y)) &&
			//				((fabs(ball.position.x - brick[i][j].position.x)) < (brickSize.x / 2 + ball.radius * 2 / 3)) && (ball.speed.y > 0))
			//			{
			//				brick[i][j].active = false;
			//				ball.speed.y *= -1;
			//			}
			//			// Hit left
			//			else if (((ball.position.x + ball.radius) >= (brick[i][j].position.x - brickSize.x / 2)) &&
			//				((ball.position.x + ball.radius) < (brick[i][j].position.x - brickSize.x / 2 + ball.speed.x)) &&
			//				((fabs(ball.position.y - brick[i][j].position.y)) < (brickSize.y / 2 + ball.radius * 2 / 3)) && (ball.speed.x > 0))
			//			{
			//				brick[i][j].active = false;
			//				ball.speed.x *= -1;
			//			}
			//			// Hit right
			//			else if (((ball.position.x - ball.radius) <= (brick[i][j].position.x + brickSize.x / 2)) &&
			//				((ball.position.x - ball.radius) > (brick[i][j].position.x + brickSize.x / 2 + ball.speed.x)) &&
			//				((fabs(ball.position.y - brick[i][j].position.y)) < (brickSize.y / 2 + ball.radius * 2 / 3)) && (ball.speed.x < 0))
			//			{
			//				brick[i][j].active = false;
			//				ball.speed.x *= -1;
			//			}
			//		}
			//	}
			//}

			// Game over logic
			if (player.life <= 0) gameOver = true;
			else
			{
				gameOver = false;

				for (int i = 0; i < LINES_OF_BRICKS; i++)
				{
					for (int j = 0; j < BRICKS_PER_LINE; j++)
					{
						if (brick[i][j].active) gameOver = false;
					}
				}
			}
		}
	}


// Draw game (one frame)
void DrawGame(void)
{
	BeginDrawing();

	ClearBackground(BLACK);

		// Draw player bar
		DrawRectangle(player.rec.x - player.rec.width / 2, player.rec.y - player.rec.height / 2, player.rec.width, player.rec.height, BLUE);

		// Draw player lives
		for (int i = 0; i < player.life; i++) DrawRectangle(20 + 40 * i, screenHeight - 30, 30, 10, YELLOW);

		// Draw ball
		DrawCircleV(ball.position, ball.radius, MAROON);

		// Draw bricks
		for (int i = 0; i < LINES_OF_BRICKS; i++)
		{
			for (int j = 0; j < BRICKS_PER_LINE; j++)
			{
				if (brick[i][j].active)
				{
					if ((i + j) % 2 == 0) DrawRectangle(brick[i][j].position.x - brickSize.x / 2, brick[i][j].position.y - brickSize.y / 2, brickSize.x, brickSize.y, GRAY);
					else DrawRectangle(brick[i][j].position.x - brickSize.x / 2, brick[i][j].position.y - brickSize.y / 2, brickSize.x, brickSize.y, DARKGRAY);
				}
			}
		}

		//if (pause) DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
		
		//DrawText("Press Enter to play again", GetScreenWidth() / 2 - MeasureText("Press Enter to play again", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);

	EndDrawing();
}

void UnloadGame(void)
{

}

// Initialize game variables
void InitGame(void)
{
	Vector2 help = { 200, 40 };
}

