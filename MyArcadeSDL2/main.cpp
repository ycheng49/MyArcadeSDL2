//
//  main.cpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/21/21.
//

#include <iostream>
#include <SDL2/SDL.h>

#include "Color.hpp"
#include "Screen.hpp"
#include "Line2D.hpp"
#include "Triangle.hpp"
#include "AARectangle.hpp"
#include "Circle.hpp"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 2;

int main(int argc, const char * argv[])
{
    Screen theScreen;
    
    theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
    
    // theScreen.Draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Yellow());
    
    Line2D line = {Vec2D(0,0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT)};
    theScreen.Draw(line, Color::White());
    
    Triangle triangle = {Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110)};
    theScreen.Draw(triangle, Color::Red(), true, Color::Red());
    
    AARectangle rect = {Vec2D(SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT / 2 - 25), 50, 50};
    theScreen.Draw(rect, Color::Blue(), true, Color::Blue());
    
    Circle circle = {Vec2D(SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT / 2 + 50), 50};
    theScreen.Draw(circle, Color(0, 255, 0, 150), true, Color(0, 255, 0, 150));
    
    theScreen.SwapScreens();
    
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
    
    return 0;
}


