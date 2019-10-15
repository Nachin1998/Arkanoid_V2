#ifndef BRICKS_H
#define	BRICKS_H
#include "raylib.h"

const int LINES_OF_BRICKS = 5;
const int BRICKS_PER_LINE = 20;

static Vector2 brickSize = { 0 };

struct Brick {
	Rectangle rec;
	Vector2 position;
	Color color;
	bool active;
};

extern Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE];
extern int initialDownPosition;
void setBrickParameters();
#endif