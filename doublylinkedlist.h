#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "header.h"

struct distanceNode
{
    QString startingCollege;
    std::vector<QString> endingCollege; // These should be parallel vectors
    std::vector<unsigned int> distance; // unsigned because distance cannot be negative
    distanceNode *next, *prev;
};

struct souvenirNode
{
    QString collegeName;
    std::vector<QString> souvenirs; // Should also be parallel vectors, both should be the same size;
    std::vector<double> souvenirPricing;
    souvenirNode *next, *prev;
};

template <typename T>
class doublyLinkedList
{
private:
    distanceNode *distanceHead, *distanceTail;
    souvenirNode *souvenirHead, *souvenirTail;

public:
    doublyLinkedList();
    ~doublyLinkedList();

    // Insert Distance && Delete First
    void insertDistanceNodeFirst(QString startingCollege, std::vector<QString> endingCollege, std::vector<unsigned int> distance);
    void deleteDistanceNodeFirst();

    // Insert Souvenir && Delete First
    void insertSouvenirNodeFirst(QString collegeName, std::vector<QString> souvenirs, std::vector<double> souvenirPricing);
    void deleteSouvenirNodeFirst();

    // Insert Distance && Delete Last
    void insertDistanceNodeLast(QString startingCollege, std::vector<QString> endingCollege, std::vector<unsigned int> distance);
    void deleteDistanceNodeLast();

    // Insert Souvenir && Delete Last
    void insertSouvenirNodeLast(QString collegeName, std::vector<QString> souvenirs, std::vector<double> souvenirPricing);
    void deleteSouvenirNodeLast();

    void printDistanceNode();
    void printSouvenirNode();



};

#endif // DOUBLYLINKEDLIST_H
