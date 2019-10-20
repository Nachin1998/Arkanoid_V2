#ifndef MENU_H
#define MENU_H
#include "raylib.h"

const int cant = 5;

struct MenuButton {
	Rectangle rec;
	Color color;
};

extern MenuButton menuButtons[cant];
extern bool controlsActive;
extern bool creditsActive;

void setButtons();
void drawMainMenu();
void buttonSelection();
void drawControls();
void drawMenuCredits();

#endif