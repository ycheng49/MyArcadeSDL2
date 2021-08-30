//
//  GameScene.cpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/29/21.
//

#include "GameScene.hpp"

GameScene::GameScene(std::unique_ptr<Game> optrGame): mGame(std::move(optrGame))
{
    
}

void GameScene::Init()
{
    mGame->Init(mGameController);
}

void GameScene::Update(uint32_t dt)
{
    mGame->Update(dt);
}

void GameScene::Draw(Screen& screen)
{
    mGame->Draw(screen);
}

const std::string& GameScene::GetSceneName() const
{
    static std::string name = "";
    
    return name;
}
