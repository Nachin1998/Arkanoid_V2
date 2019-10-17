#include "credits.h"
#include "mainMenu.h"
#include <iostream>
CreditsButton creditsButtons[creditsButtonCant];

void setCreditsButtons() {
	for (int i = 0; i < creditsButtonCant; i++)
	{
		creditsButtons[i].rec.y = 410;
		creditsButtons[i].color = WHITE;
		creditsButtons[i].rec.height = 30;
	}
	creditsButtons[0].rec.x = 140;
	creditsButtons[0].rec.width = 80;

	creditsButtons[1].rec.x = 305;
	creditsButtons[1].rec.width = 160;

	creditsButtons[2].rec.x = 570;
	creditsButtons[2].rec.width = 60;

}

void endingCredits() {
	setCreditsButtons();
	while (!WindowShouldClose())
	{
		ClearBackground(BLACK);

		DrawText("Credits", 265, 50, 60, LIGHTGRAY);

		//Hacer una funcion que sean los creditos y usarla aca y en el menu para no repetir los mismos creditos
		/*DrawText("Lead Programmer", 50, 150, 30, LIGHTGRAY);
		DrawText("Ignacio Fernandez", 450, 135, 30, LIGHTGRAY);
		DrawText("Lemos", 452, 165, 30, LIGHTGRAY);

		DrawText("Library", 200, 230, 30, LIGHTGRAY);
		DrawText("RayLib", 450, 230, 30, LIGHTGRAY);*/

		DrawText("Menu", creditsButtons[0].rec.x, creditsButtons[0].rec.y, creditsButtons[0].rec.height, creditsButtons[0].color);
		DrawText("Play again", creditsButtons[1].rec.x, creditsButtons[1].rec.y, creditsButtons[1].rec.height, creditsButtons[1].color);
		DrawText("Exit", creditsButtons[2].rec.x, creditsButtons[2].rec.y, creditsButtons[2].rec.height, creditsButtons[2].color);

		for (int i = 0; i < creditsButtonCant; i++)
		{
			if (!CheckCollisionPointRec(GetMousePosition(), creditsButtons[i].rec))
				creditsButtons[i].color = LIGHTGRAY;
			else
				creditsButtons[i].color = BLUE;

			if (CheckCollisionPointRec(GetMousePosition(), creditsButtons[i].rec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				creditsButtons[i].color = DARKBLUE;

				switch (i)
				{
				case 0:
					mainMenu();
					break;
				case 1:  //Play button
						 //Play game
					break;

				case 2:  //Exit button
					exit(0);
					break;
				}
				
			}
			EndDrawing();
		}
	}
}