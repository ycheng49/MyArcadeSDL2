//
//  BreakOutGameLevel.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/31/21.
//

#ifndef BreakOutGameLevel_hpp
#define BreakOutGameLevel_hpp

#include <vector>
#include <stdint.h>

#include "Block.hpp"

class Screen;
class Ball;
class AARectangle;

class BreakOutGameLevel
{
public:
    
    BreakOutGameLevel();
    
    void Init(const AARectangle& boundary);
    
    void Load(const std::vector<Block>& blocks);
    
    void Update(uint32_t dt, Ball& ball);
    
    void Draw(Screen& screen);
    
private:
    
    void CreateDefaultLevel(const AARectangle& boundary);
    
    std::vector<Block>  mBlocks;
};


#endif /* BreakOutGameLevel_hpp */
