#ifndef	HEADER_H
#define HEADER_H
#include <iostream>

namespace game {
	using namespace std;
	const int PLAYER_MAX_LIFE = 5;

	static const int screenWidth = 800;
	static const int screenHeight = 450;

	enum GameScreen {
		Menu,
		Gameplay,
		Credits
	};

	void play();

	void UpdateDrawFrame();  // Update and Draw (one frame)
	void InitGame();
	void Update();
	void setAllParameters();
	void Draw();
	void UnloadGame();
	extern GameScreen actualScene;
}

#endif