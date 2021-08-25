//
//  main.cpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/21/21.
//

#include <iostream>
#include <SDL2/SDL.h>

/*
 To install SDL2:
 1. go to website brew.sh, and use terminal to install homebrew
 2. in terminal, type "brew install sdl2" to install SDL2
 
 To use SDL2 in a project (xcode):
 1. create a project in xcode
 2. go to targets
        -> build settings
        -> type "search" in search bar
        -> add "/usr/local/include" in Header Search Paths
 3. go to build phases
        -> link binary with libraries, and add
        -> add others, add files
        -> press "cmd + shift + g" at the pop up window
        -> go to the folder "/usr/local/Cellar"
        -> choose "sdl2/2.0.16/lib/libSDL2-2.0.0.dylib"
 4. we now can type #include <SDL2/SDL.h> to use it
 */

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;

int main(int argc, const char * argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "Error SDL_Init Failed" << std::endl;
        return 1;
    }
    
    SDL_Window* optrWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    
    if(optrWindow == nullptr)
    {
        std::cout << "Could not create window, got error: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    SDL_Event sdlEvent;
    bool running = true;
    
    while(running)
    {
        while(SDL_PollEvent(&sdlEvent))
        {
            switch (sdlEvent.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
    }
    
    SDL_DestroyWindow(optrWindow);
    SDL_Quit();
    
    return 0;
}
