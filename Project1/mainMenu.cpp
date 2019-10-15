#include "mainMenu.h"
#include "raylib.h"
#include "gameManager.h"

void mainMenu() {

	Rectangle playButton;
	playButton.x = 20;
	playButton.y = screenHeight / 2 - 60;
	playButton.height = 24;
	playButton.width = 50;
	SetTargetFPS(60);

	
	while (!WindowShouldClose())
	{
		
		BeginDrawing();

		ClearBackground(BLACK);

		DrawText("Nark-anoid", 20, screenHeight / 2 - 200, 50, LIGHTGRAY);
		//DrawRectangleRec(playButton, WHITE);
		if (!CheckCollisionPointRec(GetMousePosition(), playButton))
			DrawText("Play", 20, screenHeight / 2 - 60, 24, LIGHTGRAY);
		else
			DrawText("Play", 20, screenHeight / 2 - 60, 24, BLUE);

		if (CheckCollisionPointRec(GetMousePosition(), playButton) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			DrawText("Play", 20, screenHeight / 2 - 60, 24, DARKBLUE);
		}
		DrawText("Controls", 60 - 40, screenHeight / 2 - 15, 24, LIGHTGRAY);
		DrawText("Credits", 60 - 40, screenHeight / 2 + 30, 24, LIGHTGRAY);
		DrawText("Exit", 60 - 40, screenHeight / 2 + 75, 24, LIGHTGRAY);

		DrawText("P to pause", GetScreenWidth() / 2 - 60, screenHeight / 2 + 200, 20, LIGHTGRAY);

		EndDrawing();
	}
}
