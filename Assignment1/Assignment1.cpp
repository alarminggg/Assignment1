#include <iostream>
#include <vector>
#include <unordered_map>
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "MoveShape.h"
#include "ShapeFile.h"

int main()
{
    std::unordered_map<int, Shape*> shapeMap;
    int nextID = 1;
    int Choice = 0;
    ShapeFile shapeFile;

    while (Choice != 5)
    {
        std::cout << "Main Menu:" << "\n"
            << "Please Input a number to choose Option:\n"
            << "[1] - Add Shape:\n"
            << "[2] - Move Shape:\n"
            << "[3] - Resize Shape:\n"
            << "[4] - View Shape:\n"
            << "[5] - Delete Shape:\n"
            << "[6] - Exit Program:\n"
            << "Enter: ";
        std::cin >> Choice;

        while (Choice > 5 || Choice < 1)
        {
            std::cout << "\nInvalid Input... \nPlease Enter\n [1] - Add Shape:\n [2] - Move Shape:\n [3] - Resize Shape:\n [4] - Delete Shape:\n [5] - Exit Program:\n Enter: ";
            std::cin >> Choice;
        }

        if (Choice == 1)
        {
            char addAnother = 'Y'; // Initialize addAnother to 'Y' to enter the loop

            while (addAnother == 'Y' || addAnother == 'y')
            {
                int ShapeChoice = 0;
                std::cout << "Please Input a number to choose a Shape:\n"
                    << "[1] - Triangle:\n"
                    << "[2] - Square:\n"
                    << "[3] - Rectangle:\n"
                    << "Enter: ";
                std::cin >> ShapeChoice;

                while (ShapeChoice > 3 || ShapeChoice < 1)
                {
                    std::cout << "\nInvalid Input... \nPlease Enter [1], [2], OR [3]: ";
                    std::cin >> ShapeChoice;
                }

                Shape* newShape = nullptr;

                if (ShapeChoice == 1)
                {
                    int size;
                    std::cout << "Enter the number Between 1 AND 20 to choose the SIZE to be printed: ";
                    std::cin >> size;

                    while (size > 20 || size < 1)
                    {
                        std::cout << "\nInvalid Input... \nPlease Enter a Number Between 1-20: ";
                        std::cin >> size;
                    }
                    newShape = new Triangle(size);
                }
                else if (ShapeChoice == 2)
                {
                    int size;
                    std::cout << "Enter the size of the square: ";
                    std::cin >> size;

                    while (size > 20 || size < 1)
                    {
                        std::cout << "\nInvalid Input... \nPlease Enter a Number Between 1-20: ";
                        std::cin >> size;
                    }
                    newShape = new Square(size);
                }
                else if (ShapeChoice == 3)
                {
                    int width, height;
                    std::cout << "Enter the WIDTH of the Rectangle to be printed: ";
                    std::cin >> width;
                    while (width > 20 || width < 1)
                    {
                        std::cout << "\nInvalid Input... \nPlease Enter a Number Between 1-20 ";
                        std::cout << "Enter the WIDTH of the Rectangle to be printed: ";
                        std::cin >> width;
                    }

                    std::cout << "\nEnter the HEIGHT of the Rectangle to be printed: ";
                    std::cin >> height;
                    while (height > 20 || height < 1)
                    {
                        std::cout << "\nInvalid Input... \nPlease Enter a Number Between 1-20 ";
                        std::cout << "\nEnter the HEIGHT of the Rectangle to be printed: ";
                        std::cin >> height;
                    }

                    newShape = new Rectangle(width, height);
                }

                std::cout << "Do you want to add another shape? (Y/N): ";
                std::cin >> addAnother;

                if (addAnother != 'Y' && addAnother != 'y') {
                    if (newShape) {
                        shapeMap[nextID++] = newShape;
                        std::cout << "Shape added with ID: " << nextID - 1 << std::endl;
                    }
                }
            }
            
        }
        else if (Choice == 2)
        {
            if (!shapeMap.empty()) {
                int shapeID;
                std::cout << "Enter the ID of the shape you want to move: ";
                std::cin >> shapeID;

                auto it = shapeMap.find(shapeID);
                if (it != shapeMap.end()) {
                    int offsetX, offsetY;
                    std::cout << "Enter the horizontal offset: ";
                    std::cin >> offsetX;
                    std::cout << "Enter the vertical offset: ";
                    std::cin >> offsetY;

                    MoveShape::ShapePositionChange(it->second, offsetX, offsetY);
                }
                else {
                    std::cout << "Shape with ID " << shapeID << " not found.\n";
                }
            }
        }
        else if (Choice == 3)
        {
            // Resize Shape functionality
        }
        else if (Choice == 4)
        {
            // Delete Shape functionality
        }
        else if (Choice == 5)
        {
            std::cout << "Exiting program...\n";
        }

        // Display all shapes
        for (const auto& pair : shapeMap) {
            pair.second->draw();
        }
    }

    // Cleanup
    for (auto& pair : shapeMap) {
        delete pair.second;
    }

    return 0;
}
