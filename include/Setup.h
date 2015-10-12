#ifndef SETUP_H
#define SETUP_H


class Setup
{
    public:
        Setup();
        ~Setup();
        SDL_Renderer* GetRenderer();
        SDL_Event* GetEvent();

        void Inicio();
        void Fim();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event* event;
        const char* titulo;
};

#endif // SETUP_H
