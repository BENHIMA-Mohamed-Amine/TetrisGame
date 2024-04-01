#include <iostream>
#include "ShapeList.hpp"
#include "utils/CircularLL.hpp"
#include "ShapeObject.hpp"
#include <vector>


template <typename T>
ShapeList<T>::ShapeList() {
    score = 0;

    // Generating 6 Random Objects
    do {
        clear();

        list.addRight(Object::random());
        list.addRight(Object::random());
        list.addRight(Object::random());
        list.addRight(Object::random());
        list.addRight(Object::random());
        list.addRight(Object::random());

    } while(getSize()!=6);

}

template <typename T>
CircularLinkedList<Object>* ShapeList<T>::exportColor(COLOR color) {
    Node<Object>* temp = list.head;
    CircularLinkedList<Object>* result = new CircularLinkedList<Object>();

    int ctr=0;

    do {
        if ((temp->data)->getColor() == color) {
            result->addRight(temp->data);
            ctr++;
        }
        temp = temp->next;
    } while (temp != list.head);

    if(!ctr) return nullptr;
    return result;
}

template <typename T>
CircularLinkedList<Object>* ShapeList<T>::exportShape(SHAPE shape) {
    Node<Object>* temp = list.head;
    CircularLinkedList<Object>* result = new CircularLinkedList<Object>();
    int ctr=0;

    do {
        if ((temp->data)->getShape() == shape) {
            result->addRight(temp->data);
            ctr++;
        }
        temp = temp->next;
    } while (temp != list.head);

    if(!ctr) return nullptr;
    return result;
}

template <typename T>
void ShapeList<T>::checkIdenticalShapesMiddle() {

    // Add Bonus to score when 3 objects with the same shape, 3 objects with the same color are next to each other
    Node<Object>* temp = list.head;

    do {
        Node<Object>* obj1 = temp;
        Node<Object>* obj2 = temp->next;
        Node<Object>* obj3 = temp->next->next;

        if((obj1->data->getColor() == obj2->data->getColor() && obj2->data->getColor() == obj3->data->getColor()) || 
            (obj1->data->getShape() == obj2->data->getShape() && obj2->data->getShape() == obj3->data->getShape()))
        {
            if(getSize()==3)
            {
                // Remove Duplicates
                list.removeNode(obj1);
                list.removeNode(obj2);
                list.removeNode(obj3);

                list.addRight(Object::random());
            } else {
                // Remove Duplicates
                list.removeNode(obj1);
                list.removeNode(obj2);
                list.removeNode(obj3);
            }

            // Increment Score
            score++;

            break;
        }
        
        temp = temp->next;

    } while(temp->next->next->next != list.head);
}

template <typename T>
void ShapeList<T>::checkIdenticalShapesLeft() {

    Node<Object>* temp = list.head;

    Node<Object>* obj1 = temp;
    Node<Object>* obj2 = temp->next;
    Node<Object>* obj3 = temp->next->next;

    if((obj1->data->getColor() == obj2->data->getColor() && obj2->data->getColor() == obj3->data->getColor()) || 
        (obj1->data->getShape() == obj2->data->getShape() && obj2->data->getShape() == obj3->data->getShape()))
    {
        if(getSize()==3)
        {
            // Remove Duplicates
            list.removeNode(obj1);
            list.removeNode(obj2);
            list.removeNode(obj3);

            list.addRight(Object::random());
        } else {
            // Remove Duplicates
            list.removeNode(obj1);
            list.removeNode(obj2);
            list.removeNode(obj3);
        }


        // Increment Score
        score++;

    }
    
    temp = temp->next;

}

template <typename T>
void ShapeList<T>::checkIdenticalShapesRight() {
    if(getSize()<3) return; // Nothing to check

    Node<Object>* temp = list.head->prev->prev->prev;

    Node<Object>* obj1 = temp;
    Node<Object>* obj2 = temp->next;
    Node<Object>* obj3 = temp->next->next;

    if((obj1->data->getColor() == obj2->data->getColor() && obj2->data->getColor() == obj3->data->getColor()) || 
        (obj1->data->getShape() == obj2->data->getShape() && obj2->data->getShape() == obj3->data->getShape()))
    {
        if(getSize()==3)
        {
            // Remove Duplicates
            list.removeNode(obj1);
            list.removeNode(obj2);
            list.removeNode(obj3);

            list.addRight(Object::random());
        } else {
            // Remove Duplicates
            list.removeNode(obj1);
            list.removeNode(obj2);
            list.removeNode(obj3);
        }

        // Increment Score
        score++;

    }
    
    temp = temp->next;

}

template <typename T>
void ShapeList<T>::addLeft(Object* obj) {
    list.addLeft(obj);
    checkIdenticalShapesLeft();
}

template <typename T>
void ShapeList<T>::addRight(Object* obj) {
    list.addRight(obj);
    checkIdenticalShapesRight();
}

template <typename T>
void ShapeList<T>::removeLeft() {
    list.removeLeft();
}

template <typename T>
void ShapeList<T>::removeRight() {
    list.removeRight();
}

template <typename T>
void ShapeList<T>::display() {
    std::cout << "List: ";
    list.display();
    std::cout << std::endl << "Score: " << score;
}

template <typename T>
void ShapeList<T>::shiftColor(COLOR targetColor) {
    CircularLinkedList<Object> *ShapeList = exportColor(targetColor);

    if(ShapeList == nullptr) {
        return;
    }

    Node<Object>* temp = ShapeList->head;
    SHAPE prevShape = temp->prev->data->getShape();
    SHAPE currShape;
    do {
        currShape = temp->data->getShape();
        temp->data->setShape(prevShape);
        prevShape = currShape;
        temp = temp->next;
    } while(temp != ShapeList->head);

    checkIdenticalShapesMiddle();
}

template <typename T>
void ShapeList<T>::shiftShape(SHAPE targetShape) {
    CircularLinkedList<Object> *ShapeList = exportShape(targetShape);

    if(ShapeList == nullptr) {
        return;
    }

    Node<Object>* temp = ShapeList->head;
    COLOR prevShape = temp->prev->data->getColor();
    COLOR currShape;
    do {
        currShape = temp->data->getColor();
        temp->data->setColor(prevShape);
        prevShape = currShape;
        temp = temp->next;
    } while(temp != ShapeList->head);

    checkIdenticalShapesMiddle();
}

template <typename T>
std::vector<Object> ShapeList<T>::getArray() {
    std::vector<Object> objList;
    Node<Object>* temp = list.head;
    do {
        objList.push_back(*(temp->data));
        temp = temp->next;
    } while(temp!=list.head);

    return objList;
}

template <typename T>
int ShapeList<T>::getSize() {
    int count = 0;
    Node<Object>* temp = list.head;
    do {
        count++;
        temp = temp->next;
    } while(temp!=list.head);

    return count;
}

template <typename T>
void ShapeList<T>::clear() {
    Node<Object>* temp = list.head;
    do {
        list.removeRight();
    } while (temp!=nullptr);
    
}

// Explicit instantiation for ShapeList<Object>
template class ShapeList<Object>;
