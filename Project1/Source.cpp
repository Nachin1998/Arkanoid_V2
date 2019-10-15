#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "collisions.h"

#include "gameManager.h"
#include "player.h"
#include "ball.h"
#include "bricks.h"

#include "mainMenu.h"

static bool gameOver = false;
static bool pause = false;
bool enter = false;

typedef enum GameScreen { LOGO, TITLE, GAMEPLAY, ENDING } GameScreen;

enum gameMode {
	singlePlayer,
	multiPlayer
}gamemode;

static void InitGame();         // Initialize game
static void UpdateGame();       // Update game (one frame)
static void setAllParameters();
static void DrawGame();         // Draw game (one frame)
static void UnloadGame();       // Unload game
static void UpdateDrawFrame();  // Update and Draw (one frame)

int main(void)
{
	InitWindow(screenWidth, screenHeight, "Nark-anoid");
	mainMenu();
	SetTargetFPS(60);
	setAllParameters();
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
			if ((player.rec.x) <= 0) player.rec.x = 0.1f;
			if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) player.rec.x += 6;
			if ((player.rec.x + player.rec.width) >= screenWidth) player.rec.x = screenWidth - player.rec.width;

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
				ball.position = { player.rec.x + player.rec.width/2, player.rec.y - 20 };

			collisions();

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

void setAllParameters() {
	setPlayerParameters();
	setBallParameters();
	setBrickParameters();
}

// Draw game (one frame)
void DrawGame(void)
{
	BeginDrawing();

	ClearBackground(BLACK);

	// Draw player bar
	if (IsKeyPressed(KEY_ENTER))enter = true;

	if (enter) {
		DrawRectangleRec(player.rec, BLUE);
	}else
		DrawRectangleLinesEx(player.rec, 2, WHITE);

		// Draw player lives
		for (int i = 0; i < player.life; i++) DrawRectangle(20 + 178 * i, screenHeight - 30, 30, 10, YELLOW);

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

		

		if (pause) DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
		
		if(gameOver) DrawText("Press Enter to play again", GetScreenWidth() / 2 - MeasureText("Press Enter to play again", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);

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

