//
//  Shape.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/26/21.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <vector>

#include "Vec2D.hpp"

// this is an interface class (has pure virtual function)
class Shape
{
public:
    
    virtual Vec2D GetCenterPoint() const = 0;
    
    virtual ~Shape() {}
    
    inline virtual std::vector<Vec2D> GetPoints() const {return mPoints;}
    
    void MoveBy(const Vec2D& deltaOffset);
    
protected:
    
    std::vector<Vec2D> mPoints;
};

#endif /* Shape_hpp */
