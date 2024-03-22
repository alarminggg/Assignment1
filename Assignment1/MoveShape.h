#ifndef MoveShape_h
#define MoveShape_h

#include "Shape.h"

class MoveShape
{
public:
    static void ShapePositionChange(Shape* shape, int offsetX, int offsetY) {
        shape->move(offsetX, offsetY);
    }
};

#endif // !MoveShape_h


