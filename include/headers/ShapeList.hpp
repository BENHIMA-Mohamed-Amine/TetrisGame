#ifndef SHAPELIST_HPP
#define SHAPELIST_HPP

#include "utils/CircularLL.hpp"
#include "ShapeObject.hpp"
#include <vector>

template <typename T>
class ShapeList
{
public:
    CircularLinkedList<Object> list;
    int score;

    ShapeList();

    CircularLinkedList<Object>* exportColor(COLOR color);
    CircularLinkedList<Object>* exportShape(SHAPE shape);

    void checkIdenticalShapesMiddle();
    void checkIdenticalShapesLeft();
    void checkIdenticalShapesRight();

    void addLeft(Object* obj);
    void addRight(Object* obj);
    void removeLeft();
    void removeRight();
    
    void display();

    void shiftColor(COLOR targetColor);
    void shiftShape(SHAPE targetShape);

    int getSize();
    void clear();
    
    std::vector<Object> getArray();
};

#endif
