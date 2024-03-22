#include "MoveShape.h"
#include <iostream>

void MoveShape(Shape* shape, int offsetX, int offsetY) {
    shape->move(offsetX, offsetY);
}