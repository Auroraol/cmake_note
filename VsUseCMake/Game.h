#pragma once
#include<SDL.h>
#include<SDL_image.h>
class Game
{

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning = false;
public:
	//初始化
	void init(const char* title, int w, int h, int flags = SDL_WINDOW_SHOWN);
	//清理
	void clean();
	//更新
	void update();
	//渲染
	void render();
	//处理事件
	void handleEvents();
	//是否在运行
	bool running();

};

