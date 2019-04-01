#include "pch.h"
#include<iostream>

extern "C" {
#include "libavcodec/avcodec.h";
#include "SDL/SDL.h";
#include"SDL/SDL_ttf.h"

}
int main(int argv, char* argc[]) {


	const int SCREEN_WIDTH = 680;
	const int SCREEN_HEIGHT = 400;

	SDL_Window *window = SDL_CreateWindow("Font Test",
	   SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


	int ret = TTF_Init();
	if (ret < 0) {
		printf("error when init ttf");
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	TTF_Font *font = TTF_OpenFont("blackfont.ttf", 30);

	SDL_Color color = { 255, 255, 255 };


	SDL_Surface *surf = TTF_RenderText_Blended(font, avcodec_configuration(), color);

	SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	TTF_CloseFont(font);

	bool quit = false;
	SDL_Event e;
	while (!quit)
	{
		//事件栈轮询
		while (SDL_PollEvent(&e))
		{
			//按右上角的X或点鼠标退出
			if (e.type == SDL_QUIT || e.type == SDL_MOUSEBUTTONDOWN) quit = true;
			//清空渲染器
			SDL_RenderClear(renderer);
			//渲染字体
			SDL_RenderCopy(renderer, text, NULL, NULL);
			//呈现渲染器
			SDL_RenderPresent(renderer);
		}
	}

	//释放资源
	SDL_DestroyTexture(text);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
