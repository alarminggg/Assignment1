#include "Triangle.h"
#include <iostream>

Triangle::Triangle(int s) : TriangleSize(s) {}

void Triangle::draw() const {
    for (int i = 1; i <= TriangleSize; ++i) {
        int NumBlanks = TriangleSize - i;
        for (int j = 0; j < NumBlanks; ++j) {
            std::cout << " ";
        }
        for (int k = 0; k < i; ++k) {
            std::cout << "* ";
        }

        std::cout << "\n";
    }
}

std::string Triangle::shapeData() const {
    // Return triangle data as a string (e.g., size and position)
    return "Triangle(Size: " + std::to_string(TriangleSize) + ", Position: (" + std::to_string(xPos) + ", " + std::to_string(yPos) + ")";
}
