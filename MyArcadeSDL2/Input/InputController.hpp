//
//  InputController.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/29/21.
//

#ifndef InputController_hpp
#define InputController_hpp

#include "InputAction.hpp"

struct GameController;

class InputController
{
public:
    
    InputController();
    
    void Init(InputAction quitAction);
    void Update(uint32_t dt);
    
    void SetGameController(GameController* controller);
    
private:
    
    InputAction mQuit;
    GameController* mnoptrCurrentController;
};

#endif /* InputController_hpp */
