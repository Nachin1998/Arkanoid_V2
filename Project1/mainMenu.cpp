#include "mainMenu.h"
#include <iostream>
#include "Header.h"

using namespace game;
MenuButton menuButtons[cant];

bool controlsActive = false;
bool menuCreditsActive = false;

void setButtons() {

	for (int i = 0; i < cant; i++)
	{
		menuButtons[i].rec.x = 20;
		menuButtons[i].rec.height = 24;
		menuButtons[i].color = LIGHTGRAY;
	}

	menuButtons[0].rec.y = 165;  //Play button
	menuButtons[0].rec.width = 50;

	menuButtons[1].rec.y = 210;  //Controls button
	menuButtons[1].rec.width = 105;

	menuButtons[2].rec.y = 255;  //Credits button
	menuButtons[2].rec.width = 90;

	menuButtons[3].rec.y = 300;  //Exit button
	menuButtons[3].rec.width = 115;

	menuButtons[4].rec.x = 492;  //Close button
	menuButtons[4].rec.y = 290;
	menuButtons[4].rec.width = 50;
	menuButtons[4].rec.height = 19;
}

void buttonSelection() {
	for (int i = 0; i < cant; i++)
	{
		if (!CheckCollisionPointRec(GetMousePosition(), menuButtons[i].rec))
			menuButtons[i].color = LIGHTGRAY;
		else
			menuButtons[i].color = BLUE;

		if (CheckCollisionPointRec(GetMousePosition(), menuButtons[i].rec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			menuButtons[i].color = DARKBLUE;

			switch (i)
			{
			case 0:
				actualScene = Gameplay;
				break;
			case 1:  //Controls button
				if (menuCreditsActive) {
					menuCreditsActive = false;
					controlsActive = true;
				}
				else
					controlsActive = true;
				break;

			case 2:  //Credits button
				if (controlsActive) {
					controlsActive = false;
					menuCreditsActive = true;
				}
				else
					menuCreditsActive = true;
				break;

			case 3:  //Exit button
				exit(0);
				break;

			case 4:  //Close button
				if (controlsActive) {
					controlsActive = false;
				}
				if (menuCreditsActive) {
					menuCreditsActive = false;
				}
				break;
			}
		}
	}
	
}

void drawMainMenu() {

	SetTargetFPS(60);
	setButtons();
	

	while (!WindowShouldClose())
	{
		//BeginDrawing();
		buttonSelection();
		ClearBackground(BLACK);

		drawControls();
		drawMenuCredits();

		DrawText("Nark-anoid", menuButtons[0].rec.x, 20, 70, WHITE);

		DrawText("Play", menuButtons[0].rec.x, menuButtons[0].rec.y, menuButtons[0].rec.height, menuButtons[0].color);
		DrawText("Controls", menuButtons[1].rec.x, menuButtons[1].rec.y, menuButtons[1].rec.height, menuButtons[1].color);
		DrawText("Credits", menuButtons[2].rec.x, menuButtons[2].rec.y, menuButtons[2].rec.height, menuButtons[2].color);
		DrawText("Exit game", menuButtons[3].rec.x, menuButtons[3].rec.y, menuButtons[3].rec.height, menuButtons[3].color);

		//Color change
		EndDrawing();
	}
}


void drawControls() {

	if (controlsActive) {
		DrawText("Controls", 450, 150, 31, LIGHTGRAY);
		DrawText("A,D, Left/Right arrow", 420, 200, 19, LIGHTGRAY);
		DrawText("Space to shoot ball", 432, 230, 19, LIGHTGRAY);

		DrawText("Close", menuButtons[4].rec.x, menuButtons[4].rec.y, menuButtons[4].rec.height, menuButtons[4].color);
	}
}


void drawMenuCredits() {

	if (menuCreditsActive) {
		DrawText("Credits", 460, 100, 31, LIGHTGRAY);
		DrawText("Lead Programmer", 350, 150, 19, LIGHTGRAY);
		DrawText("Ignacio Fernandez Lemos", 540, 150, 19, LIGHTGRAY);
		DrawText("Library", 435, 230, 19, LIGHTGRAY);
		DrawText("RayLib", 540, 230, 19, LIGHTGRAY);

		DrawText("Close", menuButtons[4].rec.x, menuButtons[4].rec.y, menuButtons[4].rec.height, menuButtons[4].color);
	}
}