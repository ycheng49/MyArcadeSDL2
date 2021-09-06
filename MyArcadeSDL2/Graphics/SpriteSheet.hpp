//
//  SpriteSheet.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 9/6/21.
//

#ifndef SpriteSheet_hpp
#define SpriteSheet_hpp

#include <string>
#include <vector>
#include <stdint.h>

#include "BMPImage.hpp"

struct Sprite
{
    uint32_t xPos = 0;
    uint32_t yPos = 0;
    uint32_t width = 0;
    uint32_t height = 0;
};

class SpriteSheet
{
public:
    
    SpriteSheet();
    
    bool Load(const std::string& name);
    
    Sprite GetSprite(const std::string& spriteName) const;
    
    std::vector<std::string> SpriteNames() const;
    
    inline const BMPImage& GetBMPImage() const {return mBMPImage;}
    inline uint32_t GetWidth() const {return mBMPImage.GetWidth();}
    inline uint32_t GetHeight() const {return mBMPImage.GetHeight();}
    
private:
    
    bool LoadSpriteSection(const std::string& path);
    
    struct BMPImageSection
    {
        std::string key = "";
        
        Sprite sprite;
    };
    
    BMPImage mBMPImage;
    
    std::vector<BMPImageSection> mSections;
};

#endif /* SpriteSheet_hpp */
