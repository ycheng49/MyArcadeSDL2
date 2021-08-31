//
//  Excluder.hpp
//  MyArcadeSDL2
//
//  Created by Yijie Cheng on 8/30/21.
//

#ifndef Excluder_hpp
#define Excluder_hpp

#include "AARectangle.hpp"
#include "BoundaryEdge.hpp"

class Excluder
{
public:
    
    virtual ~Excluder() {}
    
    void Init(const AARectangle& rect, bool reverseNormals = false);
    
    bool HasCollided(const AARectangle& rect, BoundaryEdge& edge) const;
    
    Vec2D GetCollisionOffset(const AARectangle& rect) const;
    
    inline const AARectangle& GetAARectangle() const {return mAARect;}
    
    void MoveBy(const Vec2D& delta);
    void MoveTo(const Vec2D& point);
    
    const BoundaryEdge& GetEdge(EdgeType edge) const;
    
private:
    
    void SetupEdges();
    
    AARectangle mAARect;
    
    BoundaryEdge mEdges[NUM_EDGES];
    
    bool mReverseNormals;
};

#endif /* Excluder_hpp */
