#include "Game.h"

SDL_Texture* tex;
SDL_Rect srcRect, dstRect;

void Game::init(const char* title, int w, int h, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		SDL_Log("SDL Init successful~");
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags);
		if (window)
		{
			SDL_Log("Window created~");
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_Log("Renderer created~");
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	SDL_Surface* tempSurface = IMG_Load("./assets/player.png");
	if (!tempSurface)
	{
		SDL_Log("load failed,%s", SDL_GetError());
	}
	tex = SDL_CreateTextureFromSurface(renderer,tempSurface);
	SDL_FreeSurface(tempSurface);

	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = 32;

	dstRect.x = dstRect.y = 0;
	dstRect.w = dstRect.h = 64;
}

void Game::clean()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::update()
{
	dstRect.x++;
	dstRect.y++;
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer,255, 255, 255, 255);
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, tex, &srcRect, &dstRect);

	SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
	SDL_Event events;
	if (SDL_PollEvent(&events))
	{
		if (events.type == SDL_QUIT)
		{
			isRunning = false;
		}
	}
}

bool Game::running()
{
	return isRunning;
}
