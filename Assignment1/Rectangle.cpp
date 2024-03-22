#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(int width, int height) : RectangleWidth(width), RectangleHeight(height) {}

void Rectangle::draw() const{
    for (int i = 0; i < RectangleHeight; ++i) {
        for (int j = 0; j < RectangleWidth; ++j) {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}