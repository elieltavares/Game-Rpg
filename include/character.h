#ifndef CHARACTER_H
#define CHARACTER_H
#include <SDL2/SDL.h>

class character
{
    public:
        character(SDL_Renderer* passed_renderer,std::string FilePath, int x, int y, int w, int h);
        ~character();
        void Draw();
        void animation(int BeginFrame,int EndFrame,int passo,int speed);
        int GetX();
        int GetY();
        void SetX(int x);
        void SetY(int y);

    private:
        SDL_Texture* person;

        SDL_Renderer* renderer;
        SDL_Rect rect;
        SDL_Rect crop;

        int crop_w;
        int crop_h;

        int rect_x;
        int rect_y;

        int AnimationDelay;
        int current;
};

#endif // CHARACTER_H
