#include "bricks.h"
#include "gameManager.h"
Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE];

void setBrickParameters() {
	brickSize = { screenWidth / BRICKS_PER_LINE, 40 };

	int initialDownPosition = 50;

	for (int i = 0; i < LINES_OF_BRICKS; i++)
	{
		for (int j = 0; j < BRICKS_PER_LINE; j++)
		{
			brick[i][j].position = { j*brickSize.x + brickSize.x / 2, i*brickSize.y + initialDownPosition };
			brick[i][j].active = true;
		}
	}
}