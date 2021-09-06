//
//  BMPImage.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 9/6/21.
//

#ifndef BMPImage_hpp
#define BMPImage_hpp

#include <vector>
#include <string>
#include <stdint.h>

#include "Color.hpp"

class BMPImage
{
public:
    
    BMPImage();
    
    bool Load(const std::string& path);
    
    inline const std::vector<Color>& GetPixels() const {return mPixels;}
    inline uint32_t GetWidth() const {return mWidth;}
    inline uint32_t GetHeight() const {return mHeight;}
    
private:
    
    std::vector<Color> mPixels;
    uint32_t mWidth;
    uint32_t mHeight;
};

#endif /* BMPImage_hpp */
