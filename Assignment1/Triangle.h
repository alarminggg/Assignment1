#ifndef  Triangle_h
#define Triangle_h

#include "Shape.h"
#include "MoveShape.h"

class Triangle : public Shape {
public:
	Triangle(int s);
	void draw() const override;
	virtual std::string shapeData() const override;
private:
	int TriangleSize;
};


#endif // ! Triangle_h



