//
//  main.cpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/21/21.
//

#include <iostream>
#include "Vec2D.hpp"

int main(int argc, const char * argv[])
{
    Vec2D vec1 = Vec2D::Zero;
    Vec2D vec2 = Vec2D(1,1);
    
    std::cout << vec1.AngleBetween(vec2) << std::endl;
    
    return 0;
}
