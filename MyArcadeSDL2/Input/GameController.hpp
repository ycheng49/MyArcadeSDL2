//
//  GameController.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/29/21.
//

#ifndef GameController_hpp
#define GameController_hpp

#include <vector>

#include "InputAction.hpp"

class GameController
{
public:
    
    GameController();
    
    InputAction GetActionForKey(InputKey key);
    
    void AddInputActionForKey(const ButtonAction& buttonAction);
    
    void ClearAll();
    
    static bool IsPressed(InputState state);
    static bool IsReleased(InputState state);
    static InputKey ActionKey();
    static InputKey CancelKey();
    static InputKey LeftKey();
    static InputKey RightKey();
    static InputKey UpKey();
    static InputKey DownKey();
    
private:
    
    std::vector<ButtonAction> mButtonActions;
};

#endif /* GameController_hpp */
