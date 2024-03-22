#ifndef ShapeFile_h
#define ShapeFile_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class ShapeFile {
public:
    void saveShapeToFile(int shapeID, const std::string& shapeData);
    std::string loadShapeFromFile(int shapeID);
};

#endif /* ShapeFile_h */
