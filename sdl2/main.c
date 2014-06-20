#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include <assert.h>

int main() {
	SDL_Window * window;
	SDL_Renderer * renderer;
	TTF_Font * font;
	SDL_Surface * surface;
	SDL_Texture * cecilia;
	SDL_Texture * button;
	SDL_Texture * damien;
	SDL_Event e;
	SDL_Color black = {0, 0, 0, 255};
	SDL_Rect dst;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
		"Font Test", 
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1024,
		800,
		0);

	renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	TTF_Init();

	font = TTF_OpenFont("../CaviarDreams.ttf", 40);

	surface = TTF_RenderUTF8_Blended(font, "CECILIA", black);
	cecilia = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("../UI-button-next.png");
	button = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("../damien.png");
	damien = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

        dst.x = 100;
        dst.y = 100;
	SDL_QueryTexture(cecilia, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(renderer, cecilia, NULL, &dst);

	dst.x = 300;
	dst.y = 100;
	SDL_QueryTexture(button, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(renderer, button, NULL, &dst);

	dst.x = 500;
	dst.y = 100;
	dst.w = dst.w / 2;
	dst.h = dst.h / 2;
	SDL_RenderCopy(renderer, button, NULL, &dst);

	dst.x = 600;
	dst.y = 10;
	SDL_QueryTexture(damien, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(renderer, damien, NULL, &dst);

	dst.x = 150;
	dst.y = 300;
	dst.w = dst.w / 2;
	dst.h = dst.h / 2;
	SDL_QueryTexture(damien, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(renderer, damien, NULL, &dst);

	dst.x = 30;
	dst.y = 200;
	dst.w = dst.w / 2;
	dst.h = dst.h / 2;
	SDL_RenderCopy(renderer, damien, NULL, &dst);

	dst.x = 510;
	dst.y = 200;
	dst.w = dst.w / 2;
	dst.h = dst.h / 2;
	SDL_RenderCopy(renderer, damien, NULL, &dst);

	SDL_RenderPresent(renderer);	

	while (!SDL_PollEvent(&e) || e.type != SDL_QUIT);
}

