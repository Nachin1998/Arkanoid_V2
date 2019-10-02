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

static bool gameOver = false;
static bool pause = false;

static Vector2 brickSize = { 0 };

enum GameScreen { LOGO, TITLE, GAMEPLAY, ENDING } gameScreen;
enum GameMode { SINGLEPLAYER, MULTIPLAYER, ARKAPONG } gameMode;

struct Player {
	Rectangle rec;
	Vector2 position;
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
	Vector2 position;
	bool active;
} brick[LINES_OF_BRICKS][BRICKS_PER_LINE];

void drawing() {
	BeginDrawing();

	DrawRectangleRec(player.rec, player.color);
	DrawCircleV(ball.position, ball.radius, ball.color);

	EndDrawing();
}

void initEntities() {
	// Initialize player
	player.rec.x = (GetScreenWidth() / 2)-50;
	player.rec.y = GetScreenHeight() * 7 / 8;
	player.rec.width = 80;
	player.rec.height = 10;
	player.life = PLAYER_MAX_LIFE;
	player.color = BLUE;

	// Initialize ball
	ball.position = { (screenWidth / 2)-10, screenHeight * 7 / 8 - 30 };
	ball.speed = { 0, 0 };
	ball.color = YELLOW;
	ball.radius = 7;
	ball.active = false;
}

void main() {
	InitWindow(screenWidth, screenHeight, "Nark-anoid");
	SetTargetFPS(60);
	
	while (!WindowShouldClose())
	{
		ClearBackground(BLACK);
		initEntities();
		drawing();
	}

	

	
	
}