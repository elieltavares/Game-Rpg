#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "../include/Desenhar.h"

Desenhar::Desenhar(SDL_Renderer* passed_renderer,std::string FilePath, int x, int y, int w, int h)
{
    renderer = passed_renderer;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;



    image = IMG_LoadTexture(renderer,FilePath.c_str());

}

Desenhar::~Desenhar()
{
    SDL_DestroyTexture(image);
}
void Desenhar::Draw()
{
    SDL_RenderCopy(renderer,image,NULL,&rect);
}
