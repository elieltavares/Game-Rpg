/*
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
bool Init();
bool LoadMedia();
void Close();
SDL_Window* window = NULL;
SDL_Surface* ScreenSurface = NULL;
SDL_Surface* image = NULL;
SDL_Event* event = new SDL_Event();

int main(int argc, char* argv[])
{
    bool quit = false;

    if(!Init())
    {
        std::cout << "Erro ao carregar o Init";
    }
    else
    {
        if(!LoadMedia())
        {
            std::cout << "Erro ao carregar LoadMedia";
        }
        else
        {

            while(!quit)
            {
            if(event->type == SDL_QUIT)
            {
                quit = true;
            }
            SDL_PollEvent(event);
            SDL_BlitSurface(image,NULL,ScreenSurface,NULL);
            SDL_UpdateWindowSurface(window);
            //SDL_Delay(2000);
            }
        }



    }
    Close();

    return 0;

}
bool Init()
{
    bool suscess = true;
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Erro ao iniciar o video"<<SDL_GetError();
        suscess = false;
    }

    else
    {
        window = SDL_CreateWindow("Janela",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,640,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if(window == NULL)
        {
            std::cout << "Erro a criar o windows"<< SDL_GetError();
            suscess = false;
        }
        else
        {
            ScreenSurface = SDL_GetWindowSurface(window);
        }
    }
    return suscess;

}
bool LoadMedia()
{
    bool suscess = true;
    image = SDL_LoadBMP("hello_world.bmp");
    if(image == NULL)
    {
        std::cout << "erro ao carregar image"<<SDL_GetError();
        suscess = false;
    }

    return suscess;
}
void Close()
{
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_FreeSurface(image);
    image = NULL;
    SDL_Quit();
}
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "include/Setup.h"
#include "include/Desenhar.h"
#include "include/character.h"
#include <iostream>



int main(int argc, char* argv[])
{



    Setup* setup = new Setup();
    SDL_Renderer* renderer;
    renderer = setup->GetRenderer();

    Desenhar* grama = new Desenhar(setup->GetRenderer(),"data/textura/grama/grama_2.png",0,0,800,640);
    Desenhar* casa = new Desenhar(setup->GetRenderer(),"data/textura/casa/casa.png",100,150,300,300);
    Desenhar* casa_dentro_paderes_01 = new Desenhar(setup->GetRenderer(),"data/textura/casa/casa_dentro_paredes_01.png",0,0,800,640);
    Desenhar* casa_dentro_paderes_02 = new Desenhar(setup->GetRenderer(),"data/textura/casa/casa_dentro_paredes_02.png",0,0,800,640);
    Desenhar* casa_dentro_chao = new Desenhar(setup->GetRenderer(),"data/textura/casa/casa_dentro_chao.png",0,0,800,640);
    character* person = new character(renderer,"data/textura/personagem/person.png",50,50,80,80);
// criar classe propria para npc
    character* npc_1 = new character(setup->GetRenderer(),"data/textura/personagem/npc_1.png",700,80,80,80);

    bool tecla_s = false;
    bool tecla_w = false;
    bool tecla_a = false;
    bool tecla_d = false;

    int cena = 1;


    int velocidade = 1;
    int AnimationVelocidade = 200;

    bool quit = false;
    while(!quit)
    {
        if(setup->GetEvent()->type == SDL_QUIT)
        {
            quit = true;
        }
        else
        {



            if(tecla_s)
            {
                person->SetY(person->GetY() + velocidade);
                person->animation(0,2,0,AnimationVelocidade);
            }
            if(tecla_w)
            {
                person->SetY(person->GetY() - velocidade);
                person->animation(0,2,3,AnimationVelocidade);
            }
            if(tecla_a)
            {
                person->SetX(person->GetX() - velocidade);
                person->animation(0,2,1,AnimationVelocidade);
            }
            if(tecla_d)
            {
                person->SetX(person->GetX() + velocidade);
                person->animation(0,2,2,AnimationVelocidade);
            }

        switch(setup->GetEvent()->type)
            {

                case SDL_KEYDOWN:
                    switch(setup->GetEvent()->key.keysym.sym)
                    {
                        case SDLK_s:
                            tecla_s = true;
                        break;
                        case SDLK_w:
                            tecla_w = true;
                            break;
                        case SDLK_a:
                            tecla_a = true;
                            break;
                        case SDLK_d:
                            tecla_d = true;
                            break;
                        case SDLK_ESCAPE:
                            quit = true;
                            break;

                        case SDLK_LSHIFT:
                            velocidade = 2;
                            AnimationVelocidade = 100;
                            break;


                    }
                    break;
                case SDL_KEYUP:
                    switch(setup->GetEvent()->key.keysym.sym)
                    {
                        case SDLK_s:
                            tecla_s = false;
                            //person->animation(0,2,0,100);
                        break;
                        case SDLK_w:
                            tecla_w = false;
                            //person->animation(0,2,3,100);
                            break;
                        case SDLK_a:
                            tecla_a = false;
                            //person->animation(0,2,1,100);
                            break;
                        case SDLK_d:
                            tecla_d = false;
                            //person->animation(0,2,2,100);
                            break;
                        case SDLK_LSHIFT:
                            velocidade = 1;
                            AnimationVelocidade = 200;

                    }
                    break;


            }
            std::cout <<"X: "<< person->GetX() << "     Y: "<<person->GetY()<<std::endl;

if(cena == 1)
{
            if(person->GetX() >= 40 && person->GetX() < 269 && person->GetY() >= 70 && person->GetY() <= 300  )
            {
                tecla_d = false;
            }
            if(person->GetX() <= 380 && person->GetX() > 41 && person->GetY() >= 70 && person->GetY() <= 268  )
            {
                tecla_a = false;
            }
             if(person->GetX() <= 270 && person->GetX() > 41  && person->GetY() >= 268 && person->GetY() <= 308  )
            {
                tecla_a = false;
            }


            if(person->GetY() >= 68 &&  person->GetY() < 269 && person->GetX() >=42 && person->GetX() <= 378  )
            {
                tecla_s = false;
            }
            if(person->GetY() <= 310 && person->GetY() > 68 &&  person->GetX() >=42 && person->GetX() <= 268  )
            {
                tecla_w = false;
            }
            if(person->GetY() <= 270 && person->GetY() > 68 && person->GetX() >=268 && person->GetX() <= 378  )
            {
                tecla_w = false;
            }

            //////////////////
            if(person->GetX() >= 150 && person->GetX() <=170 && person->GetY() <= 340 && person->GetY() >=310  )
            {
                switch(setup->GetEvent()->type)
                    {

                case SDL_KEYDOWN:
                    switch(setup->GetEvent()->key.keysym.sym)
                    {
                        case SDLK_SPACE:
                            cena = 2;
                        break;

                    }
                }
            }

}
//////////////////////////////////////////////////////////////
if(cena == 2)
{
   if(person->GetX() < 85)
   {
        tecla_a = false;
   }
   if(person->GetY() < 30)
   {
        tecla_w = false;
   }


}
            //////////////////

            setup->Inicio();


            if(cena == 1){
            grama->Draw();
            casa->Draw();
            person->Draw();
            }
            if(cena == 2){

            casa_dentro_chao->Draw();
            casa_dentro_paderes_01->Draw();
            person->Draw();
            casa_dentro_paderes_02->Draw();
            }
            npc_1->Draw();









            setup->Fim();





        }


    }


    delete setup;
    delete grama;
    delete person;
    delete casa;
    delete casa_dentro_paderes_01;
    delete casa_dentro_paderes_02;
    delete casa_dentro_chao;
    delete npc_1;



    return 0;
}

#
