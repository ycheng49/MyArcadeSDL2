//
//  LevelBoundary.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/31/21.
//

#ifndef LevelBoundary_hpp
#define LevelBoundary_hpp

#include "Excluder.hpp"

class AARectangle;
class Ball;

class LevelBoundary
{
public:
    
    LevelBoundary() {};
    
    LevelBoundary(const AARectangle& boundary);
    
    bool HasCollided(const Ball& ball, BoundaryEdge& edge);
                                            // find out what the edge was
    
    inline const AARectangle& GetAARectangle() const {return mIncluder.GetAARectangle();}
    
private:
    
    bool HasCollidedWithEdge(const Ball& ball, const BoundaryEdge& edge) const;
                                            // check to see if we collided at all
    Excluder mIncluder;
};

#endif /* LevelBoundary_hpp */
