//
//  Triangle.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/26/21.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include "Shape.hpp"

class Triangle : public Shape
{
public:
    
    Triangle();
    Triangle(const Vec2D& p0, const Vec2D& p1, const Vec2D& p2);
    
    inline void SetP0(const Vec2D& p0) {mPoints[0] = p0;}
    inline void SetP1(const Vec2D& p1) {mPoints[1] = p1;}
    inline void SetP2(const Vec2D& p2) {mPoints[2] = p2;}
    
    inline Vec2D GetP0() const {return mPoints[0];}
    inline Vec2D GetP1() const {return mPoints[1];}
    inline Vec2D GetP2() const {return mPoints[2];}
    
    virtual Vec2D GetCenterPoint() const override;
    
    float Area() const;
    
    bool ContainsPoint(const Vec2D& p) const;
    
private:
    
    float Area(const Vec2D& p0, const Vec2D& p1, const Vec2D& p2) const;
};

#endif /* Triangle_hpp */
