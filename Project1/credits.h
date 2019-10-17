#ifndef	CREDITS_H
#define CREDITS_H
#include "raylib.h"

const int creditsButtonCant = 3;

struct CreditsButton {
	Rectangle rec;
	Color color;
};

extern CreditsButton creditsButtons[creditsButtonCant];

void setCreditsButtons();
void endingCredits();
#endif
