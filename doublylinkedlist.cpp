#include "doublylinkedlist.h"

template <typename T>
doublyLinkedList<T>::doublyLinkedList()
{

}

template <typename T>
doublyLinkedList<T>::~doublyLinkedList()
{

}

template <typename T>
void doublyLinkedList<T>::insertDistanceNodeFirst(QString startingCollege, std::vector<QString> endingCollege, std::vector<unsigned int> distance)
{
    distanceNode *temp = new distanceNode;

    if (distanceHead != nullptr)
    {
        temp->next = distanceHead;
        temp->startingCollege = startingCollege;
        temp->endingCollege = endingCollege;
        temp->distance = distance;
        temp->prev = nullptr;
        distanceHead->prev = temp;
        distanceHead = temp;
    }

    // If there is nothing inside linked list
    else if (distanceHead == nullptr)
    {
        distanceHead = temp;
        temp->prev = nullptr;
        temp->startingCollege = startingCollege;
        temp->endingCollege = endingCollege;
        temp->distance = distance;
        temp->next = nullptr;
        distanceTail = temp;
    }
}

template <typename T>
void doublyLinkedList<T>::deleteDistanceNodeFirst()
{

}

template <typename T>
void doublyLinkedList<T>::insertSouvenirNodeFirst(QString collegeName, std::vector<QString> souvenirs, std::vector<double> souvenirPricing)
{
    souvenirNode *temp = new souvenirNode;

    if (souvenirHead != nullptr)
    {
        temp->next = distanceHead;
        temp->collegeName = collegeName;
        temp->souvenirs = souvenirs;
        temp->souvenirPricing = souvenirPricing;
        temp->prev = nullptr;
        souvenirHead->prev = temp;
        souvenirHead = temp;
    }

    // If there is nothing inside linked list
    else if (souvenirHead == nullptr)
    {
        distanceHead = temp;
        temp->prev = nullptr;
        temp->collegeName = collegeName;
        temp->souvenirs = souvenirs;
        temp->souvenirPricing = souvenirPricing;
        temp->next = nullptr;
        souvenirTail = temp;
    }
}

template <typename T>
void doublyLinkedList<T>::deleteSouvenirNodeFirst()
{

}

template <typename T>
void doublyLinkedList<T>::insertDistanceNodeLast(QString startingCollege, std::vector<QString> endingCollege, std::vector<unsigned int> distance)
{
    distanceNode *temp = new distanceNode;
}

template <typename T>
void doublyLinkedList<T>::deleteDistanceNodeLast()
{

}

template <typename T>
void doublyLinkedList<T>::insertSouvenirNodeLast(QString collegeName, std::vector<QString> souvenirs, std::vector<double> souvenirPricing)
{

}

template <typename T>
void doublyLinkedList<T>::deleteSouvenirNodeLast()
{

}

template <typename T>
void doublyLinkedList<T>::printDistanceNode()
{

}

template <typename T>
void doublyLinkedList<T>::printSouvenirNode()
{

}

