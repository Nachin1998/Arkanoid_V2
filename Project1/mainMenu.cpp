#include "mainMenu.h"
#include "gameManager.h"
#include <iostream>

Button buttons[cant];

bool controlsActive = false;
bool creditsActive = false;

void setButtons() {

	for (int i = 0; i < cant; i++)
	{
		buttons[i].rec.x = 20;
		buttons[i].rec.height = 24;
		buttons[i].color = LIGHTGRAY;
	}

	buttons[0].rec.y = 165;  //Play button
	buttons[0].rec.width = 50;

	buttons[1].rec.y = 210;  //Controls button
	buttons[1].rec.width = 105;

	buttons[2].rec.y = 255;  //Credits button
	buttons[2].rec.width = 90;

	buttons[3].rec.y = 300;  //Exit button
	buttons[3].rec.width = 115;

	buttons[4].rec.x = 492;  //Close button
	buttons[4].rec.y = 290;
	buttons[4].rec.width = 115;
	buttons[4].rec.height = 19;

}

void mainMenu() {

	SetTargetFPS(60);
	setButtons();
	
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		controls();

		DrawText("Nark-anoid", buttons[0].rec.x, 25, 50, WHITE);
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

			if (CheckCollisionPointRec(GetMousePosition(), buttons[i].rec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				buttons[i].color = DARKBLUE;

				switch (i)
				{
				case 1:
					controlsActive = true;
					controls();
					break;

				case 2:
					creditsActive = true;
					credits();
					break;

				case 3:
					exit(0);
					break;

				case 4:
					if (controlsActive) {
						controlsActive = false;
					}
					if (creditsActive) {
						creditsActive = false;
					}
					break;
				}
			}
		}
		EndDrawing();
	}
}

void controls() {
		
	if (controlsActive) {
		DrawText("Controls", 450, 150, 31, LIGHTGRAY);
		DrawText("A,D, Left/Right arrow", 420, 200, 19, LIGHTGRAY);
		DrawText("Space to shoot ball", 432, 230, 19, LIGHTGRAY);

		DrawText("Close", buttons[4].rec.x, buttons[4].rec.y, buttons[4].rec.height, buttons[4].color);
	}
}

void credits() {

	if (creditsActive) {
		DrawText("Credits", 450, 150, 31, LIGHTGRAY);
		DrawText("A,D, Left/Right arrow", 420, 200, 19, LIGHTGRAY);
		DrawText("Space to shoot ball", 432, 230, 19, LIGHTGRAY);

		DrawText("Close", buttons[4].rec.x, buttons[4].rec.y, buttons[4].rec.height, buttons[4].color);

		//DrawText("Close", 492, 290, 19, LIGHTGRAY);
	}
}
