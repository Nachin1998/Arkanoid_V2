#ifndef BALL_H
#define	BALL_H
#include "raylib.h"

namespace game {
	struct Ball {
		Vector2 position;
		Vector2 speed;
		int radius;
		bool active;
	};

	void setBallParameters();
	extern Ball ball;
}
#endif