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
    
    const int NUM_LIVES = 3;
    
    void ResetGame(size_t toLevel = 0);
    
    BreakOutGameLevel& GetCurrentLevel() {return mLevels[mCurrentLevel];}
    
    void SetToServeState();
    
    bool IsBallPassedCutOffY() const;
    
    void ReduceLifeByOne();
    
    bool IsGameOver() const {return mLives < 0;}
    
    const float INITIAL_BALL_SPEED = 100;
    const Vec2D INITIAL_BALL_VEL = Vec2D(100, -100);
    
    Paddle mPaddle;
    Ball mBall;
    LevelBoundary mLevelBoundary;
    std::vector<BreakOutGameLevel> mLevels;
    size_t mCurrentLevel;
    
    BreakOutGameState mGameState;
    
    int mLives;
    
    float mYCutOff;
};

#endif /* BreakOut_hpp */
