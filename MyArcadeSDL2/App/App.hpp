//
//  App.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/28/21.
//

#ifndef App_hpp
#define App_hpp

#include <stdint.h>

#include "Screen.hpp"

struct SDL_Window;

class App
{
public:
    
    static App& Singleton();
    
    bool Init(uint32_t width, uint32_t height, uint32_t mag);
    
    void Run();
    
    inline uint32_t Width() const {return mScreen.Width();}
    inline uint32_t Height() const {return mScreen.Height();}
    
private:
    
    Screen mScreen;
    SDL_Window* mnoptrWindow;
};

#endif /* App_hpp */
