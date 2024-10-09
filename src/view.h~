#ifndef VIEW_H
#define VIEW_H

#include <SDL2/SDL.h>

SDL_Window *init_view(char *name);

SDL_Renderer *init_renderer(SDL_Window * window);

void clear_renderer(SDL_Renderer * renderer);

SDL_Texture *load_picture(char *url, SDL_Renderer * renderer);

void display_picture(SDL_Renderer * renderer, SDL_Texture * texture, int x,
		     int y, int w, int h);

#endif
