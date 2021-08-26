//
//  Line2D.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/26/21.
//

#ifndef Line2D_hpp
#define Line2D_hpp

#include "Vec2D.hpp"

class Line2D
{
public:
    
    Line2D();
    Line2D(float x0, float y0, float x1, float y1);
    Line2D(const Vec2D& p0, const Vec2D& p1);
    
    inline const Vec2D& GetP0() const {return mP0;}
    inline const Vec2D& GetP1() const {return mP1;}
    
    inline void SetP0(const Vec2D& p0) {mP0 = p0;}
    inline void SetP1(const Vec2D& p1) {mP1 = p1;}
    
    bool operator==(const Line2D& line) const;
    
    float Slope() const;
    float MinDistanceFrom(const Vec2D& p, bool limitToSegment = false) const;
    float Length() const;
    
    Vec2D Midpoint() const;
    Vec2D ClosestPoint(const Vec2D& p, bool limitToSegment = false) const;
    
private:
    
    Vec2D mP0;
    Vec2D mP1;
};

#endif /* Line2D_hpp */
