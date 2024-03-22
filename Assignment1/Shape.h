#ifndef Shape_h
#define Shape_h

#include <string> 
class Shape
{
public:
    Shape(int x = 0, int y = 0) : xPos(x), yPos(y) {} 
    virtual ~Shape() {}

    virtual void draw() const = 0;
    virtual std::string shapeData() const = 0;
    virtual void move(int offsetX, int offsetY);
    void changeCoordinates(int x, int y);

protected:
    int xPos;
    int yPos;
};

#endif // !Shape_h