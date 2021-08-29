//
//  Scene.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/29/21.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <string>
#include <stdint.h>

#include "Screen.hpp"

// this is an interface class
class Scene
{
public:
    
    virtual ~Scene() {}
    virtual void Init() = 0;
    virtual void Update(uint32_t dt) = 0;
    virtual void Draw(Screen& theScreen) = 0;
    virtual const std::string& GetSceneName() const = 0;
};

#endif /* Scene_hpp */
