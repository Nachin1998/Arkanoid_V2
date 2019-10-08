#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>

const int PLAYER_MAX_LIFE = 5;

const int LINES_OF_BRICKS = 5;
const int BRICKS_PER_LINE = 20;

static const int screenWidth = 800;
static const int screenHeight = 450;
static const Vector2 brickSize = { screenWidth / BRICKS_PER_LINE, 40 };

static bool gameOver = false;
static bool pause = false;

void drawBricks();

enum GameScreen { MAIN_MENU, GAMEPLAY, ENDING } gameScreen;
enum GameMode { SINGLEPLAYER, MULTIPLAYER, ARKAPONG } gameMode;

struct Player {
	Rectangle rec;
	Color color;
	int life;
} player;

struct Ball {
	Vector2 position;
	Vector2 speed;
	Color color;
	int radius;
	bool active;
} ball;

struct Brick {
	Rectangle rec;
	Color color;
	bool active;
}brick[LINES_OF_BRICKS][BRICKS_PER_LINE];;

void drawing() {
	BeginDrawing();
	drawBricks();
	DrawRectangleRec(player.rec, player.color);
	DrawCircleV(ball.position, ball.radius, ball.color);

	
	EndDrawing();
}
void drawBricks() {
	for (int i = 0; i < LINES_OF_BRICKS; i++)
	{
		for (int j = 0; j < BRICKS_PER_LINE; j++)
		{
			if (brick[i][j].active)
			{
				DrawRectangleRec(brick[i][j].rec, brick[i][j].color);
				//DrawRectangleRec(players[i].rec, players[i].playerColor);
			}
		}
	}
}
void initEntities() {
	// Initialize player
	player.rec.x = (screenWidth / 2) - 50;
	player.rec.y = screenHeight * 7 / 8;
	player.rec.width = 80;
	player.rec.height = 10;
	player.life = PLAYER_MAX_LIFE;
	player.color = BLUE;

	// Initialize ball
	ball.position = { player.rec.x+40, player.rec.y-30};
	ball.speed = { -5, -5 };
	ball.color = YELLOW;
	ball.radius = 7;
	ball.active = false;

	// Initialize bricks
	int initialYPosition = 50;
	for (int i = 0; i < LINES_OF_BRICKS; i++)
	{
		for (int j = 0; j < BRICKS_PER_LINE; j++)
		{
			if ((i + j) % 2 == 0) {
				brick[i][j].rec.x = j * brickSize.x;
				brick[i][j].rec.y = i * brickSize.y + initialYPosition;
				brick[i][j].color = WHITE;
			}
			else {
				brick[i][j].rec.x = j * brickSize.x;
				brick[i][j].rec.y = i * brickSize.y + initialYPosition;
				brick[i][j].color = RED;
			}
			brick[i][j].rec.width = brickSize.x;
			brick[i][j].rec.height = brickSize.y;
			brick[i][j].active = true;
		}
	}
}

void screenSelection() {
	switch (gameScreen)
	{
	case MAIN_MENU:
		break;
	case GAMEPLAY:
		break;
	case ENDING:
		break;
	default:
		break;
	}
}
void inputs() {
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) player.rec.x -= 6;
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) player.rec.x += 6;
}

void collisions() {
	if ((player.rec.x - player.rec.width / 2) <= 0) { 
		player.rec.x = player.rec.width / 2;
	}
	if ((player.rec.x + player.rec.width / 2) >= screenWidth) { 
		player.rec.x = screenWidth - player.rec.width / 2; 
	}

	// Collision ball and bricks
	// Los * -1 estan apagados
	for (int i = 0; i < LINES_OF_BRICKS; i++)
	{
		for (int j = 0; j < BRICKS_PER_LINE; j++)
		{
			if (brick[i][j].active)
			{
				// Hit below
				if (((ball.position.y - ball.radius) <= (brick[i][j].rec.y + brickSize.y / 2)) &&
					((ball.position.y - ball.radius) > (brick[i][j].rec.y + brickSize.y / 2 + ball.speed.y)) &&
					((fabs(ball.position.x - brick[i][j].rec.x)) < (brickSize.x / 2 + ball.radius * 2 / 3)) && (ball.speed.y < 0))
				{
					brick[i][j].active = false;
					//ball.speed.y *= -1;
				}
				// Hit above
				else if (((ball.position.y + ball.radius) >= (brick[i][j].rec.y - brickSize.y / 2)) &&
					((ball.position.y + ball.radius) < (brick[i][j].rec.y - brickSize.y / 2 + ball.speed.y)) &&
					((fabs(ball.position.x - brick[i][j].rec.x)) < (brickSize.x / 2 + ball.radius * 2 / 3)) && (ball.speed.y > 0))
				{
					brick[i][j].active = false;
					//ball.speed.y *= -1;
				}
				// Hit left
				else if (((ball.position.x + ball.radius) >= (brick[i][j].rec.x - brickSize.x / 2)) &&
					((ball.position.x + ball.radius) < (brick[i][j].rec.x - brickSize.x / 2 + ball.speed.x)) &&
					((fabs(ball.position.y - brick[i][j].rec.y)) < (brickSize.y / 2 + ball.radius * 2 / 3)) && (ball.speed.x > 0))
				{
					brick[i][j].active = false;
					//ball.speed.x *= -1;
				}
				// Hit right
				else if (((ball.position.x - ball.radius) <= (brick[i][j].rec.x + brickSize.x / 2)) &&
					((ball.position.x - ball.radius) > (brick[i][j].rec.x + brickSize.x / 2 + ball.speed.x)) &&
					((fabs(ball.position.y - brick[i][j].rec.y)) < (brickSize.y / 2 + ball.radius * 2 / 3)) && (ball.speed.x < 0))
				{
					brick[i][j].active = false;
					//ball.speed.x *= -1;
				}
			}
		}
	}

}
void main() {
	InitWindow(screenWidth, screenHeight, "Nark-anoid");
	SetTargetFPS(60);
	initEntities();
	while (!WindowShouldClose())
	{
		ball.position.y += ball.speed.x;
		ball.position.y += ball.speed.y;
		ClearBackground(BLACK);
		collisions();
		inputs();
		drawing();
	}
}