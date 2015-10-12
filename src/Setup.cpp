#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/Setup.h"

Setup::Setup()
{
    event = new SDL_Event();
    titulo = "Game For Linux";
    window = SDL_CreateWindow(titulo,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,640,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}

Setup::~Setup()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete event;
}
SDL_Renderer* Setup::GetRenderer()
{
    return renderer;
}
SDL_Event* Setup::GetEvent()
{
    return event;
}

void Setup::Inicio()
{
        SDL_PollEvent(event);
        SDL_RenderClear(renderer);
}
void Setup::Fim()
{
    SDL_RenderPresent(renderer);
}
