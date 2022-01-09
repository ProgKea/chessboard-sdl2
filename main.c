#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

#define SQUARE_SIZE 90

SDL_Window *win;
SDL_Renderer *renderer;
char *position;
SDL_Texture *bP;

void init()
{
  SDL_Init(SDL_INIT_EVERYTHING);

  win = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SQUARE_SIZE * 8, SQUARE_SIZE * 8, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(win, -1, 0);
}

void draw_chessboard()
{
  SDL_Rect rect;

  rect.h = SQUARE_SIZE;
  rect.w = SQUARE_SIZE;
  rect.x = 0;
  rect.y = 0;

  int row = 1;
  for (int i=0; i<=64; i++) {
    if ((row%2)==0 || row==1) {
      if (i%2 == 0) {
	SDL_SetRenderDrawColor(renderer, 165, 122, 96, 255);
      }
      else SDL_SetRenderDrawColor(renderer, 214, 177, 139, 255);
    }
    else {
      if (i%2 != 0) {
	SDL_SetRenderDrawColor(renderer, 165, 122, 96, 255);
      }
      else SDL_SetRenderDrawColor(renderer, 214, 177, 139, 255);
    }
    SDL_RenderFillRect(renderer, &rect);
    rect.x += SQUARE_SIZE;
    if (i%8 == 0 && i!=0) {
      rect.y += SQUARE_SIZE;
      rect.x = 0;
      row++;
    }
  }
}

int main()
{
  init();

  // main loop
  while (1) {
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
	break;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q)
	break;
    }
    SDL_RenderClear(renderer);
    draw_chessboard();
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);

  SDL_Quit();
  return 0;
}
