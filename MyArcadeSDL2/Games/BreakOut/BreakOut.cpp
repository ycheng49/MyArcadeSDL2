//
//  BreakOut.cpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/30/21.
//


/*
    Paddle
        - Can move side to side (by the user)
        - Stop at the edge of the screen
        - Width and height
        - Bounce the ball
            - Bounce the ball differently based on the position that was hit on the paddle

            ---=======---
            +-----------+
            |           |
            +-----------+
 
    Ball
        - Bounce off of the walls and the paddle
        - Width and height
        - Velocity, position
 
    Block
        - Part of the level
        - Has HP: one hit by the ball is -1 HP
        - Color and position, width and height (AARectangle)
        - Bounce the ball
 
    Level
        - Container that holds all of the blocks
        - Should be able to load a level from the levels.txt file
        - Handle collisions of the blocks?
        - Contain the walls / edges of the screen?
        - Reset the level
 
    Game
        - Contains all of the objects (paddle, ball, levels)
        - Player which has 3 lives
        - States: serve the ball, in game, game over
        - Reset the game
 
 */


#include <iostream>

#include "BreakOut.hpp"
#include "GameController.hpp"
#include "App.hpp"

void BreakOut::Init(GameController& controller)
{
    controller.ClearAll();
    
    ResetGame();
    
    // serve the ball
    ButtonAction serveAction;
    
    serveAction.key = GameController::ActionKey();
    serveAction.action = [this](uint32_t dt, InputState state)
    {
        if(mGameState == IN_SERVE)
        {
            if(GameController::IsPressed(state))
            {
                mGameState = IN_PLAY;
                
                if(mPaddle.IsMovingLeft())
                {
                    mBall.SetVelocity(Vec2D(-INITIAL_BALL_SPEED, -INITIAL_BALL_SPEED));
                }
                else
                {
                    mBall.SetVelocity(Vec2D(INITIAL_BALL_SPEED, -INITIAL_BALL_SPEED));
                }
            }
        }
        else if(mGameState == IN_GAME_OVER)
        {
            if(GameController::IsPressed(state))
            {
                ResetGame();
            }
        }
    };
    
    controller.AddInputActionForKey(serveAction);
    
    // move the paddle left
    ButtonAction leftKeyAction;
    
    leftKeyAction.key = GameController::LeftKey();
    leftKeyAction.action = [this](uint32_t dt, InputState state)
    {
        if(mGameState == IN_PLAY || mGameState == IN_SERVE)
        {
            if(GameController::IsPressed(state))
            {
                mPaddle.SetMovementDirection(PaddleDirection::LEFT);
            }
            else
            {
                mPaddle.UnsetMovementDirection(PaddleDirection::LEFT);
            }
        }
    };
    
    controller.AddInputActionForKey(leftKeyAction);
    
    // move the paddle right
    ButtonAction rightKeyAction;
    
    rightKeyAction.key = GameController::RightKey();
    rightKeyAction.action = [this](uint32_t dt, InputState state)
    {
        if(mGameState == IN_PLAY || mGameState == IN_SERVE)
        {
            if(GameController::IsPressed(state))
            {
                mPaddle.SetMovementDirection(PaddleDirection::RIGHT);
            }
            else
            {
                mPaddle.UnsetMovementDirection(PaddleDirection::RIGHT);
            }
        }
    };
    
    controller.AddInputActionForKey(rightKeyAction);
}

void BreakOut::Update(uint32_t dt)
{
    if(mGameState == IN_SERVE)
    {
        mPaddle.Update(dt, mBall);
        
        SetToServeState();
    }
    else if(mGameState == IN_PLAY)
    {
        mBall.Update(dt);
        
        mPaddle.Update(dt, mBall);
        
        if(mPaddle.Bounce(mBall))
        {
            return;
        }
        
        BoundaryEdge edge;
        
        if(mLevelBoundary.HasCollided(mBall, edge))
        {
            mBall.Bounce(edge);
            
            return;
        }
        
        GetCurrentLevel().Update(dt, mBall);
    }
}

void BreakOut::Draw(Screen& screen)
{
    mBall.Draw(screen);
    mPaddle.Draw(screen);
    GetCurrentLevel().Draw(screen);
    
    screen.Draw(mLevelBoundary.GetAARectangle(), Color::White());
}

const std::string& BreakOut::GetName() const
{
    static std::string name = "Break Out!";
    
    return name;
}

void BreakOut::ResetGame()
{
    mLevels = BreakOutGameLevel::LoadLevelsFromFile(App::GetBasePath() + "Assets/BreakOutLevels.txt");
    
    mCurrentLevel = 2;
    
    AARectangle paddleRect = {Vec2D(App::Singleton().Width()/2 - Paddle::PADDLE_WIDTH/2, App::Singleton().Height() - 3*Paddle::PADDLE_HEIGHT), Paddle::PADDLE_WIDTH, Paddle::PADDLE_HEIGHT};
    AARectangle levelBoundary = {Vec2D::Zero, App::Singleton().Width(), App::Singleton().Height()};
    
    mLevelBoundary = {levelBoundary};
    
    mPaddle.Init(paddleRect, levelBoundary);
    
    mBall.MoveTo(Vec2D(App::Singleton().Width()/2.0f, App::Singleton().Height() * 0.75f));

    SetToServeState();
}

void BreakOut::SetToServeState()
{
    mGameState = IN_SERVE;
    
    mBall.Stop();
    mBall.MoveTo(Vec2D(mPaddle.GetAARectangle().GetCenterPoint().GetX(), mPaddle.GetAARectangle().GetTopLeftPoint().GetY() - mBall.GetRadius() - 1));
}
