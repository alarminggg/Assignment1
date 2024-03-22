#include "Shape.h"

void Shape::move(int offsetX, int offsetY) {
	xPos += offsetX;
	yPos += offsetY;
}

void Shape::changeCoordinates(int x, int y)
{
	xPos = x;
	yPos = y;
}