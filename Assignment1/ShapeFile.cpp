#include "ShapeFile.h"

void ShapeFile::saveShapeToFile(int shapeID, const std::string& shapeData) {
    std::ofstream outFile(std::to_string(shapeID) + ".txt");
    if (outFile.is_open()) {
        outFile << shapeData;
        outFile.close();
        std::cout << "Shape with ID " << shapeID << " saved to file.\n";
    }
    else {
        std::cerr << "Error: Unable to open file for writing.\n";
    }
}

std::string ShapeFile::loadShapeFromFile(int shapeID) {
    std::ifstream inFile(std::to_string(shapeID) + ".txt");
    std::stringstream buffer;
    if (inFile.is_open()) {
        buffer << inFile.rdbuf();
        inFile.close();
        std::cout << "Shape with ID " << shapeID << " loaded from file.\n";
        return buffer.str();
    }
    else {
        std::cerr << "Error: Unable to open file for reading.\n";
        return "";
    }
}