//
//  Ball.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/31/21.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdint.h>

#include "AARectangle.hpp"

class Screen;

struct BoundaryEdge;

class Ball
{
public:
    
    Ball();
    Ball(const Vec2D& pos, float radius);
    
    void Update(uint32_t dt);
    void Draw(Screen& screen);
    void MakeFlushWithEdge(const BoundaryEdge& edge, Vec2D& pointOnEdge, bool limitToEdge);
    void MoveTo(const Vec2D& point);
    
    inline const AARectangle GetBoundingRect() const {return mBBox;}
    inline void Stop() {mVelocity = Vec2D::Zero;}
    inline void SetVelocity(const Vec2D& vel) {mVelocity = vel;}
    inline Vec2D GetVelocity() const {return mVelocity;}
    inline float GetRadius() const {return mBBox.GetWidth() / 2.0f;}
    inline Vec2D GetPosition() const {return mBBox.GetCenterPoint();}
    
private:
    
    AARectangle mBBox;          // the ball is internally described as a rectangle
    
    Vec2D mVelocity;
    
    static const float RADIUS;
};

#endif /* Ball_hpp */
