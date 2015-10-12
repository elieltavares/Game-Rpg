#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "../include/character.h"

character::character(SDL_Renderer* passed_renderer,std::string FilePath, int x, int y, int w, int h)
{
    renderer = passed_renderer;
    person = IMG_LoadTexture(renderer,FilePath.c_str());


    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;


    SDL_QueryTexture(person,NULL,NULL,&crop_w,&crop_h);


    current = 0;




    AnimationDelay = SDL_GetTicks();

}

character::~character()
{
    SDL_DestroyTexture(person);
}
void character::Draw()
{
    SDL_RenderCopy(renderer,person,&crop,&rect);
}
//int BeginFrame, int EndFrame, int row,float speed
void character::animation(int BeginFrame,int EndFrame,int passo,int speed)
{
    int gettick = SDL_GetTicks();
    if(AnimationDelay+speed < gettick)
    {

        if(EndFrame <= current )
        {
            current = BeginFrame;
        }
        else
        current++;


        crop.x = current*crop_w/3;
        crop.y = passo*crop_h/4;
        crop.w = crop_w/3;
        crop.h = crop_h/4;

        AnimationDelay = SDL_GetTicks();

}

}


int character::GetX()
{
    return rect.x;
}
int character::GetY()
{
    return rect.y;
}
void character::SetX(int x)
{
    rect_x = x;
    rect.x = rect_x;

}
void character::SetY(int y)
{
    rect_y = y;
    rect.y = rect_y;
}

