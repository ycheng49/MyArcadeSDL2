//
//  Game.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/29/21.
//

#ifndef Game_hpp
#define Game_hpp

#include <string>
#include <stdint.h>

class GameController;
class Screen;

class Game
{
public:
    
    virtual ~Game() {}
    virtual void Init(GameController& controller) = 0;
    virtual void Update(uint32_t dt) = 0;
    virtual void Draw(Screen& screen) = 0;
    virtual const std::string& GetName() const = 0;
};

#endif /* Game_hpp */
