//
//  Screen.cpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/26/21.
//

#include <SDL2/SDL.h>
#include <cassert>

#include "Screen.hpp"
#include "Vec2D.hpp"

Screen::Screen(): mWidth(0), mHeight(0), moptrWindow(nullptr), mnoptrWindowSurface(nullptr)
{
    
}

Screen::~Screen()
{
    if(moptrWindow)
    {
        SDL_DestroyWindow(moptrWindow);
        moptrWindow = nullptr;
    }
    
    SDL_Quit();
}

SDL_Window* Screen::Init(uint32_t w, uint32_t h, uint32_t mag)
{
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "Error SDL_Init Failed" << std::endl;
        return nullptr;
    }
    
    mWidth = w;
    mHeight = h;
    
    // mag makes the window bigger, but with the same pixel resolution
    moptrWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWidth * mag, mHeight * mag, 0);
    
    if(moptrWindow)
    {
        mnoptrWindowSurface = SDL_GetWindowSurface(moptrWindow);
        
        SDL_PixelFormat* pixelFormat = mnoptrWindowSurface->format;
        
        Color::InitColorFormat(pixelFormat);
        
        mClearColor = Color::Black();
        
        mBackBuffer.Init(pixelFormat->format, mWidth, mHeight);
        
        mBackBuffer.Clear(mClearColor);
    }
    
    return moptrWindow;
}

void Screen::SwapScreens()
{
    assert(moptrWindow);
    
    if(moptrWindow)
    {
        // clear the current front facing surface
        ClearScreen();
        
        // copy content from one surface to another surcace
        // use BlitScaled method to scale the back buffer content to the front window
        SDL_BlitScaled(mBackBuffer.GetSurface(), nullptr, mnoptrWindowSurface, nullptr);
                                
        // actually draw the surface
        SDL_UpdateWindowSurface(moptrWindow);
        
        mBackBuffer.Clear(mClearColor);
    }
}

void Screen::Draw(int x, int y, const Color& color)
{
    assert(moptrWindow);
    
    if(moptrWindow)
    {
        mBackBuffer.SetPixel(color, x, y);
    }
}

void Screen::Draw(const Vec2D& point, const Color& color)
{
    assert(moptrWindow);
    
    if(moptrWindow)
    {
        mBackBuffer.SetPixel(color, point.GetX(), point.GetY());
    }
}

void Screen::ClearScreen()
{
    assert(moptrWindow);
    
    if(moptrWindow)
    {
        SDL_FillRect(mnoptrWindowSurface, nullptr, mClearColor.GetPixelColor());
    }
}
