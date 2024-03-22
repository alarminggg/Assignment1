#ifndef Square_h
#define Square_h

#include "Shape.h"
#include "MoveShape.h"

class Square : public Shape {
private:
    int size;
public:
    Square(int s);
    void draw() const override;
    virtual std::string shapeData() const override;
};

#endif // Square_h

