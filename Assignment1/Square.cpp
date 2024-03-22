#include "Square.h"
#include <iostream>

Square::Square(int SquareSize) : size(SquareSize) {}

void Square::draw() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}

std::string Square::shapeData() const {
    return "Square(Size: " + std::to_string(SquareSize) + ", Position: (" + std::to_string(xPos) + ", " + std::to_string(yPos) + ")";
}