//
//  Screen.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/26/21.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdint.h>

#include "ScreenBuffer.hpp"
#include "Color.hpp"

class Vec2D;

struct SDL_Window;
struct SDL_Surface;

class Screen
{
public:
    
    Screen();
    ~Screen();
    
    SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag);
    void SwapScreens();
    
    inline void SetClearColor(const Color& clearColor) {mClearColor = clearColor;}
    inline uint32_t Width() const {return mWidth;}
    inline uint32_t Height() const {return mHeight;}
    
    // Draw Methods go here
    void Draw(int x, int y, const Color& color);
    void Draw(const Vec2D& point, const Color& color);
    
private:
    
    Screen(const Screen& screen);
    Screen& operator=(const Screen& screen);
    
    void ClearScreen();
    
    uint32_t mWidth;
    uint32_t mHeight;
    
    Color mClearColor;
    ScreenBuffer mBackBuffer;
    
    SDL_Window* moptrWindow;
    SDL_Surface* mnoptrWindowSurface;
};

#endif /* Screen_hpp */
