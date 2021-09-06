//
//  BitmapFont.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 9/6/21.
//

#ifndef BitmapFont_hpp
#define BitmapFont_hpp

#include <stdint.h>

#include "SpriteSheet.hpp"
#include "Utils.hpp"

class Vec2D;
class AARectangle;

enum BitmapFontXAlignment
{
    BFXA_LEFT = 0,
    BFXA_CENTER,
    BFXA_RIGHT
};

enum BitmapFontYAlignment
{
    BFYA_TOP = 0,
    BFYA_CENTER,
    BFYA_BOTTOM
};

class BitmapFont
{
public:
    
    BitmapFont() {}
    
    bool Load(const std::string& name);
    
    Size GetSizeOf(const std::string& str) const;
    
    Vec2D GetDrawPosition(const std::string& str, const AARectangle& box, BitmapFontXAlignment xAlign = BFXA_LEFT, BitmapFontYAlignment yAlign = BFYA_TOP) const;
    
    inline const SpriteSheet& GetSpriteSheet() const {return mFontSheet;}
    inline const uint32_t GetFontSpacingBetweenLetters() const {return 2;}
    inline const uint32_t GetFontSpacingBetweenWords() const {return 5;}
    
private:
    
    SpriteSheet mFontSheet;
};

#endif /* BitmapFont_hpp */
