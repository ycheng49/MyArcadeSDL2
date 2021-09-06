//
//  Utils.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/23/21.
//

#ifndef Utils_hpp
#define Utils_hpp

static const float EPSILON = 0.0001f;

const float PI = 3.14159f;
const float TWO_PI = 2.0f * PI;

bool IsEqual(float x, float y);

bool IsGreaterThanOrEqual(float x, float y);

bool IsLessThanOrEqual(float x, float y);

float MillisecondsToSeconds(unsigned int milliseconds);

unsigned int GetIndex(unsigned int width, unsigned int r, unsigned int c);

#endif /* Utils_hpp */
