//
//  main.cpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/21/21.
//

#include <iostream>

#include "App.hpp"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 2;

int main(int argc, const char * argv[])
{
    if(App::Singleton().Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION))
    {
        App::Singleton().Run();
    }
    
    return 0;
}


