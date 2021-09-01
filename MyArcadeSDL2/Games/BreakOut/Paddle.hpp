//
//  Paddle.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/31/21.
//

#ifndef Paddle_hpp
#define Paddle_hpp

#include <stdint.h>

#include "Excluder.hpp"

class Screen;
class Ball;

enum PaddleDirection
{
    LEFT = 1 << 0,
    RIGHT = 1 << 1
};

class Paddle : public Excluder
{
public:
    
    static const uint32_t PADDLE_WIDTH = 50;
    static const uint32_t PADDLE_HEIGHT = 10;
    
    void Init(const AARectangle& rect, const AARectangle& boundary);
    
    void Update(uint32_t dt, Ball& ball);
    
    void Draw(Screen& screen);
    
    bool Bounce(Ball& ball);
    
    inline bool IsMovingLeft() const {return mDirection == PaddleDirection::LEFT;}
    inline bool IsMovingRight() const {return mDirection == PaddleDirection::RIGHT;}
    
    inline void SetMovementDirection(PaddleDirection dir) {mDirection |= dir;}
    inline void UnsetMovementDirection(PaddleDirection dir) {mDirection &= ~dir;}
    inline void StopMovement() {mDirection = 0;}
    
private:
    
    const float VELOCITY = 100.0f;      // pixels / second
    const float CORNER_BOUNCE_AMT = 0.2f;
    
    uint32_t mDirection;                // direction we are moving
    
    AARectangle mBoundary;              // boundary that the paddle is confined to
};

#endif /* Paddle_hpp */
