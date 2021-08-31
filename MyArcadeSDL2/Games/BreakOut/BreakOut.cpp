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
    
    ButtonAction leftKeyAction;
    
    leftKeyAction.key = GameController::LeftKey();
    leftKeyAction.action = [this](uint32_t dt, InputState state)
    {
        if(GameController::IsPressed(state))
        {
            mPaddle.SetMovementDirection(PaddleDirection::LEFT);
        }
        else
        {
            mPaddle.SetMovementDirection(PaddleDirection::NONE);
        }
    };
    
    controller.AddInputActionForKey(leftKeyAction);
    
    ButtonAction rightKeyAction;
    
    rightKeyAction.key = GameController::RightKey();
    rightKeyAction.action = [this](uint32_t dt, InputState state)
    {
        if(GameController::IsPressed(state))
        {
            mPaddle.SetMovementDirection(PaddleDirection::RIGHT);
        }
        else
        {
            mPaddle.SetMovementDirection(PaddleDirection::NONE);
        }
    };
    
    controller.AddInputActionForKey(rightKeyAction);
}

void BreakOut::Update(uint32_t dt)
{
    mPaddle.Update(dt);
}

void BreakOut::Draw(Screen& screen)
{
    mPaddle.Draw(screen);
}

std::string BreakOut::GetName() const
{
    return "Break Out!";
}

void BreakOut::ResetGame()
{
    AARectangle paddleRect = {Vec2D(App::Singleton().Width()/2 - Paddle::PADDLE_WIDTH/2, App::Singleton().Height() - 3*Paddle::PADDLE_HEIGHT), Paddle::PADDLE_WIDTH, Paddle::PADDLE_HEIGHT};
    AARectangle levelBoundary = {Vec2D::Zero, App::Singleton().Width(), App::Singleton().Height()};
    
    mPaddle.Init(paddleRect, levelBoundary);
}
