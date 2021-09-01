//
//  BreakOut.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/30/21.
//

#ifndef BreakOut_hpp
#define BreakOut_hpp

#include <vector>

#include "Game.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "LevelBoundary.hpp"
#include "BreakOutGameLevel.hpp"

enum BreakOutGameState
{
    IN_PLAY = 0,
    IN_SERVE,
    IN_GAME_OVER
};

class BreakOut : public Game
{
public:
    
    virtual void Init(GameController& controller) override;
    virtual void Update(uint32_t dt) override;
    virtual void Draw(Screen& screen) override;
    virtual const std::string& GetName() const override;
    
private:
    
    void ResetGame();
    
    BreakOutGameLevel& GetCurrentLevel() {return mLevels[mCurrentLevel];}
    
    void SetToServeState();
    
    const float INITIAL_BALL_SPEED = 100;
    const Vec2D INITIAL_BALL_VEL = Vec2D(100, -100);
    
    Paddle mPaddle;
    Ball mBall;
    LevelBoundary mLevelBoundary;
    std::vector<BreakOutGameLevel> mLevels;
    size_t mCurrentLevel;
    
    BreakOutGameState mGameState;
};

#endif /* BreakOut_hpp */
