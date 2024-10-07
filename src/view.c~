#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

SDL_Window *init_view(char *name)
{
	SDL_Window *window = NULL;
	window =
	    SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED,
			     SDL_WINDOWPOS_CENTERED, 640, 480,
			     SDL_WINDOW_SHOWN);
	return window;
}

SDL_Renderer *init_renderer(SDL_Window * window)
{
	SDL_Renderer *renderer =
	    SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	return renderer;
}

SDL_Texture *load_picture(char *url, SDL_Renderer * renderer)
{
	SDL_Surface *image = SDL_LoadBMP(url);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
	return texture;
}

void display_picture(SDL_Renderer * renderer, SDL_Texture * texture, int x,
		     int y, int w, int h)
{
	SDL_Rect params = { x, y, w, h };
	SDL_RenderCopy(renderer, texture, NULL, &params);
}

void clear_renderer(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}
