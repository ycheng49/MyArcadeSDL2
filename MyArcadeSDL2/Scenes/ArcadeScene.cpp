//
//  ArcadeScene.cpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/29/21.
//

#include "ArcadeScene.hpp"
#include "Screen.hpp"
#include "AARectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Line2D.hpp"
#include "Color.hpp"

ArcadeScene::ArcadeScene()
{}

void ArcadeScene::Init()
{}

void ArcadeScene::Update(uint32_t dt)
{}

void ArcadeScene::Draw(Screen& theScreen)
{
    Line2D line = {Vec2D(0,0), Vec2D(theScreen.Width(), theScreen.Height())};
    Triangle triangle = {Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110)};
    AARectangle rect = {Vec2D(theScreen.Width() / 2 - 25, theScreen.Height() / 2 - 25), 50, 50};
    Circle circle = {Vec2D(theScreen.Width() / 2 + 50, theScreen.Height() / 2 + 50), 50};
    
    theScreen.Draw(line, Color::White());
    theScreen.Draw(triangle, Color::Red(), true, Color::Red());
    theScreen.Draw(rect, Color::Blue(), true, Color(0, 0, 255, 140));
    theScreen.Draw(circle, Color(0, 255, 0, 150), true, Color(0, 255, 0, 150));
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
            
        }
        break;
            
        case BREAK_OUT:
        {
            
        }
        break;
            
        case ASTEROIDS:
        {
            
        }
        break;
            
        case PACMAN:
        {
            
        }
        break;
            
        default:
        {
            
        }
        break;
    }
    
    return nullptr;
}
