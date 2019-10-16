#ifndef MENU_H
#define MENU_H
#include "raylib.h"

const int cant = 5;

struct Button {
	Rectangle rec;
	Color color;
};

extern Button buttons[cant];
extern bool controlsActive;
extern bool creditsActive;

void setButtons();
void mainMenu();
void controls();
void credits();

#endif