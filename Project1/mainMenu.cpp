#include "mainMenu.h"
#include "gameManager.h"
#include <iostream>

Button buttons[cant];

void setButtons() {

	for (int i = 0; i < cant; i++)
	{
		buttons[i].rec.x = 20;
		buttons[i].rec.height = 24;
		buttons[i].color = LIGHTGRAY;
	}

	buttons[0].rec.y = screenHeight / 2 - 60;  //Play button
	buttons[0].rec.width = 50;

	buttons[1].rec.y = screenHeight / 2 - 15;  //Controls button
	buttons[1].rec.width = 105;

	buttons[2].rec.y = screenHeight / 2 + 30;  //Credits button
	buttons[2].rec.width = 90;

	buttons[3].rec.y = screenHeight / 2 + 75;  //Exit button
	buttons[3].rec.width = 115;

}

void mainMenu() {

	SetTargetFPS(60);
	setButtons();
	
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		DrawText("Nark-anoid", buttons[0].rec.x, screenHeight / 2 - 200, 50, LIGHTGRAY);
		DrawText("Play", buttons[0].rec.x, buttons[0].rec.y, buttons[0].rec.height, buttons[0].color);
		DrawText("Controls", buttons[1].rec.x, buttons[1].rec.y, buttons[1].rec.height, buttons[1].color);
		DrawText("Credits", buttons[2].rec.x, buttons[2].rec.y, buttons[2].rec.height, buttons[2].color);
		DrawText("Exit game", buttons[3].rec.x, buttons[3].rec.y, buttons[3].rec.height, buttons[3].color);

		//Color change
		for (int i = 0; i < cant; i++)
		{
			if (!CheckCollisionPointRec(GetMousePosition(), buttons[i].rec))
				buttons[i].color = LIGHTGRAY;
			else
				buttons[i].color = BLUE;

			if (CheckCollisionPointRec(GetMousePosition(), buttons[i].rec) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
				buttons[i].color = DARKBLUE;
				if (i == 3)exit(0);
			}
		}

		DrawText("P to pause", GetScreenWidth() / 2 - 60, screenHeight / 2 + 200, 20, LIGHTGRAY);

		EndDrawing();
	}
}
