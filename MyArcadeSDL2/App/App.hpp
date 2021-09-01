//
//  App.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/28/21.
//

#ifndef App_hpp
#define App_hpp

#include <stdint.h>
#include <vector>
#include <memory>

#include "Screen.hpp"
#include "Scene.hpp"
#include "InputController.hpp"

struct SDL_Window;

class App
{
public:
    
    static App& Singleton();
    
    bool Init(uint32_t width, uint32_t height, uint32_t mag);
    
    void Run();
    
    inline uint32_t Width() const {return mScreen.Width();}
    inline uint32_t Height() const {return mScreen.Height();}
    
    void PushScene(std::unique_ptr<Scene> scene);
    void PopScene();
    Scene* TopScene();      // current scene
    
    static const std::string& GetBasePath();
    
private:
    
    Screen mScreen;
    SDL_Window* mnoptrWindow;
    
    std::vector<std::unique_ptr<Scene>> mSceneStack;
    InputController mInputController;
};

#endif /* App_hpp */
