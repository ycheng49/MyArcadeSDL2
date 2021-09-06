//
//  ArcadeScene.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/29/21.
//

#ifndef ArcadeScene_hpp
#define ArcadeScene_hpp

#include <memory>

#include "Scene.hpp"

enum eGame
{
    TETRIS = 0,
    BREAK_OUT,
    ASTEROIDS,
    PACMAN,
    NUM_GAMES
};

class Screen;

class ArcadeScene : public Scene
{
public:
    
    ArcadeScene();
    
    virtual void Init() override;
    virtual void Update(uint32_t dt) override;
    virtual void Draw(Screen& theScreen) override;
    virtual const std::string& GetSceneName() const override;
    
private:
    
    std::unique_ptr<Scene> GetScene(eGame game);
};

#endif /* ArcadeScene_hpp */
