//
//  Utils.cpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/23/21.
//

#include <cmath>

#include "Utils.hpp"

bool IsEqual(float x, float y)
{
    return fabsf(x - y) < EPSILON;
}

bool IsGreaterThanOrEqual(float x, float y)
{
    return x > y || IsEqual(x, y);
}

bool IsLessThanOrEqual(float x, float y)
{
    return x < y || IsEqual(x, y);
}
