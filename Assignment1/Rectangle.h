#ifndef Rectangle_h
#define Rectangle_h

#include "Shape.h"
#include "MoveShape.h"

class Rectangle : public Shape {
private:
    int RectangleWidth;
    int RectangleHeight;
public:
    Rectangle(int width, int height);
    void draw() const override;
    virtual std::string shapeData() const override;
};

#endif // Rectangle_h