#ifndef DESENHAR_H
#define DESENHAR_H
#include <string>
#include <SDL2/SDL.h>
class Desenhar
{
    public:
        Desenhar(SDL_Renderer* passed_renderer,std::string FilePath, int x, int y, int w, int h);
        ~Desenhar();
        void Draw();
    private:
        SDL_Texture* image;
        SDL_Rect rect;

        SDL_Renderer* renderer;
};

#endif // DESENHAR_H
