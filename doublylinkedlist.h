#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "header.h"
#include "linkedlistiterator.h"

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
    std::vector<QString> souvenirName; // Should also be parallel vectors, both should be the same size;
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

    // <Insert> Distance && Souvenir <First>
    void insertDistanceNodeFirst(QString startingCollege, std::vector<QString> endingCollege, std::vector<unsigned int> distance);
    void insertSouvenirNodeFirst(QString collegeName, std::vector<QString> souvenirName, std::vector<double> souvenirPricing);

    // <Delete> Distance && Souvenir <First>
    void deleteDistanceNodeFirst();
    void deleteSouvenirNodeFirst();

    // <Insert> Distance && Souvenir <Last>
    void insertDistanceNodeLast(QString startingCollege, std::vector<QString> endingCollege, std::vector<unsigned int> distance);
    void insertSouvenirNodeLast(QString collegeName, std::vector<QString> souvenirName, std::vector<double> souvenirPricing);

    // <Delete> Distance && Souvenir <Last>
    void deleteDistanceNodeLast();
    void deleteSouvenirNodeLast();

    // <Print> Distance && Souvenir
    void printDistanceNode();
    void printSouvenirNode();

    // <Getters> Distance && Souvenir <Head>
    doublyLinkedList<T> *getDistanceHead();
    doublyLinkedList<T> *getSouvenirHead();

    // <Getters> Distance && Souvenir <Tail>
    doublyLinkedList<T> *getDistanceTail();
    doublyLinkedList<T> *getSouvenirTail();

    // Created an Iterator for Doubly Linked List
    linkedListIterator<T> begin(T tempNode);
    linkedListIterator<T> end(T tempNode);
};

#endif // DOUBLYLINKEDLIST_H
