//
//  ArcadeScene.cpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/29/21.
//

#include <iostream>

#include "ArcadeScene.hpp"
#include "Screen.hpp"
#include "AARectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Line2D.hpp"
#include "Color.hpp"
#include "GameController.hpp"
#include "App.hpp"

ArcadeScene::ArcadeScene()
{}

void ArcadeScene::Init()
{
    mTempSS.Load("ArcadeFont");
    
    // test keyboard action button 'a'
    ButtonAction action;
    
    action.key = GameController::ActionKey();
    action.action = [](uint32_t dt, InputState state)
    {
        if(GameController::IsPressed(state))
        {
            std::cout << "Action button was pressed!" << std::endl;
        }
    };
    
    mGameController.AddInputActionForKey(action);
    
    // test mouse left button
    MouseButtonAction mouseAction;
    
    mouseAction.mouseButton = GameController::LeftMouseButton();
    mouseAction.mouseInputAction = [](InputState state, const MousePosition& position)
    {
        if(GameController::IsPressed(state))
        {
            std::cout << "Left mouse button was pressed!" << std::endl;
        }
    };
    
    mGameController.AddMouseButtonAction(mouseAction);
    
    // test mouse move position
    mGameController.SetMouseMovedAction([](const MousePosition& mousePosition)
    {
        std::cout << "Mouse position x: " << mousePosition.xPos << ", y: " << mousePosition.yPos << std::endl;
    });
}

void ArcadeScene::Update(uint32_t dt)
{}

void ArcadeScene::Draw(Screen& theScreen)
{
    theScreen.Draw(mTempSS, "9", Vec2D::Zero);
}

const std::string& ArcadeScene::GetSceneName() const
{
    static std::string sceneName = "Arcade Scene";
    return sceneName;
}

std::unique_ptr<Scene> ArcadeScene::GetScene(eGame game)
{
    switch(game)
    {
        case TETRIS:
        {
            break;
        }
            
        case BREAK_OUT:
        {
            break;
        }
            
        case ASTEROIDS:
        {
            break;
        }
            
        case PACMAN:
        {
            break;
        }
            
        default:
        {
            break;
        }
    }
    
    return nullptr;
}
