//
//  Block.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/31/21.
//

#ifndef Block_hpp
#define Block_hpp

#include "Excluder.hpp"
#include "Color.hpp"

class Ball;
class Screen;

struct BoundaryEdge;

class Block : public Excluder
{
public:
    
    static const int UNBREAKABLE = -1;
    
    Block();
    
    void Init(const AARectangle& rect, int hp, const Color& outlineColor, const Color& fillColor);
    
    void Draw(Screen& screen);
    
    void Bounce(Ball& ball, const BoundaryEdge& edge);
    
    void ReduceHP();
    
    inline int GetHP() const {return mHp;}
    inline bool IsDestroyed() const {return mHp == 0;}
    inline const Color& GetOutlineColor() const {return mOutlineColor;}
    inline const Color& GetFillColor() const {return mFillColor;}
    
private:
    
    Color mOutlineColor;
    Color mFillColor;
    
    int mHp;                    // -1 means unbreakable
};

#endif /* Block_hpp */
