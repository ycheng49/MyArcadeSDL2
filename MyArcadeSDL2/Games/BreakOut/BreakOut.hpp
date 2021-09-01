//
//  BreakOut.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/30/21.
//

#ifndef BreakOut_hpp
#define BreakOut_hpp

#include "Game.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "LevelBoundary.hpp"
#include "BreakOutGameLevel.hpp"

class BreakOut : public Game
{
public:
    
    virtual void Init(GameController& controller) override;
    virtual void Update(uint32_t dt) override;
    virtual void Draw(Screen& screen) override;
    virtual const std::string& GetName() const override;
    
private:
    
    void ResetGame();
    
    const Vec2D INITIAL_BALL_VEL = Vec2D(100, -100);
    
    Paddle mPaddle;
    Ball mBall;
    LevelBoundary mLevelBoundary;
    BreakOutGameLevel mLevel;
};

#endif /* BreakOut_hpp */
