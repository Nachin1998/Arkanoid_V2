#ifndef MENU_H
#define MENU_H
#include "raylib.h"

const int cant = 4;

struct Button {
	Rectangle rec;
	Color color;
};

extern Button buttons[cant];

void setButtons();
void mainMenu();

#endif