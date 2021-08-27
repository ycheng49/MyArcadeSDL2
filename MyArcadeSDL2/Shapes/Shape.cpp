//
//  Shape.cpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/26/21.
//

#include "Shape.hpp"

void Shape::MoveBy(const Vec2D& deltaOffset)
{
    for(Vec2D& point : mPoints)
    {
        point = point + deltaOffset;
    }
}
