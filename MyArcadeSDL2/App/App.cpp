//
//  App.cpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/28/21.
//

#include <SDL2/SDL.h>

#include "App.hpp"
#include "Line2D.hpp"
#include "Triangle.hpp"
#include "AARectangle.hpp"
#include "Circle.hpp"
#include "Color.hpp"

App& App::Singleton()
{
    static App theApp;
    return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
    mnoptrWindow = mScreen.Init(width, height, mag);
    
    return mnoptrWindow != nullptr;
}

void App::Run()
{
    if(mnoptrWindow)
    {
        Line2D line = {Vec2D(0,0), Vec2D(mScreen.Width(), mScreen.Height())};
        mScreen.Draw(line, Color::White());
        
        Triangle triangle = {Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110)};
        mScreen.Draw(triangle, Color::Red(), true, Color::Red());
        
        AARectangle rect = {Vec2D(mScreen.Width() / 2 - 25, mScreen.Height() / 2 - 25), 50, 50};
        mScreen.Draw(rect, Color::Blue(), true, Color::Blue());
        
        Circle circle = {Vec2D(mScreen.Width() / 2 + 50, mScreen.Height() / 2 + 50), 50};
        mScreen.Draw(circle, Color(0, 255, 0, 150), true, Color(0, 255, 0, 150));
        
        mScreen.SwapScreens();
        
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
    }
}
