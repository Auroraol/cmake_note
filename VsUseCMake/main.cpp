#include"Game.h"

int main(int argc,char *argv[])
{
	Game *game = new Game;
	game->init("SDL", 640, 480);

	const int FPS = 60;					//帧率
	const int frameDelay = 1000 / 60;	//每一帧应该消耗的事件 16.66ms

	Uint32 frameStart = 0;
	int frameTime = 0;

	while (game->running())
	{
		frameStart = SDL_GetTicks();	

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay - frameTime > 0)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();
	delete game;
	return 0;
}