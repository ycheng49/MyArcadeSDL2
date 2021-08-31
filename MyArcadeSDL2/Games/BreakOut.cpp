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

void BreakOut::Init(GameController& controller)
{
    std::cout << "Break Out Game Init()" << std::endl;
}

void BreakOut::Update(uint32_t dt)
{
    std::cout << "Break Out Game Update" << std::endl;
}

void BreakOut::Draw(Screen& screen)
{
    std::cout << "Break Out Game Draw" << std::endl;
}

std::string BreakOut::GetName() const
{
    return "Break Out!";
}
