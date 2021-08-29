//
//  InputAction.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/29/21.
//

#ifndef InputAction_hpp
#define InputAction_hpp

#include <functional>
#include <stdint.h>

using InputKey = uint8_t;
using InputState = uint8_t;
using InputAction = std::function<void(uint32_t dt, InputState)>;

struct ButtonAction
{
    InputKey key;
    InputAction action;
};

#endif /* InputAction_hpp */
