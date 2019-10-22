#ifndef MENU_H
#define MENU_H
#include "raylib.h"

namespace game {
	const int cant = 5;

	struct MenuButton {
		Rectangle rec;
		Color color;
	};

	extern MenuButton menuButtons[cant];
	extern bool controlsActive;
	extern bool creditsActive;
	extern bool gameOver;
	extern bool pause;

	void setButtons();
	void drawMainMenu();
	void buttonSelection();
	void drawControls();
	void drawMenuCredits();
}

#endif