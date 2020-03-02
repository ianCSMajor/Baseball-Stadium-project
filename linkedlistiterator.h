#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H

#include "header.h"

template <typename T>
struct node
{
    T info;
    node<T> *next, *link;
};

template <typename T>
class linkedListIterator
{
private:
    node<T> *current;

public:
    linkedListIterator();
    linkedListIterator(node<T> *ptr);
    ~linkedListIterator();

    bool operator==(const linkedListIterator<T> &right) const;
    bool operator!=(const linkedListIterator<T> &right) const;

    linkedListIterator<T> operator++();
    T& operator*();
};

#endif // LINKEDLISTITERATOR_H
