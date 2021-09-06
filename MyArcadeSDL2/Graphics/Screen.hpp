//
//  Screen.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/26/21.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdint.h>
#include <vector>

#include "ScreenBuffer.hpp"
#include "Color.hpp"

class Vec2D;
class Line2D;
class Triangle;
class AARectangle;
class Circle;
class BMPImage;
class SpriteSheet;
class BitmapFont;

struct SDL_Window;
struct SDL_Surface;
struct Sprite;

class Screen
{
public:
    
    Screen();
    ~Screen();
    
    SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag);
    void SwapScreens();
    
    inline void SetClearColor(const Color& clearColor) {mClearColor = clearColor;}
    inline uint32_t Width() const {return mWidth;}
    inline uint32_t Height() const {return mHeight;}
    
    // Draw Methods go here (Bresenham's line algorithm)
    void Draw(int x, int y, const Color& color);
    void Draw(const Vec2D& point, const Color& color);
    void Draw(const Line2D& line, const Color& color);
    void Draw(const Triangle& triangle, const Color& color, bool fill = false, const Color& fillColor = Color::White());
    void Draw(const AARectangle& rect, const Color& color, bool fill = false, const Color& fillColor = Color::White());
    void Draw(const Circle& circle, const Color& color, bool fill = false, const Color& fillColor = Color::White());
    void Draw(const BMPImage& image, const Sprite& sprite, const Vec2D& pos);
    void Draw(const SpriteSheet& ss, const std::string& spriteName, const Vec2D& pos);
    void Draw(const BitmapFont& font, const std::string& textLine, const Vec2D& pos);
    
private:
    
    Screen(const Screen& screen);
    Screen& operator=(const Screen& screen);
    
    void ClearScreen();
    void FillPoly(const std::vector<Vec2D>& points, const Color& color);
    
    uint32_t mWidth;
    uint32_t mHeight;
    
    Color mClearColor;
    ScreenBuffer mBackBuffer;
    
    SDL_Window* moptrWindow;
    SDL_Surface* mnoptrWindowSurface;
};

#endif /* Screen_hpp */
