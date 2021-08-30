//
//  GameScene.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/29/21.
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <memory>

#include "Scene.hpp"
#include "Game.hpp"

class GameScene : public Scene
{
public:
    
    GameScene(std::unique_ptr<Game> optrGame);
    virtual ~GameScene() {}
    
    virtual void Init() override;
    virtual void Update(uint32_t dt) override;
    virtual void Draw(Screen& screen) override;
    
    virtual const std::string& GetSceneName() const override;
    
private:
    
    std::unique_ptr<Game> mGame;
};

#endif /* GameScene_hpp */
