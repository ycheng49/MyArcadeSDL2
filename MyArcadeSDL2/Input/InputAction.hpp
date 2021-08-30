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

struct MousePosition;

using InputKey = uint8_t;
using InputState = uint8_t;
using MouseButton = uint8_t;

using InputAction = std::function<void(uint32_t dt, InputState)>;
using MouseMovedAction = std::function<void(const MousePosition& mousePosition)>;
using MouseInputAction = std::function<void(InputState state, const MousePosition& position)>;

struct ButtonAction
{
    InputKey key;
    InputAction action;
};

struct MousePosition
{
    int32_t xPos, yPos;
};

struct MouseButtonAction
{
    MouseButton mouseButton;
    MouseInputAction mouseInputAction;
};

#endif /* InputAction_hpp */
