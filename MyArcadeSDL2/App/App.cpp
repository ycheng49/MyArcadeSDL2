//
//  App.cpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/28/21.
//

#include <SDL2/SDL.h>
#include <iostream>
#include <cassert>

#include "App.hpp"
#include "ArcadeScene.hpp"
#include "GameScene.hpp"
#include "BreakOut.hpp"

App& App::Singleton()
{
    static App theApp;
    return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
    mnoptrWindow = mScreen.Init(width, height, mag);
    
    std::unique_ptr<ArcadeScene> arcadeScene = std::make_unique<ArcadeScene>();
    
    PushScene(std::move(arcadeScene));
    
    // Temporary
    /*{
        std::unique_ptr<BreakOut> breakoutGame = std::make_unique<BreakOut>();
        
        std::unique_ptr<GameScene> breakoutScene = std::make_unique<GameScene>(std::move(breakoutGame));
        
        PushScene(std::move(breakoutScene));
    }*/
    
    return mnoptrWindow != nullptr;
}

void App::Run()
{
    if(mnoptrWindow)
    {
        bool running = true;
        
        uint32_t lastTick = SDL_GetTicks();
        uint32_t currentTick = lastTick;
        
        uint32_t dt = 10;       // in miliseconds
        uint32_t accumulator = 0;
        
        mInputController.Init([&running](uint32_t dt, InputState state)
        {
            running = false;
        });
                
        while(running)
        {
            currentTick = SDL_GetTicks();
            
            uint32_t frameTime = currentTick - lastTick;
            
            if(frameTime > 300)         // in miliseconds
            {
                frameTime = 300;
            }
            
            lastTick = currentTick;
            
            accumulator += frameTime;
            
            // input
            mInputController.Update(dt);
            
            Scene* topScene = App::TopScene();
            
            assert(topScene && "Why don't have a scene?");
            
            if(topScene)
            {
                // update
                while(accumulator >= dt)
                {
                    // update current scene by dt
                    topScene->Update(dt);
                                        
                    accumulator -= dt;
                }
                
                // render
                topScene->Draw(mScreen);
            }
            
            mScreen.SwapScreens();
        }
    }
}

void App::PushScene(std::unique_ptr<Scene> scene)
{
    assert(scene && "Don't push nullptr");
    
    if(scene)
    {
        scene->Init();
        
        mInputController.SetGameController(scene->GetGameController());
        
        mSceneStack.emplace_back(std::move(scene));
        
        SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());
    }
}

void App::PopScene()
{
    if(mSceneStack.size() > 1)
    {
        mSceneStack.pop_back();
    }
    
    if(TopScene())
    {
        mInputController.SetGameController(TopScene()->GetGameController());

        SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());
    }
}

Scene* App::TopScene()
{
    if(mSceneStack.empty())
    {
        return nullptr;
    }
    
    return mSceneStack.back().get();
}

const std::string& App::GetBasePath()
{
    static std::string basePath = SDL_GetBasePath();
    
    // std::cout << "The base path is: " << basePath << std::endl;
    
    return basePath;
}
